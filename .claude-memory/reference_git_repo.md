---
name: reference-git-repo
description: "This learning project is backed by a git repo on student's personal GitHub — commit and push at every natural session-end"
metadata: 
  node_type: memory
  type: reference
  originSessionId: e0d15d00-bcb1-423e-83c0-f544f750e5f8
---

The `prep-cmu/` working directory is a git repo backed by the student's personal
GitHub:

- **Remote:** `git@github.com:Grbmax/prep-cmu.git`
- **Account:** Grbmax (personal)
- **Branch:** `main` (single-branch workflow for now)
- **SSH-authenticated** — `ssh git@github.com` succeeds as Grbmax.

**Commit discipline (apply automatically):**
At every natural session-end — when the student says "logging off", "exit", takes
a break, or wraps up a topic — stage, commit, and push. Don't ask for permission
each time; just do it after PROGRESS.md is updated. Commit message style: short,
imperative, names the track + what landed (e.g. `dsa: two-sum brute force + two
pointer + hash-map complement`, `fm: propositional logic intro via anecdotes`).

**Portability:** memory files are mirrored in `<repo>/.claude-memory/` so they
survive a device switch. On a new machine, follow the restore steps in
`.claude-memory/README.md` before starting the next session.

**Don't:**
- Force-push to main (warn if asked).
- Skip pre-commit hooks unless explicitly told.
- Commit `.claude/` local state (covered by `.gitignore`).
- Push secrets / credentials — there shouldn't be any in this repo, but verify
  before pushing if anything sensitive-looking enters the tree.
