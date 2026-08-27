# Claude Memory (portable copy)

This directory mirrors my persistent memory for this project, so it survives a
device switch. Memory normally lives outside the repo at a path derived from the repo's location:

```
~/.claude/projects/-Users-gaurav-Developer-cmu-prep-cmu/memory/
```

> **Note (Aug 2026):** this path changed. The repo used to live at `~/gb-brain/prep-cmu`,
> so the old memory folder was `-Users-gaurav-gb-brain-prep-cmu`. If tutoring sessions
> seem to have forgotten your history, that stale folder is why — copy the files across
> using the commands below. `CLAUDE.md` in the repo root loads automatically regardless,
> so the important rules are never lost.

## To restore on a new device

After cloning the repo on a new machine, copy these files back into the live
memory location so I (Claude) actually read them:

```bash
P=~/.claude/projects/-Users-gaurav-Developer-cmu-prep-cmu
mkdir -p $P/memory
cp .claude-memory/*.md $P/memory/
mv $P/memory/MEMORY.md $P/MEMORY.md
```

Then start the next session — `MEMORY.md` will be loaded automatically.

## What each file does

- **MEMORY.md** — the index. Lists every memory with a one-line hook.
- **student_profile.md** — who you are, how to pitch explanations.
- **feedback_pacing.md** — small chunks, no unexplained jargon.
- **feedback_dsa_pattern_lens.md** — after a solution, show the idiomatic/competitive version.
- **feedback_error_log.md** — recurring mistakes + hurdle bank to drill them.
- **feedback_token_economy.md** — terseness rules; decide-and-propose vs menus.
