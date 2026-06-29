# DSA Pattern 01 — Two Pointers

## The core idea

Maintain two indices into a sequence and move them under a rule, so you traverse the
structure in O(n) instead of the O(n²) you'd pay with nested loops. The two pointers
encode a decision: "given what I see at these two positions, which one do I advance,
and what does advancing it cost me in coverage?"

Three common geometries:

1. **Opposite ends, converging.** `lo = 0`, `hi = n-1`, move them toward each other.
   Used on *sorted* arrays where the sum/relationship of `a[lo]` and `a[hi]` tells you
   which end to move. Each step eliminates a whole row/column of the brute-force
   search space — that's where the O(n²) → O(n) win comes from.

2. **Same direction, different speeds (fast/slow).** Both start at the left; one
   advances faster or conditionally. Used for in-place filtering, cycle detection,
   and "read pointer / write pointer" compaction.

3. **Two sequences, one pointer each.** Merge-style: advance whichever pointer points
   at the smaller element. The basis of merging sorted lists.

The invariant is everything. Before you write the loop, state in one sentence what is
always true about the region between/around the pointers. If you can't state it, you
don't yet have the algorithm.

## Canonical problems (described, NOT solved)

### A. Two Sum II — sorted input
Given a 1-indexed **sorted** array and a target, return the indices of the two numbers
that add to the target.
- Geometry: opposite ends converging.
- Key insight: if `a[lo] + a[hi] > target`, the largest element is too big with
  *every* remaining partner, so `hi--`. Symmetrically `lo++` when the sum is too small.
- **Time O(n), Space O(1).** Contrast with the hash-map version on *unsorted* input,
  which is O(n) time but O(n) space — sortedness is what buys you the constant space.

### B. Remove Duplicates from Sorted Array (in place)
Given a sorted array, remove duplicates in place so each element appears once; return
the new length. Order preserved, no extra array.
- Geometry: fast/slow, same direction. `slow` marks the write position (end of the
  deduped prefix); `fast` scans ahead.
- Invariant: everything in `[0, slow]` is unique and sorted. You only write when
  `a[fast] != a[slow]`.
- **Time O(n), Space O(1).**

### C. Container With Most Water
Given heights, pick two lines forming a container with the x-axis; maximize trapped
water `= (hi - lo) * min(height[lo], height[hi])`.
- Geometry: opposite ends converging.
- Key insight: the area is limited by the *shorter* wall, so move the shorter wall
  inward — moving the taller one can never increase the area for this width and only
  shrinks the width. This greedy move is the crux; be ready to justify why it's safe.
- **Time O(n), Space O(1).**

## How to recognize it

Reach for two pointers when you see:
- A **sorted** array and a target sum / pair / triplet relationship.
- "In place", "O(1) extra space", "without allocating another array".
- Merging or comparing two ordered sequences.
- Detecting a cycle in a linked list (Floyd's fast/slow).
- Palindrome checks, reversing in place.

## When NOT to use it

- **Unsorted data where order matters to the logic.** If the converging-ends argument
  relies on sortedness and you don't have it, two pointers gives wrong answers — you
  likely want a hash map or to sort first (and sorting costs O(n log n)).
- **You need all pairs/combinations, not an optimum or a single valid pair.** Two
  pointers prunes the search space; if the problem genuinely requires enumerating
  every pair, you can't prune.
- **The advance rule isn't monotonic.** The pattern only works when "moving a pointer"
  monotonically changes the quantity you're testing (sum, area, match). If moving a
  pointer can change the target value non-monotonically, the elimination argument
  collapses. Sliding window is the right tool when the constraint is on a *contiguous
  range* rather than two endpoints.
- **Data isn't randomly indexable** (e.g., a singly linked list where you need
  opposite-ends geometry) — converging pointers need O(1) indexing or you lose the win.

## The questions you must answer after solving any of these
(a) time complexity, (b) space complexity, (c) one variant to think about
— e.g. for Two Sum: "what changes if the array is *not* sorted, or if you need *all*
pairs, or a triplet summing to target (3Sum)?"
