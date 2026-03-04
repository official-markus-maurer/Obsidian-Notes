# Compiler Intrinsics

Intrinsics are special functions provided by the compiler that map directly to assembly instructions. They are safer and more readable than inline assembly.

## 🧰 Common GCC/Clang Built-ins

### Bit Manipulation

```c
#include <stdio.h>

int main() {
    unsigned int x = 0b10110;

    // Count Set Bits (Population Count)
    // Maps to POPCNT instruction on modern x86
    int ones = __builtin_popcount(x); 
    printf("Set bits: %d\n", ones); // Output: 3

    // Count Trailing Zeros
    // Maps to TZCNT / BSF
    int trailing = __builtin_ctz(x);
    printf("Trailing zeros: %d\n", trailing); // Output: 1 (for 0...10)

    // Count Leading Zeros
    // Maps to LZCNT / BSR
    int leading = __builtin_clz(x);
    printf("Leading zeros: %d\n", leading);
    
    return 0;
}
```

### Branch Prediction
```c
if (__builtin_expect(x > 0, 1)) {
    // Likely path
}
```

### Prefetching
```c
__builtin_prefetch(&array[i+10]); // Hint CPU to load future data into cache
```

---
[[00-Index|Back to Assembly Index]]
