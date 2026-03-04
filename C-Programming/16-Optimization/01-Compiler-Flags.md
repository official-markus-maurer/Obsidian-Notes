# Compiler Flags

Modern compilers like GCC and Clang are incredibly smart. They can automatically optimize your code in ways that are hard to do manually.

## 🎚️ Optimization Levels

| Flag | Description |
|---|---|
| `-O0` | **Default**. No optimization. Fastest compilation time. Best for debugging (variables aren't optimized away). |
| `-O1` | Basic optimizations. Code size and execution time reduction. |
| `-O2` | **Recommended for release**. Performs nearly all supported optimizations that do not involve a space-speed tradeoff. |
| `-O3` | Aggressive optimization. May increase binary size (e.g., loop unrolling, function inlining). Can sometimes be buggy or slower due to instruction cache misses. |
| `-Os` | Optimize for **Size**. Enables -O2 optimizations that don't increase code size. Great for embedded systems. |
| `-Ofast` | Disregards strict standard compliance. Example: Fast math (might lose precision). |

## 🔗 Link Time Optimization (LTO)

Normally, the compiler optimizes one file at a time. LTO allows optimization across the entire program during the linking phase.

```bash
gcc -O2 -flto -c main.c
gcc -O2 -flto -c utils.c
gcc -O2 -flto -o app main.o utils.o
```

---
[[00-Index|Back to Optimization Index]]
