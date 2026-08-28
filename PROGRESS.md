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
| **DSA — Striver A2Z (C++)**  | Phase 0.3 done (check sorted) — 5/455 sheet total | 2            | 2026-08-27   |
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
3. **`int` vs `size_t`** for indices; initialize-on-declare. Recurred again 2026-08-27
   (loop index AND an `arr.size() < 0` guard) — now the most active target.
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

### 2026-08-27 (cont.) — DSA — Phase 0.3 — Check if array is sorted
- **Covered:** early return vs. flag variable — same check, two shapes. Wrote it
  with a flag+break first, correct on the first attempt with no bugs.
- **Got right:** clean solve, no hint needed — first bug-free problem of the
  session. O(n)/O(1) from memory. Correctly reasoned the strictly-increasing
  variant needs `<` to become `<=` (not flipped to `>` — caught his own
  misdirection on this after one clarifying question, didn't need it explained).
  Rewrote flag+break into direct early-return himself once shown the shape.
- **Struggled with:** nothing code-side. Momentary wrong instinct on the variant
  (flipping the operator direction instead of loosening it) — self-corrected
  immediately once asked to re-examine what the current condition catches.
- **Quiz result:** 2/2 (complexity + variant, both correct after one nudge).
- **Pattern named:** linear scan, early-exit. STL equivalent noted:
  `is_sorted(begin, end)`.

### 2026-08-27 (cont.) — DSA — Phase 0.2 — Second largest without sorting
- **Covered:** single-pass "running top-2": two accumulators seeded `INT_MIN`,
  demote-old-largest-to-second on a new max, guard so duplicates of the max don't
  get counted as a distinct second-largest, then a post-loop check (`s_largest
  still INT_MIN?`) to detect "no second largest exists" (all-same / single element).
  Bug hunt was long and mostly self-driven — walked through 5 distinct bugs across
  ~8 attempts before it was fully correct.
- **Got right:** Big-O (O(n)/O(1)) unprompted. Root-caused the null-pointer/segfault
  crash himself (missing `return` after the empty-array guard — a regression from
  the pattern he'd used correctly in 0.1) after one Socratic question. Correctly
  reasoned the k-th-largest variant needs a different structure (min-heap of size
  k), unprompted.
- **Struggled with (bug sequence, in order):**
  1. Empty-array guard printed but didn't `return` — fell through into `nums[0]`,
     segfault. Self-fixed after being asked to trace it.
  2. Classic "lost the old max" bug: `largest` got overwritten on a new max but
     nothing captured the outgoing value as the new `second` — so strictly
     increasing arrays returned the *first* element as "second largest." Needed
     a conceptual hint (trace `{1,2,3,4}` by hand) — self-corrected from there.
  3. Seeded `second` to the same value as `largest` (or later, `0`) — failed on
     descending/all-negative arrays where `largest` never changes after `i=0`, so
     `second` never had a valid path to update. Needed a structural hint (fold
     demotion into the `if`, seed with `INT_MIN`).
  4. Misheard the structural hint as "remove the `else if` entirely" instead of
     "add the demotion into the `if`, keep the `else if`" — dropped the branch
     that catches descending values. This needed pseudocode (3rd ask on the same
     mechanic, per the hint-escalation rule) to unstick.
  5. For the all-same/no-second-largest case, put the "give up" check *inside* the
     loop as a bare `else` — fired per-element instead of once for the whole
     array, breaking otherwise-correct cases like `{1,2,4,4}`. Two-step fix: first
     a conceptual hint (trace `{1,2,4,4}` through the new code), then a structural
     hint (move the check to after the loop, test the sentinel once).
- **Quiz result:** 2/2 complexity (O(n)/O(1)), correct k-th-largest variant answer
  unprompted.
- **Revisit next session:** the recurring shape across bugs 2-3-4 is losing track
  of *which* variable should capture *which* outgoing value at *which* point in
  the control flow — less a syntax gap now, more a "trace before you type" habit
  gap. Consider requiring a hand-trace of one non-trivial test case (not the
  happy path) before running the compiler, for the next few problems.
- **Pattern named:** running top-2 (single-pass), generalizes to top-K via a
  min-heap of size K — not yet written to `patterns/` (revisit once an actual
  top-K problem is solved and the heap code exists to reference).

### 2026-08-27 — DSA — Phase 0.1 — Largest element in an array
- **Covered:** first DSA session since 2026-06-20 (~2 month gap). Rebuilt Big-O from
  scratch again (O(n)/O(1) recall came back clean after one prompt — not gone, just
  needed a nudge). Solved largest-element: linear scan, running max seeded from
  `arr[0]` (not `0` — caught the all-negative bug himself once asked to trace it by
  hand). Restructured from inline `main()` code into a proper `const vector<int>&`
  solution function + driver, matching the sheet's per-problem shape going forward.
  Installed and configured `clang-format` (Google-based, repo-root `.clang-format`).
- **Got right:** O(n)/O(1) complexity from memory, unprompted reasoning ("we hold one
  element"). Self-corrected the `largest = 0` seed bug after being asked to trace an
  all-negative input by hand — didn't need the answer given. Correctly reasoned
  `const vector<int>&` avoids both the copy (value) and the mutation risk (plain ref)
  once the three options were laid out.
- **Struggled with:** (1) reached for `std::array<int,4>` instead of the assigned
  `vector<int>` mechanic — corrected once flagged. (2) `int i` vs `size_t` for the
  loop index AGAIN — compiler's `-Wsign-compare`/`-Wsign-conversion` caught it live;
  he named the fix correctly unprompted once shown the warning. (3) first guard
  attempt was `if (arr.size() < 0)` — same unsigned-can't-be-negative gap as the
  index bug, same session; recognized it once asked to reconsider. (4) general
  recall of pre-semester exercises (Ex.1-4, Two Sum both variants) is largely gone —
  recapped in-session, not re-drilled today.
- **Quiz result:** 2/2 on Big-O gate (O(n) time, O(1) space, both reasoned correctly).
- **Revisit next session:** `int` vs `size_t` is still not automatic — 6th+ recurrence
  across sessions, stays the #1 active target alongside value-vs-index. Consider a
  30-second reflex check ("what type does `.size()` return?") before every problem
  in Phase 0 until it stops needing a prompt.
- **Complexity recall:** O(n) time / O(1) space, correct and unprompted-after-nudge.
- **Pattern named:** linear scan / single-pass reduction — not written to `patterns/`
  (too foundational to need a note; it's the base case other patterns build on).
  Idiomatic version shown: `*max_element(arr.begin(), arr.end())`.

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

### >>> NEXT SESSION START HERE <<< (revised 2026-08-27, post Phase 0.3)

1. **DSA — Phase 0.4.** `dsa/STRIVER-TRACKER.md` — "Remove duplicates from sorted
   array." Mechanic: two-index write pointer — this is the value-vs-index drill
   target's next real test, watch closely.
2. **Trace-before-you-type** — still the standing target from 0.2's long bug hunt.
   0.3 was clean on the first attempt, no trace needed, so no new evidence either
   way yet.
3. **`int` vs `size_t`** and **value-vs-index** — both clean for 3 straight problems
   now (0.1 was the last size_t slip, value-vs-index hasn't recurred since the
   pre-semester sessions). Getting close to the Phase 0 gate threshold — keep
   watching but don't relax the check yet.
3. **Formal Methods, unfinished:** the De Morgan check (`¬(authenticated ∧ premium)`,
   `¬(admin ∨ owner)`) was never answered before we pivoted to git setup. Close that
   when 17-614 coursework has room — coursework outranks this pre-arrival sequence.
4. **Deprioritized:** C++ Exercise 5 (`int**` dynamic append) — 15-513's malloc lab
   covers this ground better. Only return to it if a DSA problem exposes the gap.

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
