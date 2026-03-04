# Header Files Best Practices

Header files are the interface to your code. They should declare *what* your code does, not *how* it does it.

## 1. Include Guards
Every header file MUST have an include guard to prevent redefinition errors.

**The Old Way (Standard C):**
```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// Declarations...

#endif
```

**The Modern Way (Widely Supported):**
```c
#pragma once

// Declarations...
```
`#pragma once` is less error-prone (no copy-paste errors with macro names) and supported by GCC, Clang, and MSVC.

## 2. What Goes in a Header?
-   **Function Prototypes**: `void my_func(int a);`
-   **Struct Definitions**: `typedef struct { ... } MyStruct;` (if public)
-   **Macros/Constants**: `#define MAX_SIZE 100`
-   **Extern Variables**: `extern int global_config;` (Use sparingly!)

## 3. What Does NOT Go in a Header?
-   **Function Implementations**: `void f() { ... }` (Unless `static inline`)
-   **Variable Definitions**: `int count = 0;` (Causes "multiple definition" errors)

## 4. Self-Containment
A header file should include everything it needs to compile.
If `my_header.h` uses `uint32_t`, it must `#include <stdint.h>`. Do not force the user to include dependencies manually.

---
[[00-Index|Back to Index]] | [[03-Opaque-Pointers|Next: Opaque Pointers]]
