# Intel Intrinsics (SSE/AVX)

Intrinsics are C functions that map directly to assembly instructions. They allow you to write SIMD code without writing raw assembly.

## 📦 Data Types (Header: `<immintrin.h>`)

| Type | Size | Holds |
|---|---|---|
| `__m128` | 128-bit | 4 `float`s |
| `__m128d` | 128-bit | 2 `double`s |
| `__m128i` | 128-bit | Integers (16 chars, 8 shorts, 4 ints, 2 longs) |
| `__m256` | 256-bit | 8 `float`s (AVX) |
| `__m256d` | 256-bit | 4 `double`s (AVX) |

## 🛠️ Naming Convention
`_mm_operation_suffix`

-   **Operation**: `add`, `sub`, `mul`, `div`, `sqrt`, `load`, `store`.
-   **Suffix**:
    -   `ps`: Packed Single (4 floats).
    -   `pd`: Packed Double (2 doubles).
    -   `ss`: Scalar Single (1 float, low part only).
    -   `si128`: Signed Integer 128-bit.

## 🚀 Example: Vector Addition

```c
#include <stdio.h>
#include <immintrin.h> // Includes SSE, SSE2, AVX, etc.

int main() {
    // 16-byte alignment is required for _mm_load_ps (legacy SSE requirement)
    // Using _mm_loadu_ps (unaligned) is safer on modern CPUs with negligible penalty.
    float a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    float result[4];

    // 1. Load data into 128-bit registers (XMM)
    __m128 va = _mm_loadu_ps(a); // Unaligned load
    __m128 vb = _mm_loadu_ps(b);

    // 2. Perform parallel addition
    __m128 vresult = _mm_add_ps(va, vb);

    // 3. Store result back to memory
    _mm_storeu_ps(result, vresult); // Unaligned store

    printf("Result: %.1f %.1f %.1f %.1f\n", 
           result[0], result[1], result[2], result[3]);
    // Output: 6.0 8.0 10.0 12.0

    return 0;
}
```

## ⚡ Performance Tip
Avoid moving data between SIMD registers and standard integer registers (e.g., `_mm_extract_epi32`). It is slow. Try to keep data in SIMD registers as long as possible.

---
[[00-Index|Back to SIMD Index]]
