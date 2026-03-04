# Sanitizers

Sanitizers are compiler instrumentation tools that detect bugs at runtime with minimal overhead (compared to Valgrind). They are built into Clang and GCC.

## 🕵️ AddressSanitizer (ASan)
Detects memory errors: out-of-bounds accesses (heap, stack, global), use-after-free, memory leaks.

**Usage**:
```bash
gcc -fsanitize=address -g main.c -o main
./main
```
If your program crashes or leaks, ASan prints a detailed stack trace showing exactly where the memory error occurred (e.g., "READ of size 4 at 0x...").

## 👻 UndefinedBehaviorSanitizer (UBSan)
Detects undefined behavior that might otherwise be silent or cause random bugs:
-   Signed integer overflow.
-   Shifting by negative numbers.
-   Dereferencing null pointers.
-   Division by zero.

**Usage**:
```bash
gcc -fsanitize=undefined -g main.c -o main
```

## 🧵 ThreadSanitizer (TSan)
Detects data races in multi-threaded code (two threads accessing the same memory without a lock, where at least one is a write).

**Usage**:
```bash
gcc -fsanitize=thread -g main.c -o main
```

> **Note**: TSan and ASan are generally incompatible. Run them in separate test passes.

## 💾 MemorySanitizer (MSan)
Detects reads of uninitialized memory. (Clang only, Linux only).

**Usage**:
```bash
clang -fsanitize=memory -g main.c -o main
```

## 💡 Best Practices
Enable ASan and UBSan in your **Debug** builds and CI pipelines. They catch 90% of common C bugs automatically.

---
[[00-Index|Back to Modern Tooling Index]]
