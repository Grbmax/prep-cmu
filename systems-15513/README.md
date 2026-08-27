# 15-513 — Introduction to Computer Systems (Fall 2026)

CS:APP. This replaced 15-640 in the Fall schedule; 15-513 is the prerequisite that
clears the way for 15-640 in a later semester, so taking it first is the correct order
rather than a detour.

- **Textbook:** Bryant & O'Hallaron, *Computer Systems: A Programmer's Perspective*, 3rd ed.
- **Course site:** https://www.cs.cmu.edu/~213/ · **Labs:** https://www.cs.cmu.edu/~213/labs.html
- **Weighting (typical):** labs ~52%, exams ~30%, written/prep assignments ~18%.
  The labs *are* the course.
- **Language: C.** Not C++. See the separation rule in `../dsa/README.md`.

## Academic integrity — the rule that governs this folder

Everything under `labs/` is graded work. For that material I explain concepts, point at
the CS:APP chapter, and teach debugging *method* — reading a `gdb` backtrace, using
`objdump`, interpreting a cache simulator's miss counts. I will not write lab code,
write pseudocode for lab code, or fix specific lines in it, and I'll say so if asked.
CMU's autograder and integrity policy are not things to be clever about.

Where I *can* go all-in: `drills/`. Same concept, different problem, no grade attached.
If a lab exposes a gap, we build a drill for it and hammer that instead.

## Lab calendar

| Lab | Window | What it actually teaches | CS:APP |
|-----|--------|--------------------------|--------|
| L0 C Programming | Aug 25 – Sep 01 | C fluency, the build toolchain, style enforcement | Ch. 1 |
| L1 Data | Aug 27 – Sep 08 | Bit-level ops, two's complement, IEEE 754 floats | Ch. 2 |
| L2 Bomb | Sep 03 – Sep 15 | x86-64 assembly, reading disassembly, `gdb` | Ch. 3 |
| L3 Attack | Sep 15 – Sep 24 | Buffer overflows, stack discipline, ROP | Ch. 3 |
| L4 Cache | Sep 24 – Oct 08 | Memory hierarchy, locality, blocking for cache | Ch. 5–6 |
| L5a Malloc (checkpoint) | Oct 08 – Oct 27 | Allocator design: free lists, splitting, coalescing | Ch. 9 |
| L5b Malloc (final) | – Nov 03 | Segregated lists, footer elimination, utilization | Ch. 9 |
| L6 Shell | Nov 03 – Nov 12 | Processes, signals, race conditions, `fork`/`exec` | Ch. 8 |
| L7 Proxy | Nov 12 – Nov 24 | Sockets, HTTP, concurrency, caching | Ch. 11–12 |
| L8 SFS | Nov 19 – Dec 03 | File systems, on-disk layout | Ch. 10 |

**Malloc is the one that eats weeks.** Plan the DSA schedule around Oct 8 – Nov 3
being compressed. See `../ROADMAP.md`.

## Double-dips worth exploiting

| 15-513 gives you | Which also serves |
|------------------|-------------------|
| L1 Data — bit manipulation | Striver Step 8 (Bit Manipulation) — do them the same week |
| L4 Cache — locality, access patterns | Why array traversal order matters in DSA; real answers in "how would you optimize this" |
| L5 Malloc — free lists, pointer arithmetic | Striver Step 6 (Linked List); pointer fluency generally |
| L6 Shell — processes and signals | Distributed systems intuition for when 15-640 lands |
| Whole course | The systems-interview half of an ML-infra role — this is the coursework that most directly serves the C++/ML-systems direction |

## Layout

```
systems-15513/
├── README.md   this file
├── labs/       your lab work (I do not write code here — see the rule above)
├── notes/      CS:APP reading notes, lecture notes, exam prep
└── drills/     off-grade practice problems on the same concepts (normal tutor rules)
```

## Track this per lab

When a lab is done, add one line to `../PROGRESS.md`: what the lab actually taught you
(not what it asked you to do), what took the longest, and what you'd want to re-derive
before the exam. The exams test the concepts the labs drilled — that log is your study
guide in December.
