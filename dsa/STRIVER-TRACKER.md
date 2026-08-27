# Striver A2Z — Tracker

**Language:** C++17 · **Started:** 2026-08-27 · **Sheet:** ~455 problems, 18 steps

## What this sheet is and is not, for us

The A2Z sheet is a **problem inventory and an ordering spine**. It is not a course to
sit through. Gaurav does not learn from videos or reading — he learns by being handed a
problem, attempting it, and being corrected. So:

- **Videos: never.** Not the Striver ones, not anyone's. If a concept needs explaining,
  I explain it live, in text, against the specific problem in front of him.
- **Editorials: only after.** After his own solution compiles and he has stated both
  complexities from memory. Never before, never as a hint.
- **The sheet's job** is to guarantee coverage (we cannot silently skip a pattern) and
  to supply problems already sorted by difficulty inside each pattern.

### The loop, per problem

1. I hand him the problem cold. No hint, no pattern name.
2. He writes his **pattern guess** in the file header, before any code. Wrong guesses
   are the useful data — that instinct is the actual thing being trained.
3. He states the brute force in words, with its complexity.
4. He writes it. Every line is his. `make run FILE=...` — ASan on.
5. He states time and space **from memory** before checking anything.
6. Only now: I show the idiomatic/optimized version, name the pattern, and he writes
   the pattern note if it's new.
7. Tick the box here with the date. Needed a hint → no tick, it goes on the re-do list.

Timebox: 25 min stuck with zero progress → pattern name only, re-attempt. 45 min total
→ we walk it together and it's on the re-do list at +7 days.

---

## Phase 0 — C++ back into the hands (Aug 27 → ~Sep 12)

**Why this exists.** Starting at binary search — where his friends are starting — only
works if C++ is already automatic. It isn't: the error log has value-vs-index four
times, off-by-one twice in a single file, `int` vs `size_t` still not instinctive. Drop
into binary search in that state and every problem is a syntax fight with an algorithm
hidden behind it; neither gets learned.

The opposite trap is worse: six weeks of C++ tutorials "until ready," finishing in
November with zero problems solved.

**So: rebuild C++ through problems, never before them.** Each session is one language
mechanic plus, immediately, a problem that cannot be solved without it. Two weeks,
~25 problems, and then the syntax is invisible — which is the only state in which
binary search is actually about binary search.

Problems below are drawn from Striver Steps 1 and 3 (easy tier), chosen for what
language mechanic they force rather than for the algorithm.

| # | Mechanic being rebuilt | Problem that forces it | Done | Date |
|---|------------------------|------------------------|------|------|
| 0.1 | `vector<int>`, indexed for-loop, `size_t` | Largest element in an array | [x] | 2026-08-27 |
| 0.2 | Two accumulators, the "pattern twin" check | Second largest without sorting | [ ] | |
| 0.3 | Early return vs flag variable | Check if array is sorted | [ ] | |
| 0.4 | Two-index write pointer (**value-vs-index drill**) | Remove duplicates from sorted array | [ ] | |
| 0.5 | In-place swap, `std::swap`, reverse | Left-rotate array by one, then by k | [ ] | |
| 0.6 | Range-for vs indexed-for — when each is wrong | Move zeros to end | [ ] | |
| 0.7 | `unordered_map` insert/lookup, the `[]` silent-insert footgun | Frequency of each element | [ ] | |
| 0.8 | `.count()` vs `.find()`, iterator basics | First non-repeating character | [ ] | |
| 0.9 | `unordered_set`, dedup thinking | Union / intersection of two arrays | [ ] | |
| 0.10 | Running accumulator, negative-number edge cases | Maximum subarray sum (Kadane) | [ ] | |
| 0.11 | `sort` + lambda comparator | Sort by frequency, then by value | [ ] | |
| 0.12 | `pair`, `vector<pair>`, structured bindings | Merge overlapping intervals | [ ] | |
| 0.13 | `std::string` vs `char*`, `substr` | Reverse words in a string | [ ] | |
| 0.14 | Function decomposition, pass by `const&` | Rotate matrix 90° in place | [ ] | |
| 0.15 | Recap under time pressure — 3 random problems from 0.1–0.14, 20 min each, no notes | | [ ] | |

**Gate to Phase 1:** 0.15 passed, and value-vs-index has gone three consecutive
problems without appearing. If it appears, Phase 0 extends. This gate is not
negotiable — it is the whole point.

---

## Phase 1 — Interview core (Sep 12 → Oct 15)

Steps listed in **recruiting-priority order**, not sheet order. Sheet numbering kept so
you can find things on takeuforward.

| Sheet # | Step | Problems | Done | Why here |
|---------|------|----------|------|----------|
| 4 | Binary Search (1D, 2D, search space) | 32 | 0 | Highest yield per problem on the sheet. "Binary search on the answer" is the sub-pattern most candidates never recognize. |
| 3 | Arrays — medium and hard tier | ~25 remaining | 2 | Easies absorbed in Phase 0. Dutch flag, prefix sums, majority element. |
| 10 | Sliding Window & Two Pointer | 12 | 0 | Two-pointer basics already banked — see `patterns/01-two-pointers.md`. |
| 9 | Stack & Queues (incl. monotonic stack) | 30 | 0 | Monotonic stack is a top-5 interview pattern and reliably separates candidates. |
| 8 | Bit Manipulation | 18 | 0 | **Pulled forward from P3** — overlaps 15-513 Lab 1 (Data) directly. Do them the same week; free double-dip. |

**Oct 15 checkpoint:** solve a random medium from Steps 3/4/10 in 35 minutes, out loud,
in C++, without reference. That is the interview-ready bar.

## Phase 2 — Structures (Oct → Nov)

| Sheet # | Step | Problems | Done | Why here |
|---------|------|----------|------|----------|
| 6 | Linked List | 31 | 0 | Fast/slow pointers, in-place reversal. Pairs with 15-513 malloc lab pointer work. |
| 13 | Binary Trees | 38 | 0 | Do iterative traversals too — they get asked specifically to catch people who only know recursive. |
| 11 | Heaps | 17 | 0 | `priority_queue` fluency; top-K is a stock question. |
| 14 | Binary Search Trees | 16 | 0 | Short step, high payoff once trees are solid. |

## Phase 3 — The hard half (Nov → Dec)

| Sheet # | Step | Problems | Done | Why here |
|---------|------|----------|------|----------|
| 7 | Recursion (patternwise) | 25 | 0 | Subsets / permutations / backtracking. Must land **before** DP or DP won't click. |
| 16 | Graphs | 53 | 0 | BFS/DFS → topo sort → Dijkstra → union-find. Largest step; start early November. |
| 17 | Dynamic Programming | 55 | 0 | By pattern only (1D, grid, subsequence, stocks, LIS, partition) — never problem-by-problem. |
| 12 | Greedy | 15 | 0 | Mostly interval and scheduling logic. |

Most candidates are weak across Phase 3. Being solid here is the actual edge.

## Phase 4 — Completeness (Spring)

| Sheet # | Step | Problems | Done | Why here |
|---------|------|----------|------|----------|
| 2 | Sorting techniques | 7 | 0 | Know the complexities; implementing them is low interview yield. |
| 5 | Strings (basic/medium) | 15 | 0 | |
| 15 | Tries | 7 | 0 | |
| 18 | Strings (hard) | 9 | 0 | KMP, Z-function, Rabin-Karp. Rare in screens. |
| 1 | Learn the Basics — remainder | ~25 | 0 | Skip unless a gap surfaces. Phase 0 covered the parts that matter. |

---

## Running totals

| | Count |
|---|---|
| Phase 0 complete | 1 / 15 |
| Sheet problems ticked | 3 / 455 |
| On the re-do list | 0 |

Carried over from pre-semester: Two Sum sorted (two-pointer) and Two Sum unsorted
(hash-map complement), 2026-06-19, now in `steps/03-arrays/`. Both count toward Step 3.

## Patterns banked

| Pattern | Trigger to recognize it | Note |
|---------|------------------------|------|
| Two pointers | sorted array + pair / triplet / range | `patterns/01-two-pointers.md` |
| Hash-map complement | unsorted + "have I seen X before" | note not yet written |

## Re-do list

Problems that needed a hint. Re-solve from scratch on the due date, no notes. This list
being empty because hints were avoided is worse than it being long.

| Problem | Step | Hinted on | Re-do due | Done |
|---------|------|-----------|-----------|------|
| | | | | |

## Session log

Detailed per-session notes live in `../PROGRESS.md`. This file tracks *what*; that one
tracks *how it went*.
