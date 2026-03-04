# Intel Intrinsics (SSE/AVX)

To use SIMD in C, we include `<immintrin.h>`.

## 📦 Data Types

-   `__m128`: 128-bit vector containing 4 `float`s.
-   `__m128d`: 128-bit vector containing 2 `double`s.
-   `__m128i`: 128-bit vector containing integers (char, short, int, long).
-   `__m256`: 256-bit vector (AVX) containing 8 `float`s.

## 🛠️ Example: Vector Addition

```c
#include <stdio.h>
#include <immintrin.h> // Includes all SSE/AVX headers

int main() {
    // Must be 16-byte aligned for older SSE versions
    float a[4] __attribute__((aligned(16))) = {1.0, 2.0, 3.0, 4.0};
    float b[4] __attribute__((aligned(16))) = {5.0, 6.0, 7.0, 8.0};
    float result[4] __attribute__((aligned(16)));

    // 1. Load data into registers
    __m128 va = _mm_load_ps(a);
    __m128 vb = _mm_load_ps(b);

    // 2. Perform addition
    __m128 vresult = _mm_add_ps(va, vb);

    // 3. Store result back to memory
    _mm_store_ps(result, vresult);

    printf("Result: %f %f %f %f\n", result[0], result[1], result[2], result[3]);
    // Output: 6.0 8.0 10.0 12.0

    return 0;
}
```

## 📝 Naming Convention
`_mm_op_suffix`
-   `op`: `add`, `sub`, `mul`, `div`, `sqrt`...
-   `suffix`:
    -   `ps`: Packed Single-precision (4 floats)
    -   `pd`: Packed Double-precision (2 doubles)
    -   `ss`: Scalar Single (only 1 float)

---
[[00-Index|Back to SIMD Index]]
