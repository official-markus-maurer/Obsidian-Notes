# Type Qualifiers

C provides qualifiers that change how the compiler treats variables. You already know `const`, but there are others.

## ⚡ `volatile`

The `volatile` keyword tells the compiler that a variable's value can change at any time, without any action being taken by the code the compiler finds nearby.

### When to use?
1.  **Memory-mapped I/O**: Interacting with hardware registers.
2.  **Interrupt Service Routines (ISRs)**: Variables modified by an interrupt.
3.  **Multithreading**: Flags shared between threads (though `atomic` is better in C11).

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

---
[[00-Index|Back to Advanced Index]]
