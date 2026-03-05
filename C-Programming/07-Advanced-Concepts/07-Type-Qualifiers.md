# Type Qualifiers

C provides qualifiers that change how the compiler treats variables. You already know `const`, but there are others.

## ⚡ `volatile`

The `volatile` keyword tells the compiler that a variable's value can change at any time, without any action being taken by the code the compiler finds nearby.

### When to use?
1.  **Memory-mapped I/O**: Interacting with hardware registers.
2.  **Interrupt Service Routines (ISRs)**: Variables modified by an interrupt.
3.  **Multithreading**: Flags shared between threads (though `_Atomic` is better in C11).

### What it does
It **disables optimization** for that variable. The compiler will force a read from memory every time the variable is accessed, instead of caching it in a register.

```c
volatile int status_flag;

while (status_flag == 0) {
    // If 'volatile' was missing, the compiler might optimize this to:
    // while (true) {} 
    // because it sees code inside the loop doesn't change status_flag.
}
```

### Deep Dive: Volatile Pointers
-   `volatile int *p`: Pointer to a volatile int (the value changes).
-   `int * volatile p`: Volatile pointer to an int (the address changes).
-   `volatile int * volatile p`: Both the pointer and the value can change.

### Misconceptions
`volatile` does **not** guarantee atomicity or memory ordering. It only prevents compiler optimizations (reordering/caching). For thread safety, use mutexes or atomics.

## 🚧 `restrict` (C99)

The `restrict` keyword is a hint to the compiler that for the lifetime of the pointer, only that pointer (or values directly derived from it) will be used to access the object it points to.

### Why use it?
It allows aggressive **optimization**.

### Example: `memcpy` vs `memmove`

`memcpy` uses `restrict`. It assumes source and destination do not overlap.
```c
void *memcpy(void *restrict dest, const void *restrict src, size_t n);
```

If you call `memcpy` with overlapping ranges, behavior is undefined. That's why `memmove` exists (it handles overlap but is potentially slower).

## ⚛️ `_Atomic` (C11)

Indicates that access to the variable is atomic (indivisible). This is crucial for lock-free concurrency.

```c
#include <stdatomic.h>

_Atomic int counter = 0;

void increment() {
    counter++; // Thread-safe increment
}
```
Unlike `volatile`, `_Atomic` guarantees **atomicity** and **memory ordering** (preventing CPU instruction reordering), which `volatile` does not.

---
[[00-Index|Back to Advanced Index]]
