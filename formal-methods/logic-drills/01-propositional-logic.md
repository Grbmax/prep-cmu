# Formal Methods 01 — Propositional Logic

Propositional logic is the algebra of true/false statements combined with connectives.
In formal methods it's the substrate: you specify properties of a system as logical
formulas and reason about whether they hold. Get fluent here and predicate/temporal
logic become extensions, not new subjects.

## Notation (used throughout)
- `¬p` — not p
- `p ∧ q` — p and q
- `p ∨ q` — p or q (inclusive)
- `p → q` — implies (p → q is false ONLY when p is true and q is false)
- `p ↔ q` — iff (true when p and q have the same truth value)
- A formula is **valid** (a tautology) if true under every assignment; **satisfiable**
  if true under at least one; **unsatisfiable** (a contradiction) if true under none.
- Two formulas are **equivalent** (≡) if they have identical truth tables.

The connective that trips everyone up: `p → q`. It is *not* causation. "If the lock is
engaged then the door is closed" is vacuously true whenever the lock is not engaged.
Read implication as "you never see p true while q is false."

---

## Drills

Frame each around the system property in the prompt. Work them before scrolling to
answers. After each, I will ask you the Formal Methods question:
**"What does this specification guarantee, and what does it NOT guarantee?"**

**1.** Let `a` = "user is authenticated", `r` = "request is allowed". A system enforces
"only authenticated users get their requests allowed." Write this as an implication.
Then: does your formula forbid an *unauthenticated* user from being allowed?

**2.** Build the truth table for `p → q`. State the one row where it is false.

**3.** A cache returns either fresh data or an error, never both, never neither. Let
`f` = "returns fresh data", `e` = "returns error". Write a single formula capturing
"exactly one of f, e holds." (Hint: exclusive or.)

**4.** Is `(p → q) ↔ (¬q → ¬p)` valid? (This is the contrapositive law — central to
how you'll restate safety properties.)

**5.** A deploy script claims: "If tests pass, we deploy." Observed: we did NOT deploy.
What, if anything, can you conclude about the tests? Name the inference rule.

**6.** Simplify `¬(p ∧ q)` and `¬(p ∨ q)` into formulas using ¬ on the individual
variables. Name the law.

**7.** A retry policy: "We retry if and only if the call failed and we're under the
attempt limit." Let `r`=retry, `f`=failed, `u`=under limit. Write the formula, then
give the condition under which we do NOT retry, simplified.

**8.** Is `p ∨ ¬p` valid? Is `p ∧ ¬p` satisfiable? Name each.

**9.** Show `p → q ≡ ¬p ∨ q` by truth table. Why does this equivalence matter when a
SAT/model checker only accepts formulas in terms of ¬, ∧, ∨?

**10.** A monitor asserts the invariant: "If the queue is full, no new item is
enqueued." Let `F`=queue full, `N`=new item enqueued. Write the invariant. Then:
suppose at some instant `N` is true and `F` is true — is the invariant violated?
What does the invariant say about the case where the queue is *not* full?

---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
(scroll down for answers)
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---

## Answers

**1.** `r → a`  ("if a request is allowed, the user is authenticated"). Equivalently
the contrapositive `¬a → ¬r`. It does NOT say authenticated users are always allowed
(`a → r` is a different, stronger claim) — only that being allowed *requires* auth.

**2.**
| p | q | p → q |
|---|---|-------|
| T | T |   T   |
| T | F |   F   |
| F | T |   T   |
| F | F |   T   |
False only on the row p=T, q=F.

**3.** `f ⊕ e`, i.e. `(f ∨ e) ∧ ¬(f ∧ e)`. The first conjunct forbids "neither", the
second forbids "both".

**4.** Valid. A formula and its contrapositive are equivalent — identical truth tables.
This is why "if allowed then authenticated" and "if not authenticated then not allowed"
are interchangeable specifications.

**5.** From `tests_pass → deploy` and `¬deploy`, conclude `¬tests_pass` (tests did not
pass). Inference rule: **modus tollens**. (You may NOT conclude anything from merely
observing a deploy about whether tests passed — the implication only runs one way.)

**6.** `¬(p ∧ q) ≡ ¬p ∨ ¬q` and `¬(p ∨ q) ≡ ¬p ∧ ¬q`. **De Morgan's laws.**

**7.** `r ↔ (f ∧ u)`. We do NOT retry when `¬(f ∧ u) ≡ ¬f ∨ ¬u` — the call succeeded,
or we're at/over the attempt limit (or both).

**8.** `p ∨ ¬p` is valid (law of excluded middle, a tautology). `p ∧ ¬p` is NOT
satisfiable (a contradiction).

**9.**
| p | q | p→q | ¬p∨q |
|---|---|-----|------|
| T | T |  T  |  T   |
| T | F |  F  |  F   |
| F | T |  T  |  T   |
| F | F |  T  |  T   |
Columns match, so `p → q ≡ ¬p ∨ q`. It matters because implication isn't a primitive
connective for many solvers; you rewrite every `→` into `¬, ∨` (and via De Morgan into
CNF) before feeding it to a SAT engine or a tool like Alloy/TLA+ internally.

**10.** Invariant: `F → ¬N` (equivalently `¬(F ∧ N)`). If `N ∧ F` both hold, the
invariant IS violated — that's exactly the forbidden row. When the queue is not full
(`¬F`), the invariant says **nothing** about `N`: enqueuing is permitted but not
required. A safety invariant constrains the bad case only; it never forces progress.
