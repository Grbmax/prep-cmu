---
name: feedback-dsa-pattern-lens
description: "Always show the idiomatic / competitive-programming-optimized version alongside the student's working code, and teach pattern-based thinking"
metadata: 
  node_type: memory
  type: feedback
  originSessionId: e0d15d00-bcb1-423e-83c0-f544f750e5f8
---

After the student gets an exercise working, ALSO show the shorter / idiomatic /
competitive-programming-optimized version that achieves the same thing — and name the
pattern or standard-library tool behind it.

**Why:** The student's explicit goal is to stop thinking in brute-force terms and
start recognizing reusable patterns and methods, so that DSA becomes intuitive rather
than something he grinds. He wants to build the instinct a strong competitive
programmer has: "this is a <pattern> problem, the clean tool is <X>." Seeing the
optimized form right after his own hand-rolled version is how that instinct forms.

**How to apply:**
- Let him solve it his own way FIRST (don't pre-empt the learning by handing the
  one-liner up front — that violates the no-spoonfeed rule in [[feedback-pacing]]).
- THEN, once correct, present the idiomatic/optimized version: relevant STL algorithm
  (`std::max_element`, `std::sort`, `std::accumulate`, two-pointer/sliding-window
  template, hash-map trick, etc.), why it's better (clarity, complexity, fewer bugs),
  and the pattern name to file it under.
- Frame DSA work around patterns, not ad-hoc loops: name the pattern, the invariant,
  the complexity. Connect back to [[student-profile]] (never done serious DSA grind).
- Keep the pacing discipline from [[feedback-pacing]] — introduce the optimized form
  as one more digestible step, not a dump.
