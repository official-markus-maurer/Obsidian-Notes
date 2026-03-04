# Sanitizers

Sanitizers are compiler instrumentation tools that detect bugs at runtime with minimal overhead (compared to Valgrind).

## 🕵️ AddressSanitizer (ASan)
Detects memory errors: out-of-bounds accesses, use-after-free, memory leaks.

**Usage**:
```bash
gcc -fsanitize=address -g main.c -o main
./main
```
If your program crashes or leaks, ASan prints a beautiful stack trace showing exactly where the memory error occurred.

## 👻 UndefinedBehaviorSanitizer (UBSan)
Detects undefined behavior: integer overflows, shifting by negative numbers, null pointer dereferences.

**Usage**:
```bash
gcc -fsanitize=undefined -g main.c -o main
```

## 🧵 ThreadSanitizer (TSan)
Detects data races in multi-threaded code.

**Usage**:
```bash
gcc -fsanitize=thread -g main.c -o main
```

> **Note**: You usually cannot mix TSan with ASan. Use them in separate test runs.

---
[[00-Index|Back to Modern Tooling Index]]
