# Integer Overflows

Integer overflow occurs when an arithmetic operation attempts to create a numeric value that is outside of the range that can be represented with a given number of bits.

## 💥 The Vulnerability

If an integer overflows, it wraps around.

```c
unsigned char x = 255;
x = x + 1; // x becomes 0
```

This is dangerous in **Memory Allocation**:

```c
void *allocate_array(int count) {
    // If count is very large, count * sizeof(int) might wrap around to a small number
    // malloc allocates a small buffer, but we think we have a huge one.
    // Result: Heap Buffer Overflow.
    size_t size = count * sizeof(int); 
    return malloc(size);
}
```

## 🛡️ Prevention

Check for overflow *before* performing the operation.

```c
#include <limits.h>

void *allocate_safe(int count) {
    if (count > INT_MAX / sizeof(int)) {
        return NULL; // Overflow would occur
    }
    return malloc(count * sizeof(int));
}
```

---
[[00-Index|Back to Secure Coding Index]]
