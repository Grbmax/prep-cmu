---
name: feedback-pacing
description: "How to pace and pitch explanations for this student — small chunks, no unexplained jargon, verify before assuming knowledge"
metadata: 
  node_type: memory
  type: feedback
  originSessionId: e0d15d00-bcb1-423e-83c0-f544f750e5f8
---

Teach in small chunks and check understanding before continuing. Do NOT firehose
dense, multi-section explanations — the student found that hard to absorb.

**Why:** Student has a CS background but has been away from C++ / CS fundamentals for
~4-5 years. Recall is rusty; dense walls of text with many concepts stacked at once
cause overwhelm rather than learning. They explicitly asked to "take a different
approach" after two long, dense messages.

**How to apply:**
- One concept at a time. Pause and check ("does that land? want an example?") before
  moving on. Don't pre-load 6 related ideas.
- Do NOT assume the student knows a concept unless they say they do. Ask.
- Avoid shortforms / abbreviations / acronyms unless you've already defined them with
  this student (e.g. spell out "undefined behavior" before using "UB", define "RAII"
  before reusing it). When introducing a necessary term, define it in plain words once.
- Peer-level and honest is still right (see CLAUDE.md tone), but density must come
  DOWN. Fewer words, verified before advancing. Information-per-sentence is good;
  sentences-per-message should be low.
- Relates to the non-spoonfeed rule in [[student-profile]] — go slow, but still make
  them do the thinking; slower pace is not the same as giving answers.
