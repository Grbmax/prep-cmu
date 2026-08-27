# PROGRESS.md — Learning Log

One entry per session. Most recent at the top. Be honest in the "Struggled" field —
that field drives what we drill next.

> **Phase change, 2026-08-27.** The pre-arrival five-track plan is retired. Fall
> semester is live: 15-513 replaced 15-640 (deferred), and DSA via the Striver A2Z
> sheet became top priority against Summer 2027 recruiting. Distributed Systems and
> Python/AI moved to `parked/`. History below is preserved unchanged — the drill
> targets it identified are still active.

## Status board

| Track                        | Current position                          | Confidence (1-5) | Last touched |
|------------------------------|-------------------------------------------|------------------|--------------|
| **DSA — Striver A2Z (C++)**  | Step 3 Arrays — 2/455 (both Two Sum variants) | 2            | 2026-06-19   |
| **15-513 Systems (C)**       | Not logged here yet — L0/L1 window is open | -                | -            |
| **17-614 Formal Methods**    | Propositional logic — De Morgan check open | 3                | 2026-06-20   |
| C++ fluency (supporting)     | Ex. 1-4 done; Ex. 5 (`int**` append) open  | 3                | 2026-05-27   |
| ~~Distributed Systems~~      | parked — 15-640 deferred                   | -                | -            |
| ~~Python for AI~~            | parked — semester 2                        | -                | -            |
| ~~C systems (self-directed)~~| closed — superseded by 15-513              | -                | -            |

## Active drill targets

Carried forward from the log below. These do not clear until they stop recurring.

1. **Value-vs-index** — 4 recurrences (Ex.2 max_elem, Ex.4, Two Sum sorted, Two Sum
   unsorted). Highest-priority catch.
2. **Off-by-one** (`<=` vs `<`) — plus the "pattern twin" habit: fix one loop, immediately
   check its sibling.
3. **`int` vs `size_t`** for indices; initialize-on-declare.
4. **Affirming the consequent** (Formal Methods) — recognizing implication shapes across
   negated phrasings.

## Entry template (copy this for each new session)

### YYYY-MM-DD — <Track> — <Topic>
- **Covered:** what we worked through.
- **Got right:** concepts/exercises that landed cleanly.
- **Struggled with:** where reasoning broke down, what hints were needed.
- **Quiz result:** X/3 (gate to next topic).
- **Revisit next session:** specific weak spots to re-drill.
- **Complexity recall (DSA only):** time / space / variant discussed.
- **Pattern named (DSA only):** and whether it went into `dsa/patterns/`.

---

## Log

### 2026-05-27 (session 1, cont.) — C/C++ — Exercise 2 (max_elem, references & dangling)
- **Covered:** `std::vector<int>` basics (`.size()`, `[]`, `.push_back`), `const&`
  parameters (avoid copy + read-only), returning `const int&`, and the dangling-
  reference trap. Used `-fsanitize=address` to make UB visible. Introduced the
  competitive/idiomatic version: `*std::max_element(v.begin(), v.end())`.
- **Got right:** correctly identified returning a ref to a vector element is safe vs a
  ref to a local dangles. Predicted the dangling-reference use-after-free before running
  it, and confirmed via AddressSanitizer. Read the ASan report's key lines with help.
- **Struggled with:** (1) for-loop syntax — used commas instead of semicolons between
  the three parts; `<=` off-by-one; signed/unsigned compare (`int i` vs `size_t`).
  (2) put the running-max accumulator INSIDE the loop (reset each iteration) — needed
  to see a non-sorted counterexample to spot it. (3) uninitialized vars again.
  (4) JS `null`-check instinct — learned C++ ints have no null; emptiness check is
  `!v.empty()`, `[]` is unchecked vs `.at()`.
- **Quiz result (pointers gate from Ex.1):** 2/3 — passed. Slip: stated `int p` instead
  of `*p = 99` to write through a pointer (knew it in code, wording slip).
- **Revisit next session:** for-loop mechanics until automatic; initialize-on-declare
  habit; `size_t` for indices. Reinforce when to return by value vs reference.
- **New tutor directive captured:** teach with competitive-programming/pattern lens —
  always show idiomatic/optimized version after he solves it (added CLAUDE.md rule 9).
- **RESOLVED next session (continuation):** Ex.2 index fix applied: `size_t pos = 0`,
  compare `v[i] > v[pos]`, return `v[pos]`. Runs clean. Gate passed 2/2 (value-vs-index
  reasoning sound; understood return-by-value vs `const&` tradeoff). Coached on:
  reference-return is mostly a win for BIG objects; for `int`, return by value is
  safer/equivalent — the exercise used `const int&` purely to teach the dangling trap.

### 2026-XX-XX (sessions continued) — C/C++ — Exercises 3 & 4 (heap, ownership, dangling)
- **Covered:** heap vs stack lifetimes; `new int(...)` ↔ `delete`; `new int[n]` ↔
  `delete[]`; caller-as-owner pattern; `const int*` for read-only pointer params;
  return-by-value vs return-via-heap-pointer tradeoff for primitives.
- **Got right:** Ex.3 made_squares + print_array works, sanitizer-clean. Ex.4 all
  three versions written; correctly used `new int(100)` ↔ `delete heap;`. Articulated
  why C (return-by-value) is the senior choice for a single int and named the cases
  where B (heap pointer) would actually be correct (sharing, size, polymorphism,
  lifetime threading).
- **Struggled with:**
  (1) Off-by-one AGAIN — wrote `i <= n` in BOTH loops of squares.cpp; second one
      caught only after fixing the first (lesson: search for the pattern twin).
  (2) REGRESSION on dereferencing — printed `val` and `heap` (addresses) instead of
      `*val`, `*heap`. Had to be re-shown after using `*` correctly in Ex.1.
  (3) Conceptual: thought "lifetime ends" meant "local fn vs global fn"; sharpened
      to "variable lifetime ends when its frame dies."
- **New tooling lesson:** macOS ASan does not detect stack-use-after-return by
  default. Enable with `ASAN_OPTIONS=detect_stack_use_after_return=1 ./bin`.
- **Senior-engineer review notes given:** add trailing newline in print loops; use
  `size_t` for sizes/indices; `const int*` for read-only pointer params.

### 2026-06-19 (cont.) — DSA — Two Sum (unsorted) via hash-map complement
- **Covered:** `std::unordered_map<K,V>` basics (insert/read with `[]`, presence
  via `.count(k)`, the silent-insert footgun); the complement pattern
  ("have I seen `target - x` before?"); time–space tradeoff (O(n) time costs O(n)
  space, vs two-pointer's O(1) space on sorted input).
- **Got right:** correct algorithm shape on first attempt after one mid-correction;
  articulated O(n) space ("map grows up to n entries") and why no sortedness is
  needed ("bag of all earlier elements + existence query"); ran sanitizer-clean
  after the indexing fix.
- **Struggled with:** value-vs-index, 4TH RECURRENCE: used range-for
  `for (int i : nums)` getting the VALUE, then indexed it as `nums[i]` →
  out-of-bounds caught by ASan. Coached on the two for-loop forms:
  range-for = values, indexed-for = positions. Rule of thumb: need the index →
  Form 2 always.
- **Patterns banked this session:** sorted + pair → two pointers (O(n) time, O(1)
  space). Unsorted + pair → hash-map complement (O(n) time, O(n) space). Generally:
  "have I seen X before" → unordered_map.

### 2026-06-19 — DSA — Two Sum (sorted): brute force + two-pointer
- **Covered:** Big-O from scratch (time + space). O(1)/O(n)/O(n²) shapes, rules
  (sequential adds, nested multiplies, constants drop, lower-order drops, triangular
  loops are O(n²)). Wrote brute force two_sum_sorted (O(n²)/O(1)) and two-pointer
  fast version (O(n)/O(1)). Named TWO patterns: sorted+pair → two pointers;
  unsorted+pair → hash-map complement.
- **Got right:** complexity answers correct without prompting after one example; ran
  unsorted counter-example to prove two-pointer needs sortedness. Algorithm shape and
  loop condition `while (lo < hi)` right.
- **Struggled with / drilled:**
  (1) Big-O entirely new — ECE background, never learned formally; built up from
      first principles. He pattern-matched "nested = O(n²)" too quickly on the first
      check; corrected by seeing inner loop bounded by constant 10 → still O(n).
  (2) Value-vs-index AGAIN — returned `{*lo, *hi}` (values) instead of `{lo, hi}`
      (indices). This is the third time the pattern has bitten him (Ex.2 max_elem,
      Ex.4 conceptual, here). Logged as the #1 active drill target.
  (3) Reached for raw `const int*` for two-pointer markers because of the literal
      name "pointer"; coached to use `size_t` indices for vector traversal. Pointers
      only when you're walking a linked list / pointer-arithmetic structure.
  (4) Outer `for (i=0; i<n; i++)` driving the loop instead of a `while (lo < hi)` —
      conceptual: the markers ARE the loop state.
- **Pattern instincts to bank:** sorted + pair/triplet/range → two pointers. Unsorted
  + "have I seen the complement" → hash map. Triangular nested loop → O(n²).
- **Style nits given:** always brace loop and if bodies, even single-line.

### 2026-06-20 — Formal Methods — Propositional logic (implication, AND/OR, De Morgan)
- **Covered:** rebuilt FM intro using anecdotes (initial symbolic intro overwhelmed
  him). Walked: implication truth table via alarm/door story; the four-row
  conclusion matrix (modus ponens valid, affirming-consequent invalid, modus tollens
  valid, denying-antecedent invalid); the contrapositive equivalence; spec
  guarantees-vs-doesn't-guarantee discipline; AND/OR with inclusive-or footgun;
  De Morgan's laws (`¬(A∧B) ≡ ¬A∨¬B`, `¬(A∨B) ≡ ¬A∧¬B`) and how negation gives the
  bad-case formula for spec violation.
- **Got right:** correctly identified spec violation case in the queue example
  (3/3 on row-pattern matching). Translation #2 (`A ∨ B`) correct on first attempt.
  Asked "guarantees vs not guarantees" mindset is forming.
- **Struggled with:**
  (1) Affirming the consequent — answered "yes Bob is authenticated" because he can
      view; classic reverse-implication trap. Coached via theater-season-pass story.
  (2) Missed the contrapositive on Carol (cannot view → not authenticated); had
      gotten the same shape right earlier in the deploy example. Pattern recognition
      across negated phrasings is the weak spot.
  (3) Translation #1: wrote bare `A ∧ B` instead of `W → (A ∧ B)` — captured the AND
      but missed that "to do X, Y must hold" is fundamentally an implication.
  (4) Translation #3: forgot to define variables before writing the formula.
  (5) Initial symbolic-notation dump was too dense — student requested anecdote-led
      teaching. Restarted FM with stories; that worked.
- **New tutor directive captured:** be terse — decide-and-propose instead of menus,
  no verbatim restatements, no closing recap fluff. Added [[feedback-token-economy]]
  memory + applied for the rest of the session.

### >>> NEXT SESSION START HERE <<< (revised 2026-08-27)

**Priority order has changed.** Recruiting clock now sets the agenda — see `ROADMAP.md`.

1. **DSA first.** Open `dsa/README.md`, agree the C++ decision is final, then start
   Striver Step 4 (Binary Search) — highest interview yield per problem on the sheet,
   and you already have two-pointer basics banked. First target: the "binary search on
   the answer" family, which is the sub-pattern most candidates never recognize.
   Alternative if you want a gentler restart: finish Step 3 (Arrays) easies to rebuild
   C++ typing speed first.
2. **Bit manipulation early.** Striver Step 8 overlaps 15-513 Lab 1 (Data) directly.
   Doing them in the same week is a free double-dip — schedule it now, not in Spring.
3. **Formal Methods, unfinished:** the De Morgan check (`¬(authenticated ∧ premium)`,
   `¬(admin ∨ owner)`) was never answered before we pivoted to git setup. Close that,
   then propositional logic is done — but note 17-614 is now running for real, so
   coursework topics take precedence over this pre-arrival sequence.
4. **Drill targets still active:** value-vs-index (4 recurrences — watch closely),
   off-by-one, `int` vs `size_t`, affirming the consequent.
5. **Deprioritized:** C++ Exercise 5 (`int**` dynamic append) — the concept it teaches
   (manual pointer/heap/ownership mechanics) is now covered far better by 15-513's
   malloc lab. Only return to it if a DSA problem exposes the gap sooner.

### 2026-05-27 — C/C++ — Pointers, references, Exercise 1 (swap)
- **Covered:** value semantics (a variable IS a box, copying duplicates), references
  (`int&` = another name for the same box), addresses (`&a`), pointers (`int* p`),
  dereferencing (`*p`). Built and ran Exercise 1: `swap_ints(int*, int*)`. Sorted out
  the macOS toolchain (use `clang++` not `clang`; build/run from the terminal).
- **Got right:** value-vs-reference distinction landed cleanly on first check.
  Correctly used `&a` to pass addresses and `*a`/`*b` to swap through pointers.
  Self-corrected the swap once shown the temp-variable data-flow bug.
- **Struggled with:** (1) needs slower pacing — dense multi-concept messages overwhelmed
  him (see feedback memory). (2) `return 0;` placed mid-function killed later code —
  unfamiliar that `return` exits immediately. (3) swap temp direction: wrote `*a = c`
  (erasing the value) instead of `c = *a` (saving it first). (4) printed pointer `a`
  instead of value `*a`. (5) toolchain friction: VSCode play/debug button auto-uses
  `clang` (C), not `clang++` (C++); fixed compilerPath, steered to terminal builds.
- **Quiz result:** pending (3-question pointer check in progress).
- **Revisit next session:** reinforce pointer-vs-value when printing/passing; `void`
  return type; initialize-once habit (`int c = *a;`). Then Exercise 2 (return by
  const reference, lifetime of returned references).
