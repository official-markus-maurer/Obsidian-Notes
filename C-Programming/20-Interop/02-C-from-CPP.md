# C and C++ Interoperability

C++ is designed to be mostly compatible with C, but they are different languages. C++ supports features like function overloading and namespaces, which change how functions are named in the compiled object file.

## 🛑 The Problem: Name Mangling

In C, a function `void add(int)` is compiled to a symbol named `_add`.
In C++, `void add(int)` might be compiled to `_Z3addi` (to distinguish it from `void add(float)`).

If you try to link a C object file with a C++ object file, the linker will fail because it can't find the mangled name.

## ✅ The Solution: `extern "C"`

Wrap your C declarations in `extern "C"` to tell the C++ compiler: "Treat these functions as C functions (do not mangle names)."

### `mylib.h` (The Header)
This header can be included by both C and C++ files.

```c
#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Function Prototypes
void c_function(int x);
int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
```

### `mylib.c` (Implementation)
Compiled with `gcc` (C Compiler).

```c
#include "mylib.h"

void c_function(int x) { ... }
int add(int a, int b) { ... }
```

### `main.cpp` (C++ Usage)
Compiled with `g++` (C++ Compiler).

```cpp
#include <iostream>
#include "mylib.h" // Safe to include!

int main() {
    c_function(10); // Linker finds _c_function (not mangled)
    return 0;
}
```

## ⚠️ Caveats
-   You cannot use C++ features (classes, templates, references) inside `extern "C"` blocks.
-   You cannot overload functions inside `extern "C"`.

---
[[00-Index|Back to Interop Index]]
