# Preprocessor Directives

The preprocessor is a tool that processes the source code before it is compiled. Directives start with a hash symbol (`#`).

## 📦 Macros (`#define`)
Used to define constants or macro functions.

```c
#define PI 3.14159
#define MAX(a,b) ((a) > (b) ? (a) : (b))

printf("Area: %f\n", PI * r * r);
printf("Max: %d\n", MAX(10, 20));
```

## 📂 File Inclusion (`#include`)
- `#include <file>`: Looks in standard system directories.
- `#include "file"`: Looks in the current directory first.

## ❓ Conditional Compilation
Used to compile code selectively.

```c
#ifdef DEBUG
    printf("Debug mode is on.\n");
#endif

#ifndef HEADER_FILE_H
#define HEADER_FILE_H
    // Content of header file
#endif
```
This is commonly used for "include guards" in header files to prevent multiple inclusion.

---
[[00-Index|Back to Advanced Index]]
