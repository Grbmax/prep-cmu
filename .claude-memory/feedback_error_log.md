---
name: feedback-error-log
description: Recurring logical & syntactical errors the student keeps making — drill these specifically until they go away
metadata: 
  node_type: memory
  type: feedback
  originSessionId: e0d15d00-bcb1-423e-83c0-f544f750e5f8
---

Track recurring mistakes and engineer hurdles that force the student to overcome them
on purpose. Update this list after every exercise — add new patterns, mark ones that
have been cleaned up.

**Why:** Student explicitly asked me to track recurring errors and keep throwing
hurdles at him so he overcomes the same logical mistakes through repetition rather
than getting them pointed out and forgetting. Goal is muscle-memory, not a one-time
fix.

**How to apply:**
- After every exercise, append observed errors here under "Recurring patterns."
- When designing the next exercise / hurdle, INTENTIONALLY craft inputs or constraints
  that will surface the patterns he's still weak on (e.g. an unsorted list to expose
  index-vs-value, an all-negative input to expose "init max to 0" bugs, an odd size
  to expose off-by-one, a function that allocates without freeing to expose ownership).
- When he gets one right that was previously on the list, call it out briefly and
  mark it cleaned up. Positive feedback for behavior to repeat — per
  [[feedback-pacing]] save-from-success rule.

---

## Recurring patterns (active — keep drilling)

1. **Off-by-one in for-loops:** writes `i <= n` when iterating array indices. Has hit
   this twice now (Ex.2 max_elem first attempt; Ex.3 squares — BOTH loops in one
   file). Drill: every new loop, ask "valid indices are 0..n-1; does my condition
   include n?" Hurdle idea: give him an array whose size is odd or whose last element
   is something distinctive (e.g. 42), so an off-by-one prints garbage instead of
   silently working.

2. **`int` for sizes/indices instead of `size_t`:** keeps triggering sign-compare
   warnings. Sometimes self-corrects, sometimes not. Drill: whenever he writes an
   array loop, gently nudge if the counter is signed. He's seen the rule; now make
   it reflexive.

3. **Uninitialized / under-initialized variables:** wrote `int curr;` and `int pos;`
   raw, also wrote `int c = 0; c = *a;` (double-init). Less frequent now, but watch.
   Drill: prefer "init with the final value you want" over "init to 0 then assign".

4. **Returning a reference to something that dies (or could):** predicted the bug in
   Ex.2 correctly under coaching, but the instinct to write `return v[pos]` from a
   reference-returning function on a temporary is the kind of thing that hides in
   real code. Hurdle idea: a later exercise that returns by reference where the
   caller passes a temporary vs a named variable, observe which one explodes.

5. **Value-vs-index confusion:** `pos` accidentally holding the max VALUE while being
   used as an INDEX (Ex.2). Cleaned up once corrected, but the mental tag of "what
   does this variable mean" is fragile. Drill: when introducing a tracker var,
   ask him to name what it stores ("the index of the current best" vs "the current
   best value").

## Cleaned up (proven solid — stop drilling unless regresses)

- For-loop *punctuation* (semicolons not commas between the three parts) — was wrong
  once in Ex.2, hasn't recurred since.
- `*p` vs `p` when dereferencing — wrote `std::cout << a` (pointer address) once in
  Ex.1, hasn't recurred.
- `clang` vs `clang++` toolchain confusion — resolved, terminal builds now reflexive.
- `null`-check instinct from JS — replaced with `!v.empty()` understanding.
- `new[]` ↔ `delete[]` pairing — articulated correctly in the gate, applied correctly
  in Ex.3.

## Hurdle bank (specific test inputs / problem variants to use)

- **All-negative input** → forces "init to first element, not 0".
- **Single-element vector** → exposes off-by-one on either end.
- **Empty vector** → forces him to confront preconditions / throwing / `std::optional`.
- **Heap allocation without a matching free** → run under `-fsanitize=address`, read
  the leak report aloud.
- **Function that takes `const T&` and we try to call with a temporary** → demonstrate
  lifetime-extension rules in a later exercise.
- **Mixing `new` with `delete[]` or `new[]` with `delete`** → run under sanitizer, see
  the failure mode, articulate why.
