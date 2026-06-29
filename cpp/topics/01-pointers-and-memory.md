# C++ 01 — Pointers, Memory, References

You knew this once. This is the reload, not the intro. The goal is to rebuild the
mental model of *where bytes live* and *who owns them*, because every C++ bug you
will hit for the next month traces back to one of those two questions.

## 1. The two regions that matter

**Stack** — automatic storage. Function-local variables live here. Allocation is a
pointer bump; deallocation is automatic when the variable goes out of scope (the
stack frame pops). Fast, LIFO, bounded (typically ~1–8 MB). You never call anything
to manage it.

```cpp
void f() {
    int x = 42;        // x lives on the stack
    int arr[1000];     // also stack — 4000 bytes in this frame
}                      // x and arr destroyed here, automatically
```

**Heap** (free store) — dynamic storage. You explicitly request memory with `new`
(or `malloc` in C), and it lives until you explicitly release it with `delete`
(or `free`). Large, slow-ish, and *yours to manage*. Forgetting to release = leak.
Releasing twice or using after release = undefined behavior.

```cpp
int* p = new int(42);  // 4 bytes on the heap; p (on stack) holds its address
delete p;              // release. p is now dangling — don't deref it.
```

The single most important sentence: **a pointer variable lives on the stack; what it
points to may live anywhere.** Confusing the pointer with the pointee is the root of
most memory bugs.

## 2. Pointers — the mechanics you forgot

A pointer is a variable whose value is an address.

```cpp
int x = 10;
int* p = &x;   // & = "address of"; p now holds the address of x
*p = 20;       // * = "dereference"; writes through p; x is now 20
```

- `int*` — pointer to int.
- `&x` — address-of x (an `int*`).
- `*p` — the int stored at the address in p (an lvalue you can read or write).
- `nullptr` — the typed null pointer. Use it, never `NULL` or `0` in modern C++.

Pointer arithmetic is in units of the pointed-to type, not bytes:

```cpp
int a[3] = {1, 2, 3};
int* p = a;     // arrays decay to a pointer to their first element
*(p + 1);       // == a[1] == 2  (advances 4 bytes, not 1)
```

`p[i]` is *defined as* `*(p + i)`. That equivalence is why C arrays and pointers feel
interchangeable — and why off-by-one indexing walks off the end silently.

## 3. References — pointers with training wheels removed

A reference is an alias for an existing object. Not a separate object, no own address
you manipulate, cannot be null, cannot be reseated after binding.

```cpp
int x = 10;
int& r = x;    // r IS x, another name for it
r = 20;        // x is now 20
```

When to use which:
- **Reference** — when the thing must always refer to a valid object and never change
  what it refers to. Default choice for function parameters you don't want to copy.
- **Pointer** — when it can be null, can be reseated, or you need pointer arithmetic /
  ownership semantics.

Pass-by-reference to avoid copies and to mutate:

```cpp
void grow(std::vector<int>& v) { v.push_back(1); }   // mutates caller's vector
void read(const std::vector<int>& v) { /* ... */ }   // no copy, read-only
```

`const T&` is the workhorse parameter type for "big, read-only, no copy."

## 4. const and pointers — read right-to-left

```cpp
const int* p;        // pointer to const int   — can't change *p, can reseat p
int* const p = &x;   // const pointer to int   — can change *p, can't reseat p
const int* const p;  // const pointer to const int — neither
```

Read the declaration right-to-left from the variable name. `int* const p` → "p is a
const pointer to int."

## 5. The bug catalogue (this is where you'll actually spend time)

**Dangling pointer / use-after-free** — pointing at memory that's already freed or
out of scope.

```cpp
int* bad() {
    int x = 5;
    return &x;   // returns address of a stack variable that dies on return. UB.
}
```

**Memory leak** — heap allocation never released. No crash, just growing RSS.

```cpp
void leak() {
    int* p = new int[1000];
    // forgot delete[] — 4000 bytes lost every call
}
```

**Double free** — `delete` the same pointer twice → heap corruption.

**Mismatched new/delete** — `new[]` must pair with `delete[]`, `new` with `delete`.
Mixing them is UB.

**Uninitialized pointer** — a pointer with garbage address; dereferencing it reads or
writes a random location.

```cpp
int* p;     // garbage
*p = 5;     // UB — writes who-knows-where
```

**Buffer overrun** — indexing past an array's bounds. Silent corruption, not a
guaranteed crash.

## 6. Why raw new/delete is legacy in modern C++

Manual `new`/`delete` is error-prone, so modern C++ wraps ownership in types whose
destructors release automatically — this is **RAII** (Resource Acquisition Is
Initialization). You'll get a full topic on it, but the headline:

- `std::unique_ptr<T>` — sole owner; frees on scope exit; move-only.
- `std::shared_ptr<T>` — shared ownership via reference count; frees when count hits 0.
- `std::vector<T>` — owns a heap buffer for you; no manual free ever.

Rule of thumb for the modern grind: **you should rarely type `new` or `delete`.**
When you do (in the C-systems track), you do it deliberately and pair it immediately.

## 7. The mental checklist for any pointer you see

1. What does it point to, and on which region (stack/heap/static) does that live?
2. Who owns it — i.e., whose job is it to free it, and when?
3. Can it be null here? Is that checked?
4. Could the pointee outlive or under-live the pointer?

If you can answer those four for every pointer in a function, you don't have memory
bugs. The exercises in `cpp/exercises/01-pointers-and-memory.cpp` force exactly this.
