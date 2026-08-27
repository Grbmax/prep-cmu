# ROADMAP — Fall 2026 → Summer 2027 Internship

## The constraint that sets everything else

Summer 2027 internship recruiting for CMU grad students ramps **Sept–Nov 2026**.
Applications open early; technical screens land Oct–Dec. That means:

> **The DSA sheet has to be interview-usable by mid-October, not finished by May.**

This is why the Striver A2Z order in `dsa/STRIVER-TRACKER.md` is re-sequenced by
interview yield rather than followed 1→18. Completeness is the Spring goal; coverage of
the high-frequency patterns is the Fall goal.

## Fall 2026 course load (from the Obsidian hub)

| Course | Title | Mini | Load on this repo |
|--------|-------|------|-------------------|
| 15-513 | Introduction to Computer Systems | Full | **Heavy** — 9 C labs, 52% of grade |
| 17-614 | Formal Methods | 1 | Medium — Tomayko track, excel here |
| 17-611 | Statistics | 1 | Light |
| 17-619 | Product Management | 1 | Light |
| 17-603 | Communications | Full | Light |
| 17-622 | Agile Methods | 2 | Light |
| 17-623 | Quality Assurance | 2 | Light |
| 17-627 | RQ for Embedded Systems | 2 | Light (possible swap → 17-626) |

15-640 Distributed Systems: **deferred**. 15-513 clears its prerequisite properly.

## 15-513 lab calendar (the immovable objects)

| Lab | Window | Collides with |
|-----|--------|---------------|
| L0 C Programming | Aug 25 – Sep 01 | — |
| L1 Data | Aug 27 – Sep 08 | Bit Manipulation step (use it, don't fight it) |
| L2 Bomb | Sep 03 – Sep 15 | Peak application season |
| L3 Attack | Sep 15 – Sep 24 | |
| L4 Cache | Sep 24 – Oct 08 | Mini-1 finals + Mini-2 start |
| L5a Malloc checkpoint | Oct 08 – Oct 27 | **Interview season peak** |
| L5b Malloc final | – Nov 03 | |
| L6 Shell | Nov 03 – Nov 12 | |
| L7 Proxy | Nov 12 – Nov 24 | |
| L8 SFS | Nov 19 – Dec 03 | |

Malloc is the one that eats weeks. Bank the DSA patterns **before** Oct 8.

## Weekly cadence (default; adjust when a lab is due)

- **DSA:** 5 problems/week minimum, 8 in a light week. Quality over volume — a problem
  is "done" only when the pattern is named and the complexity is stated from memory.
  No videos, no tutorials: the sheet supplies problems, the learning happens in session.
- **15-513:** whatever the current lab demands + one CS:APP chapter read ahead.
- **17-614:** one logic/spec drill per week outside of homework.
- **Friday:** 20-minute re-do sprint on the oldest unresolved item in the re-do list.

## Phase plan

**Phase 0 — Aug 27 → ~Sep 12: C++ back into the hands.** ~15 easy problems chosen for
the language mechanic each one forces, not for the algorithm. This is not a syntax
course — every mechanic is learned inside a problem. Non-negotiable gate at the end.
Full breakdown in `dsa/STRIVER-TRACKER.md`.

**Phase 1 — Sep 12 → Oct 15: interview core.** Steps 4 (Binary Search), 3-medium
(Arrays), 10 (Sliding Window & Two Pointer), 9 (Stack & Queues), 8 (Bit Manipulation,
pulled forward to ride 15-513 Lab 1). Target: ~90 problems.

**Phase 2 — Oct → Nov: structures.** Steps 6 (Linked List), 13 (Binary Trees),
11 (Heaps), 14 (BST). Target: ~100 problems.

**Phase 3 — Nov–Dec: the hard half.** Steps 7 (Recursion), 16 (Graphs), 17 (DP),
12 (Greedy). This is where most candidates are weak — being solid here is the edge.

**Phase 4 — Spring: completeness.** Sorting, strings, tries, the remaining hard tail.
Plus 15-640 if it lands in the Spring schedule.

## Checkpoints

- [ ] **Sep 12** — Phase 0 gate passed: value-vs-index clean for 3 consecutive problems.
- [ ] **Sep 15** — Resume + CPDC review current; applications going out.
- [ ] **Oct 15** — Interview-ready checkpoint: can solve a random medium from Steps 3/4/10/13 in 35 min, out loud, in C++.
- [ ] **Nov 15** — Graphs + DP core patterns banked.
- [ ] **Dec 10** — Semester closed out; re-plan Spring around 15-640 and offer status.
