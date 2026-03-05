# Compiler Intrinsics

Intrinsics are C functions provided by the compiler (GCC, Clang, MSVC) that map directly to specific CPU instructions. They are safer, more portable, and easier to read than inline assembly.

## 🧰 Bit Manipulation (`__builtin_`)

Use these instead of manual bit-twiddling loops. They map to hardware instructions like `POPCNT`, `LZCNT`, `TZCNT` on x86.

```c
#include <stdio.h>

int main() {
    unsigned int x = 0b10110;

    // Count Set Bits (Population Count)
    // Hardware: POPCNT
    int ones = __builtin_popcount(x); 
    printf("Set bits: %d\n", ones); // Output: 3

    // Count Trailing Zeros
    // Hardware: BSF / TZCNT
    int trailing = __builtin_ctz(x);
    printf("Trailing zeros: %d\n", trailing); // Output: 1

    // Count Leading Zeros
    // Hardware: BSR / LZCNT
    // Useful for finding highest set bit (MSB)
    int leading = __builtin_clz(x);
    printf("Leading zeros: %d\n", leading);
    
    // Parity (Returns 1 if odd number of set bits)
    int parity = __builtin_parity(x);
    printf("Parity: %d\n", parity);

    return 0;
}
```

## ⚛️ Atomic Operations (`__atomic_`)

Use these for lock-free concurrency. They map to instructions with the `LOCK` prefix (e.g., `LOCK XADD`).

```c
int counter = 0;

// Fetch and Add (Atomic Increment)
// Returns OLD value
int old_val = __atomic_fetch_add(&counter, 1, __ATOMIC_SEQ_CST);

// Compare and Swap (CAS)
// If counter == expected, set it to desired.
int expected = 5;
int desired = 10;
bool success = __atomic_compare_exchange_n(&counter, &expected, desired, 
                                           false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
```

## 🚀 Optimization Hints

### Branch Prediction (`__builtin_expect`)
Tell the compiler which branch is more likely to be taken.

```c
// Likely
if (__builtin_expect(ptr != NULL, 1)) {
    // fast path
}

// Unlikely (Error handling)
if (__builtin_expect(error_code != 0, 0)) {
    // slow path
}
```
*Note: In C++20, use `[[likely]]` and `[[unlikely]]` attributes instead.*

### Prefetching (`__builtin_prefetch`)
Hint the CPU to load data into cache before it's needed.

```c
// Prefetch data at address for reading (0) with low locality (0-3)
__builtin_prefetch(&array[i+16], 0, 1);
```

---
[[00-Index|Back to Assembly Index]]
