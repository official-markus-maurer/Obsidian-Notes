# Variadic Functions Internals (x86-64)

How does `va_arg` actually work? It depends heavily on the **Calling Convention**.

## 🌍 The System V AMD64 ABI (Linux/macOS)

Remember that arguments are passed in registers (`RDI`, `RSI`, `RDX`...) and then on the stack.
For variadic functions, things get complicated because the compiler doesn't know how many arguments there are or their types.

### Register Spill Area
When a variadic function is called:
1.  **Floating Point Args**: `XMM0` - `XMM7` are dumped into a "Register Save Area" on the stack.
2.  **Integer Args**: `RDI` - `R9` are dumped into the same area.

The `va_list` structure (typedef'd as an array of 1 struct) keeps track of offsets into this area.

```c
typedef struct {
    unsigned int gp_offset; // Offset for general purpose regs
    unsigned int fp_offset; // Offset for floating point regs
    void *overflow_arg_area; // Stack arguments
    void *reg_save_area;     // Register save area
} va_list[1];
```

### The Logic of `va_arg`
When you call `va_arg(ap, int)`:
1.  Check `gp_offset`.
2.  If `gp_offset < 48` (6 regs * 8 bytes):
    -   Fetch value from `reg_save_area + gp_offset`.
    -   Increment `gp_offset` by 8.
3.  Else:
    -   Fetch value from `overflow_arg_area` (Stack).
    -   Increment `overflow_arg_area` pointer.

This explains why `va_list` is complex and why you can't just cast it to `void**`.

## 🪟 Windows x64 ABI

Windows is much simpler.
-   First 4 args in registers (`RCX`, `RDX`, `R8`, `R9`).
-   Rest on stack.
-   The caller reserves "Shadow Space" (32 bytes) on the stack.

The callee (variadic function) simply dumps the 4 registers into the Shadow Space. Now **all** arguments are contiguous in memory!
`va_list` is just a pointer (`char*`). `va_arg` just increments the pointer.

## ⚠️ Type Promotion
Because the CPU works with words (64-bit on x64), smaller types are promoted.
-   `char`, `short` -> `int` (or `long`).
-   `float` -> `double`.

This is why `va_arg(ap, char)` is illegal. You must ask for `va_arg(ap, int)`.

---
[[00-Index|Back to Functions Index]]
