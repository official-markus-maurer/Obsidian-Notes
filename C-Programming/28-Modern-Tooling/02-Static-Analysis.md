# Static Analysis

Static analysis tools check your code *without running it*. They find bugs, style violations, and "code smells".

## 🧹 Clang-Tidy
Part of the LLVM project. It acts like a super-linter.

**Checks**:
-   `cert-*`: CERT Secure Coding standards.
-   `readability-*`: Code readability improvements.
-   `bugprone-*`: Likely bugs.

**Usage**:
```bash
clang-tidy main.c -- -Iinclude
```

## 🔍 Cppcheck
A fast, dedicated static analyzer for C/C++.

**Features**:
-   Detects uninitialized variables.
-   Detects unused functions.
-   Detects buffer overruns (statically).

**Usage**:
```bash
cppcheck --enable=all main.c
```

---
[[00-Index|Back to Modern Tooling Index]]
