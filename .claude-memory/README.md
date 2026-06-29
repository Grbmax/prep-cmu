# Claude Memory (portable copy)

This directory mirrors my persistent memory for this project, so it survives a
device switch. Memory normally lives outside the repo at:

```
~/.claude/projects/-Users-gaurav-gb-brain-prep-cmu/memory/
```

## To restore on a new device

After cloning the repo on a new machine, copy these files back into the live
memory location so I (Claude) actually read them:

```bash
mkdir -p ~/.claude/projects/-Users-gaurav-gb-brain-prep-cmu/memory
cp .claude-memory/*.md ~/.claude/projects/-Users-gaurav-gb-brain-prep-cmu/memory/
mv ~/.claude/projects/-Users-gaurav-gb-brain-prep-cmu/memory/MEMORY.md \
   ~/.claude/projects/-Users-gaurav-gb-brain-prep-cmu/MEMORY.md
```

Then start the next session — `MEMORY.md` will be loaded automatically.

## What each file does

- **MEMORY.md** — the index. Lists every memory with a one-line hook.
- **student_profile.md** — who you are, how to pitch explanations.
- **feedback_pacing.md** — small chunks, no unexplained jargon.
- **feedback_dsa_pattern_lens.md** — after a solution, show the idiomatic/competitive version.
- **feedback_error_log.md** — recurring mistakes + hurdle bank to drill them.
- **feedback_token_economy.md** — terseness rules; decide-and-propose vs menus.
