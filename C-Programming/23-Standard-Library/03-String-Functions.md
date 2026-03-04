# String Optimization Techniques

The standard library string functions (`strlen`, `strcpy`, `memcpy`) are heavily optimized. Understanding how they work can help you write faster code.

## 🚀 Word-at-a-Time Processing

A naive `strlen` checks one byte at a time:

```c
size_t naive_strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}
```

**Optimized `strlen`** reads **8 bytes (64 bits) at a time** (on a 64-bit CPU). It uses bitwise magic to detect if any of those 8 bytes is a null terminator `0`.

### The Magic Formula (Simplification)
To check if a 64-bit word `v` contains a zero byte:
```c
has_zero_byte = (v - 0x0101010101010101UL) & ~v & 0x8080808080808080UL;
```

## 🏎️ `memcpy` vs `memmove`

-   **`memcpy`**: Assumes non-overlapping memory. It can use SIMD (AVX/SSE) to copy 32 or 64 bytes per instruction.
-   **`memmove`**: Handles overlap. It checks the direction of the copy (start-to-end or end-to-start) to prevent overwriting source data.

## 💡 Best Practices
1.  **Prefer `memcpy`** over loops. The compiler/library version is likely faster than anything you write.
2.  **Use `memchr`** to find a character in a block of memory (it's vectorized).

---
[[00-Index|Back to Stdlib Index]]
