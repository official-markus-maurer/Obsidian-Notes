# Introduction to SIMD

SIMD (Single Instruction, Multiple Data) is a hardware feature that allows a single CPU instruction to process multiple data points simultaneously. This is the key to high-performance computing (graphics, physics, AI, audio processing).

## 🚀 The Concept: Vectorization

Normally (Scalar / SISD), to add two arrays of 4 floats:
```c
// Requires 4 separate 'add' instructions
for (int i = 0; i < 4; i++) {
    c[i] = a[i] + b[i]; 
}
```

With SIMD:
```c
// Requires 1 'vector add' instruction
// Load 4 floats into register A
// Load 4 floats into register B
// Add A + B -> C (Parallel)
c = _mm_add_ps(a, b); 
```
This can result in a **4x speedup** (theoretically) for float operations.

## 🖥️ Architecture Support

### x86 (Intel/AMD)
1.  **SSE (Streaming SIMD Extensions)**:
    -   128-bit registers (`XMM0` - `XMM15`).
    -   Holds 4 `float`s, 2 `double`s, or 16 `char`s.
    -   Supported on almost all modern CPUs.
2.  **AVX (Advanced Vector Extensions)**:
    -   256-bit registers (`YMM0` - `YMM15`).
    -   Holds 8 `float`s or 4 `double`s.
3.  **AVX-512**:
    -   512-bit registers (`ZMM`).
    -   Holds 16 `float`s. (Server/High-end Desktop only).

### ARM
-   **NEON**: 128-bit registers. Standard on mobile and Apple Silicon.

## ⚠️ Challenges
-   **Alignment**: Data often needs to be aligned (e.g., 16-byte boundary for SSE).
-   **Complexity**: Writing SIMD code manually (intrinsics) is hard and verbose.
-   **Portability**: SSE code won't run on ARM. You need conditional compilation or a wrapper library (like `simde`).

---
[[00-Index|Back to SIMD Index]]
