# Header Files Best Practices

Header files (`.h`) are the public API of your module. They define *what* your code can do, while source files (`.c`) define *how* it does it.

## 1. Include Guards
Every header file MUST have an include guard to prevent "redefinition" errors if included multiple times.

**The Modern Way:**
```c
#pragma once
```
Supported by all major compilers (GCC, Clang, MSVC).

**The Standard Way (Portable):**
```c
#ifndef MYLIB_UTILS_H
#define MYLIB_UTILS_H

// Declarations...

#endif
```

## 2. What Goes in a Header?
-   **Function Prototypes**: `void my_func(int a);`
-   **Public Structs**: `typedef struct { int x, y; } Point;`
-   **Macros/Constants**: `#define MAX_BUFFER 1024`
-   **Extern Variables**: `extern int global_config;` (Use sparingly!)

## 3. What Does NOT Go in a Header?
-   **Function Implementations**: `void f() { ... }` (Unless `static inline`)
-   **Variable Definitions**: `int count = 0;` (Causes linker errors)
-   **Private Helpers**: Functions only used inside one `.c` file should be `static` in that `.c` file, not in the header.

## 4. Forward Declarations (Reduce Dependencies)
If a header only uses a pointer to a struct, you don't need the full definition. Use a forward declaration to avoid `#include` chains.

**Bad (`user.h`):**
```c
#include "database.h" // Dragging in huge dependency
void process_user(struct Database *db);
```

**Good (`user.h`):**
```c
struct Database; // Forward declaration
void process_user(struct Database *db);
```
*In `user.c`, you include `database.h` to use the members.*

## 5. Self-Containment
A header should compile on its own. If `my_header.h` uses `uint32_t`, it **must** include `<stdint.h>`. Do not force the user to include dependencies manually.

---
[[00-Index|Back to Index]] | [[03-Opaque-Pointers|Next: Opaque Pointers]]
