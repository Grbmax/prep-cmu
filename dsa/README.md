# DSA — Striver A2Z in C++

## Why C++

Decided Aug 2026. Three reasons, in order of weight:

1. **It's the ML-systems language.** The Python you'd write for AI work is an API surface.
   The layer underneath it — PyTorch's ATen/c10, CUDA kernels, TensorRT, TVM, vLLM's
   paged-attention core, llama.cpp — is C++. If the goal is AI *infrastructure* rather
   than AI *application*, C++ is the working language, and DSA practice is free reps in it.
2. **It compounds with 15-513.** Pointers, memory layout, allocation, alignment, cache
   behaviour — the malloc and cache labs make you better at C++ and vice versa. One
   mental model, two payoffs.
3. **The sheet is C++-native.** Striver's editorials and videos are C++-first, so there's
   no translation tax between the explanation and your file.

**The real cost, stated honestly:** C++ is more keystrokes than Python under a 35-minute
interview clock. That cost is only paid by people who fight the syntax. The fix is to
build muscle memory for a small STL vocabulary (below) instead of a large one, and to
type the boilerplate from `templates/solution.cpp` until it's automatic. Don't switch
languages mid-stream — the switching cost is far higher than the keystroke cost.

**The one genuine upside of C++ here:** your recurring bug class is value-vs-index and
off-by-one. C++ with `-fsanitize=address` screams about those. Python silently returns a
wrong answer. The compiler is a tutor.

## The C / C++ separation rule — read this before every 15-513 lab

They are different languages and mixing habits will cost you autograder points.

| | 15-513 labs | DSA here |
|---|---|---|
| Language | **C** (C99/C11) | **C++17** |
| Memory | `malloc`/`free`, raw pointers | `std::vector`, RAII, rarely `new` |
| Containers | you build them | STL |
| Strings | `char*`, `\0`-terminated | `std::string` |
| Compile | `gcc -std=c11 -Wall -Werror` | `clang++ -std=c++17 -g -fsanitize=address` |

If you catch yourself reaching for `vector` in a lab, or for `malloc` in a DSA solution,
you've crossed the streams. Stop and re-orient.

## The STL vocabulary worth having automatic

Learn these cold; ignore the rest of the STL until a problem demands it.

`vector` (`push_back`, `size`, `back`, `empty`, `resize`) · `sort(v.begin(), v.end())` with
a lambda comparator · `unordered_map` / `unordered_set` (`.count()`, and know that `[]`
silently inserts) · `map` / `set` when you need ordering · `priority_queue` (and
`greater<int>` for a min-heap) · `deque` for sliding-window maxima · `string`
(`substr`, `+=`, `find`) · `pair` / `tuple` and structured bindings · `lower_bound` /
`upper_bound` · `max_element` / `min_element` / `accumulate` / `reverse`.

## How he learns — the constraint that shapes everything here

**No videos. No tutorials. No reading a solution before attempting.** He absorbs by
attempting, failing, and being corrected — not by watching. Striver's sheet is used as a
problem inventory and an ordering spine, not as a course. The videos are never opened.
Editorials come out only after his own solution compiles and both complexities have been
stated from memory.

Corollary: concepts get explained live, in text, against the specific problem in front
of him — never as a lecture in advance of one.

## Workflow per problem

1. Read the problem cold — no hint, no pattern name from me. **Before writing anything**,
   say what pattern it looks like and why. Write that guess in the file's header comment.
   Being wrong here is useful data — it's exactly the instinct being trained.
2. Brute force first, in words, with its complexity. Don't skip this; the optimization is
   only meaningful as a delta from something.
3. Write it in `steps/NN-<step-name>/<problem_name>.cpp` from the template.
4. Compile and run with the sanitizer: `make run FILE=steps/03-arrays/two_sum.cpp`
5. State time and space complexity **from memory** before checking.
6. Then, and only then, look at the idiomatic/optimized version. Name the pattern. Add it
   to `patterns/` if it's new.
7. Tick the box in `STRIVER-TRACKER.md` with the date.

## The re-do rule

A problem you needed a hint for is not done — it's scheduled. Put it in the Re-do list at
the bottom of `STRIVER-TRACKER.md` dated +7 days. Re-solving from scratch a week later is
what converts "I followed that" into "I can produce that". This is the single
highest-leverage habit on the sheet and the easiest one to skip.

## Timebox

25 minutes stuck with zero progress → stop, get the pattern name only, re-attempt.
45 minutes total → walk the solution together, re-do list +7 days. Grinding past that
teaches frustration, not algorithms.

## Layout

```
dsa/
├── README.md              this file
├── STRIVER-TRACKER.md     progress + ordering — the source of truth
├── steps/                 one folder per Striver step, solutions inside
├── patterns/              one note per named pattern, written after you meet it
├── templates/             solution.cpp + Makefile
└── problems/              scratch / problem statements
```

Note: `Makefile` in this directory is a symlink to `templates/Makefile` so you can run
`make run FILE=...` without the extra path. Earlier solutions from the pre-semester
phase were moved into `steps/03-arrays/`.

## Links

- Sheet: https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2
- Progress tracker (external, optional): https://takeuforward.org/plus
