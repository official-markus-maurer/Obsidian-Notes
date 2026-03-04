# Introduction to SIMD

## 🚀 The Concept

Normally (SISD), to add two arrays:
```c
for (int i = 0; i < 4; i++) {
    c[i] = a[i] + b[i]; // 4 separate additions
}
```

With SIMD:
```c
c = _mm_add_ps(a, b); // 1 instruction adds all 4 elements at once!
```

## 🖥️ Architecture Support

### x86 (Intel/AMD)
-   **MMX**: Ancient, integer only.
-   **SSE (Streaming SIMD Extensions)**: 128-bit registers (4 floats).
-   **AVX (Advanced Vector Extensions)**: 256-bit registers (8 floats).
-   **AVX-512**: 512-bit registers (16 floats).

### ARM
-   **NEON**: 128-bit registers.

---
[[00-Index|Back to SIMD Index]]
