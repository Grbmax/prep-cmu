# START HERE

**You do not need to read any other file in this repo.** ROADMAP.md, CLAUDE.md,
dsa/STRIVER-TRACKER.md — those are my notes, so that I stay consistent across sessions
and don't lose track of what you've done. They are not homework. If you never open them,
nothing breaks.

Here is the entire thing you need to know:

## Which Claude do you talk to?

You have two, and they are for different things.

**Claude Code, in the terminal, inside this repo — use this for DSA sessions.**

```
cd ~/Developer/cmu/prep-cmu
claude
```

It reads `CLAUDE.md` automatically when it starts, which is exactly what that file is
for — the tutoring rules load themselves. It sits in the same terminal where you compile
and run, so it sees your errors directly. This is the setup you built, and it's the right
one for the daily loop.

**Cowork (the desktop app) — use this for everything wider.** Planning, anything touching
your Obsidian notes and the repo at once, research, course logistics. It can reach several
folders at the same time; Claude Code sees only the repo it's opened in.

Rule of thumb: **one problem, one repo → terminal. Big picture, many folders → Cowork.**

Both write to the same files, so nothing gets lost either way.

## Starting a DSA session

In the terminal, inside the repo, say:

> **"start 0.1"**

(or 0.2, 0.3 — whatever the next one is. I'll tell you at the end of each session.)

That's it. I hand you one problem. You write the code. I correct it. We stop.

## What happens in a session

1. I give you one problem, in plain words. No jargon that I haven't defined.
2. You guess what kind of problem it is — you're allowed to be wrong, that's the point.
3. You write the code yourself. I will not write it for you.
4. You run it (two commands, below).
5. I tell you what a senior engineer would change, and why.
6. I write down what happened so next session picks up where this one stopped.

One problem is a session. If a session is 25 minutes, that's a real session. You are not
behind.

## The two commands

Make a new file for a problem:

```
cd ~/Developer/cmu/prep-cmu/dsa
make new FILE=steps/03-arrays/largest_element.cpp
```

Open that file in VS Code, write your code, then run it:

```
make run FILE=steps/03-arrays/largest_element.cpp
```

That's the whole toolchain. If `make run` prints errors you don't understand, paste them
to me — reading error messages is a skill I'll teach you, not something you're supposed
to already have.

## Words I use, in plain English

Tell me whenever I use one that isn't here. I'll add it.

- **DSA** — data structures and algorithms. The interview material.
- **The sheet / Striver A2Z** — a public list of ~455 practice problems, sorted sensibly.
  We use it as a to-do list so we don't miss a topic. **You never watch the videos.**
- **Pattern** — a shape of problem that keeps coming back. "Two pointers" is a pattern.
  The goal is to see a new problem and think "oh, this is one of those."
- **Complexity / Big-O** — roughly, "if the input gets 10x bigger, how much slower does
  this get?" Written like O(n) or O(n²).
- **STL** — the standard set of ready-made tools in C++ (lists, maps, sorting). You don't
  build these yourself; you learn which one to reach for.
- **AddressSanitizer / ASan** — a checker built into the compiler. It shouts when your
  code touches memory it shouldn't. It's on by default here, deliberately: it catches your
  most common bug the moment it happens instead of silently giving a wrong answer.
- **Phase 0** — the first two weeks. Rebuilding C++ through easy problems. Where you are.
- **`make`** — a tool that runs the compiler for you so you don't type a long command.

## If you're overwhelmed

Say so and we'll do one problem and stop. The plan in the other files assumes a good
month. It is not a promise you made to anyone.
