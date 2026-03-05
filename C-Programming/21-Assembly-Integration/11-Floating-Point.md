# Floating Point Assembly (x86-64)

While General Purpose Registers (`RAX`, `RBX`) handle integers, floating-point math uses the **SSE (Streaming SIMD Extensions)** registers: `XMM0` through `XMM15`.

## 📦 The XMM Registers

-   Each `XMM` register is **128 bits** wide.
-   **Scalar Operations**: Use only the lower 32 bits (float) or 64 bits (double).
-   **Packed Operations**: Use the full 128 bits (SIMD) to process multiple values at once.

## 🔢 Scalar Instructions (Single Value)

These instructions operate on one `float` or `double` at a time.
Suffixes: `SS` = Scalar Single (float), `SD` = Scalar Double (double).

### Data Movement
-   `MOVSS xmm0, [mem]`: Load 32-bit float.
-   `MOVSD xmm0, [mem]`: Load 64-bit double.
-   `MOVAPS xmm0, [mem]`: Load 128-bit aligned data (Packed).

### Arithmetic
-   `ADDSS xmm0, xmm1`: Add float in xmm1 to xmm0.
-   `ADDSD xmm0, xmm1`: Add double.
-   `SUBSS`, `MULSS`, `DIVSS`: Subtract, Multiply, Divide (floats).
-   `SQRTSS`: Square Root.

### Comparison
-   `UCOMISS xmm0, xmm1`: Unordered Compare Scalar Single.
    -   Sets `ZF`, `PF`, `CF` flags similar to `CMP`.
    -   Use standard jumps (`JA`, `JB`, `JE`) afterwards.

## 🔄 Conversions (Casts)

-   `CVTSI2SS xmm0, rax`: Convert Signed Integer (in RAX) to Scalar Single (in XMM0).
-   `CVTSS2SI rax, xmm0`: Convert Scalar Single to Signed Integer (with truncation).

## 🌍 Calling Convention (System V ABI)

Floating point arguments are passed in `XMM` registers, not `RDI`/`RSI`.

| Argument | Register |
| :--- | :--- |
| **Arg 1** | `XMM0` |
| **Arg 2** | `XMM1` |
| ... | ... |
| **Arg 8** | `XMM7` |
| **Return Value** | `XMM0` |

### Varargs (printf)
When calling a variadic function like `printf`, `AL` (part of RAX) must contain the **number of XMM registers used**.
```asm
mov rax, 1          ; 1 float argument used
movsd xmm0, [pi]    ; Load double
mov rdi, fmt        ; Load format string
call printf
```

---
[[00-Index|Back to Assembly Index]]
