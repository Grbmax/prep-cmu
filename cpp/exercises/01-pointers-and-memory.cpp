// ============================================================================
// C++ 01 — Pointers & Memory — EXERCISES
//
// Rules of engagement:
//   - Write your attempts in cpp/my-solutions/, not here. Keep this file clean.
//   - Compile with warnings on:  g++ -std=c++17 -Wall -Wextra -g your_file.cpp
//   - When stuck, ask me for a hint. I escalate: concept -> structure -> pseudocode.
//     I will not hand you compilable solutions to these.
//
// Each exercise has WHAT TO IMPLEMENT and WHAT TO THINK ABOUT.
// ============================================================================


// ----------------------------------------------------------------------------
// Exercise 1 — swap via pointers
//
// WHAT TO IMPLEMENT:
//   void swap_ints(int* a, int* b);
//   Swaps the two int values that a and b point to (not the pointers themselves).
//   In main(), declare two ints, print them, call swap_ints, print again.
//
// WHAT TO THINK ABOUT:
//   Why must the parameters be pointers (or references) and not plain ints?
//   What would happen to the caller's variables if they were plain ints?
//   Could you write the same thing with references? Which reads cleaner, and why?
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Exercise 2 — find max without copying
//
// WHAT TO IMPLEMENT:
//   const int& max_elem(const std::vector<int>& v);
//   Returns a reference to the largest element of v. Assume v is non-empty.
//
// WHAT TO THINK ABOUT:
//   Why const reference for both the parameter and the return type?
//   What is the lifetime of the thing you return — is it safe to return a
//   reference into v? When would returning a reference be a dangling-reference bug?
//   What should the contract say about an empty vector? (Don't handle it yet —
//   just decide what the precondition is.)
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Exercise 3 — heap-allocated array with correct cleanup
//
// WHAT TO IMPLEMENT:
//   A function that allocates an int array of size n on the heap, fills it with
//   the first n squares (1, 4, 9, ...), returns the pointer. A second function
//   that takes that pointer + size, prints the contents. main() must allocate,
//   use, and correctly release the memory.
//
// WHAT TO THINK ABOUT:
//   Which new pairs with which delete? (Hint: it's the [] form.)
//   Who owns the returned pointer — caller or callee? Make that explicit in your
//   mind before writing. What goes wrong if main() forgets to release? If it
//   releases twice? Run it under: g++ -fsanitize=address  and read the report.
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Exercise 4 — spot and fix the dangling pointer
//
// WHAT TO IMPLEMENT:
//   Below is a BROKEN function (described in comments — do not paste it as-is).
//   Reproduce it, observe the bug, then write a corrected version.
//
//     int* make_counter_start() {
//         int start = 100;
//         return &start;          // <-- this is the bug
//     }
//
//   Write make_counter_start_fixed() that returns a usable int* the caller can
//   read and must release. Then a variant that avoids the heap entirely.
//
// WHAT TO THINK ABOUT:
//   Exactly when does `start` cease to exist? Why might the broken version even
//   "work" sometimes when you run it — and why is that worse than crashing?
//   The two fixes (heap vs return-by-value) have different ownership stories.
//   Which would a senior engineer prefer here, and why?
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Exercise 5 — pointer-to-pointer: append to a dynamic list
//
// WHAT TO IMPLEMENT:
//   void append(int** arr, int* size, int value);
//   `*arr` points to a heap int array of length `*size`. Grow it by one (allocate
//   a new array of size+1, copy old contents, write `value` at the end, free the
//   old array), and update both *arr and *size so the caller sees the new array.
//   Drive it from main(): start from an empty array, append several values, print.
//
// WHAT TO THINK ABOUT:
//   Why int** and not int*? What does the caller actually need updated, and where
//   does that variable live? Draw the boxes-and-arrows: caller's pointer, the old
//   buffer, the new buffer. Where exactly does the old buffer get freed, and is
//   there any window where you've leaked it or lost the only reference to it?
//   (This is the manual version of what std::vector does for you — notice how much
//   bookkeeping it hides.)
// ----------------------------------------------------------------------------
