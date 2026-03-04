# Integer Overflows

Integer overflow occurs when an arithmetic operation attempts to create a numeric value that is outside of the range that can be represented with a given number of bits.

## 💥 The Vulnerability

### Unsigned Overflow
Unsigned integers wrap around modulo 2^N. This is defined behavior in C.
```c
unsigned char x = 255;
x = x + 1; // x becomes 0
```

### Signed Overflow
Signed integer overflow is **Undefined Behavior (UB)** in C. The compiler can assume it never happens and optimize away checks!
```c
int x = INT_MAX;
x = x + 1; // UB! Might wrap to negative, might trap, might delete your hard drive.
```

### Allocation Hazards
Overflow is dangerous in `malloc` size calculations.

```c
void *allocate_array(size_t count) {
    // If count is huge, count * 4 might wrap to a small number (e.g., 4)
    // malloc(4) succeeds, but we write huge data -> Heap Buffer Overflow
    size_t size = count * sizeof(int); 
    return malloc(size);
}
```

## 🛡️ Prevention

### 1. Manual Checks
Check *before* the operation.

```c
#include <limits.h>

void *allocate_safe(size_t count) {
    if (count > SIZE_MAX / sizeof(int)) {
        return NULL; // Overflow would occur
    }
    return malloc(count * sizeof(int));
}
```

### 2. Compiler Builtins (GCC/Clang)
Modern compilers provide built-in functions that return true on overflow.

```c
size_t a = ...;
size_t b = ...;
size_t res;

if (__builtin_mul_overflow(a, b, &res)) {
    // Handle overflow
} else {
    // Use result
}
```

### 3. Safe Math Libraries
Use libraries like SafeInt (C++) or similar wrappers in C.

---
[[00-Index|Back to Secure Coding Index]]
