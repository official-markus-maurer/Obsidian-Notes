# Preprocessor Directives

The preprocessor is a text substitution tool that runs **before** the compiler. All directives start with `#`.

## 📦 Macros (`#define`)

### Constants
Replaces all occurrences of `PI` with `3.14159`.
```c
#define PI 3.14159
```

### Function-like Macros
**Warning**: Always use parentheses around arguments to prevent operator precedence issues.
```c
// Bad: #define SQUARE(x) x * x
// Good:
#define SQUARE(x) ((x) * (x))

int a = 5;
int result = SQUARE(a + 1); 
// Expands to: ((a + 1) * (a + 1)) -> 36
// Bad version: a + 1 * a + 1 -> 5 + 5 + 1 -> 11 (Wrong!)
```

### Pitfalls
Avoid side effects in arguments.
```c
SQUARE(i++); // Expands to ((i++) * (i++)) -> Undefined Behavior!
```

## 📂 File Inclusion (`#include`)
-   `#include <stdio.h>`: Searches system directories (e.g., `/usr/include`).
-   `#include "myheader.h"`: Searches the current directory first.

## ❓ Conditional Compilation
Used to compile code selectively (e.g., for cross-platform compatibility).

```c
#ifdef _WIN32
    #include <windows.h>
#elif defined(__linux__)
    #include <unistd.h>
#else
    #error "OS not supported!"
#endif
```

## 🛡️ Include Guards
Prevents a header file from being included multiple times, which causes "redefinition" errors.

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

struct Point { int x, y; };

#endif
```
*Modern alternative*: `#pragma once` (supported by most compilers but not standard C).

## 🔧 Predefined Macros
Useful for debugging and logging.
-   `__FILE__`: Current file name (string).
-   `__LINE__`: Current line number (int).
-   `__DATE__`: Compilation date.
-   `__func__` (C99): Current function name.

```c
printf("Error in %s at line %d: %s\n", __FILE__, __LINE__, __func__);
```

---
[[00-Index|Back to Advanced Index]]
