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

## 🚀 Architecture Specific

Tell the compiler to use instructions specific to your CPU (e.g., AVX2).

```bash
gcc -O2 -march=native -o app main.c
```
-   **`-march=native`**: Optimize for the CPU of the machine compiling the code.
-   **`-mtune=generic`**: Optimize for common CPUs (good for distributing binaries).

## 🛠️ Debugging Flags

-   **`-g`**: Include debug symbols (line numbers, variable names) for GDB/LLDB.
-   **`-ggdb3`**: Include extra debug info for GDB macros.
-   **`-fno-omit-frame-pointer`**: Keeps the frame pointer register (`ebp`/`rbp`) intact. Essential for accurate stack traces and profiling (perf).

## ⚠️ Warning Flags (Enable ALL of them)

Catch bugs before they happen.

```bash
gcc -Wall -Wextra -Wpedantic -Werror ...
```
-   **`-Wall`**: All common warnings.
-   **`-Wextra`**: Even more warnings.
-   **`-Wpedantic`**: Enforce strict ISO C compliance.
-   **`-Werror`**: Treat warnings as errors (stops compilation).

## 🔗 Link Time Optimization (LTO)

Normally, the compiler optimizes one file at a time. LTO allows optimization across the entire program during the linking phase.

```bash
gcc -O2 -flto -c main.c
gcc -O2 -flto -c utils.c
gcc -O2 -flto -o app main.o utils.o
```

---
[[00-Index|Back to Optimization Index]]
