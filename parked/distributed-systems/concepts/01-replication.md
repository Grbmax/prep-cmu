# Distributed Systems 01 — Replication (DDIA Ch. 5)

Replication = keeping copies of the same data on multiple machines connected by a
network. You do it for three reasons: **lower latency** (put data near users),
**availability** (survive node failures), and **read throughput** (scale out reads).
The hard part is never the copying — it's what happens to the *changes*. Every model
below is just a different answer to "where can writes happen, and how do other copies
find out?"

The whole chapter lives under one unavoidable fact: replicas are connected by an
asynchronous network that can delay, reorder, drop, or partition. So you will ALWAYS
be trading consistency against availability and latency. There is no model that wins
on all three.

---

## 1. Leader–Follower (single-leader / active-passive)

- One replica is the **leader**. All writes go to it.
- Leader writes to its local storage, then ships the change to **followers** via a
  **replication log**. Followers apply changes in the same order.
- Reads can go to leader OR any follower (read scaling).

### Sync vs async replication
- **Synchronous:** leader waits for the follower to confirm before reporting success.
  Guarantees the follower has the write — but if that follower stalls, the write
  blocks. In practice you make *one* follower sync and the rest async
  (**semi-synchronous**): at least one other copy is guaranteed current.
- **Asynchronous:** leader doesn't wait. Fast and always available for writes, but if
  the leader dies before propagating, those writes are **lost**. This is the common
  default.

### Failover (when the leader dies)
1. Detect the leader is dead (usually a timeout — and timeouts can be wrong).
2. Choose a new leader (election, or a controller appoints one).
3. Reconfigure clients and followers to use it.

Failover is where the bodies are buried:
- **Lost writes:** async writes not yet replicated are gone. If the old leader rejoins,
  its extra writes often must be discarded — dangerous if other systems already acted
  on them (the GitHub MySQL/Redis incident: discarded writes left stale data in use).
- **Split brain:** two nodes both believe they're leader, both accept writes →
  divergence/corruption. You need a mechanism to force at most one leader.
- **Wrong timeout:** too short → needless failovers under load spikes; too long → long
  downtime. No right answer, only tradeoffs.

### Replication log implementations
- **Statement-based:** ship the SQL. Breaks on nondeterminism (`NOW()`, `RAND()`,
  autoincrement, triggers). Mostly abandoned.
- **Write-ahead log (WAL) shipping:** ship the low-level storage-engine log. Tightly
  couples replicas to the exact storage format/version → hard to do zero-downtime
  upgrades.
- **Logical (row-based) log:** ship logical row changes, decoupled from storage engine.
  Enables version-mixing and feeding external systems (**change data capture**).
- **Trigger-based:** application-level, flexible, higher overhead and more bug surface.

---

## 2. Replication lag and its read anomalies

With async followers, a follower can be behind the leader ("replication lag").
**Eventual consistency**: if writes stop, followers eventually converge. But "eventually"
is unbounded, and three specific anomalies bite users. Each has a named guarantee that
fixes it:

- **Read-your-own-writes** (read-after-write consistency): a user who just wrote must
  see their write, even if other users see it later. Fix: read the user's own recently
  written data from the leader, or track write timestamps.
- **Monotonic reads:** a user must not see time "go backwards" (read a value, then read
  an older value from a more-lagged follower). Fix: pin each user to one replica
  (e.g., hash of user id).
- **Consistent prefix reads:** observers must see writes in causal order — you can't
  see the answer before the question. Violated when partitions replicate independently.
  Fix: ensure causally related writes go through the same partition / are ordered.

The lesson: "eventual consistency" silently pushes these problems onto application
developers. Naming the guarantee you actually need is half the battle.

---

## 3. Multi-Leader (active-active)

Multiple leaders accept writes; each leader is a follower of the others.
Use cases: multi-datacenter operation, offline-capable clients (your phone's calendar
is a leader), real-time collaborative editing.

Upside: writes are local/low-latency and survive a datacenter outage. Downside, and
it's the whole game: **write conflicts.** The same record gets edited concurrently on
two leaders.

### Conflict resolution strategies
- **Avoid conflicts:** route all writes for a given record to the same leader. Simplest
  when it fits.
- **Last-write-wins (LWW):** pick by timestamp. Simple, but *discards data* and depends
  on clock sync — clocks lie.
- **Merge / application logic:** keep both, merge on read or write (e.g., union of
  edits, or let the user resolve).
- **CRDTs / mergeable structures:** data types designed so concurrent edits merge
  deterministically without losing intent.

Replication topologies (how leaders forward writes): **all-to-all** (robust, but
messages can arrive out of causal order → use version vectors), **circular**, **star**
(single points of failure on a node; one dead node breaks the chain).

---

## 4. Leaderless (Dynamo-style: Cassandra, Riak, Voldemort)

No leader. The client (or a coordinator) sends each write to **several** replicas and
each read to **several** replicas, in parallel.

### Quorums
With `n` replicas, require `w` to ack a write and `r` to respond to a read. If
**`w + r > n`**, the read and write sets overlap, so a read is guaranteed to touch at
least one replica that saw the latest write. Common choice: `n=3, w=2, r=2`.
- Smaller `w` → faster, more durable-loss risk. Smaller `r` → faster reads, staler data.
- `w + r > n` is necessary but not sufficient — edge cases (concurrent writes, failed
  writes that partially applied, sloppy quorums) still let you read stale data.

### Catch-up mechanisms (how stale replicas converge)
- **Read repair:** on a read, the client sees a stale replica and writes the fresh
  value back to it.
- **Anti-entropy:** a background process continuously compares and syncs replicas
  (often via Merkle trees to find differences cheaply).

### Sloppy quorums and hinted handoff
During a partition, accept writes on *any* reachable n nodes (not the "home" nodes) to
stay available; once the partition heals, **hand off** those writes to the proper home
nodes. Boosts write availability but means a read at the home nodes may miss recent
writes — `w + r > n` no longer truly guarantees overlap.

### Detecting concurrency: version vectors
"Concurrent" means neither write happened-before the other. Leaderless systems track a
**version vector** (a version number per replica) to tell whether one write supersedes
another or whether they're genuinely concurrent and must be merged (siblings). This is
the formal machinery behind "happened-before" you'll need for causality discussions.

---

## 5. The comparison you should be able to recite

| Model        | Where writes go | Conflict handling | Write availability | Typical consistency |
|--------------|-----------------|-------------------|--------------------|---------------------|
| Single-leader| one node        | none (serialized) | lost on leader fail| strong-ish, easy reasoning |
| Multi-leader | several nodes   | REQUIRED (hard)   | high, multi-DC     | eventual + conflicts |
| Leaderless   | quorum of nodes | merge/version vec | tunable via w,r    | tunable, eventual    |

---

## The mandatory question for this concept
**"What breaks if the network partitions?"** Be ready to answer it for each model:
- Single-leader: followers cut off from the leader go stale; if the *leader* is on the
  minority side or presumed dead, failover risks split brain and lost async writes.
- Multi-leader: each side keeps accepting writes (that's the point) → guaranteed
  divergence that must be reconciled on heal; LWW silently drops data.
- Leaderless: writes/reads on the minority side may not reach quorum (unavailable) or,
  with sloppy quorums, succeed against the "wrong" nodes and read stale until handoff.

That question is CAP in disguise: under partition you choose availability (keep serving,
risk staleness/divergence) or consistency (refuse to serve rather than return wrong
data). Every replication design is a stance on that choice.
