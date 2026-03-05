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

## 🪄 Advanced Features

### 1. Stringification (`#`)
Converts a macro argument into a string literal.

```c
#define PRINT_INT(x) printf(#x " = %d\n", x)

int count = 42;
PRINT_INT(count);
// Expands to: printf("count" " = %d\n", count);
// Output: count = 42
```

### 2. Token Pasting (`##`)
Concatenates two tokens into one. Useful for generating variable names.

```c
#define DECLARE_STRUCT(type) struct type##_s { type value; };

DECLARE_STRUCT(int);
// Expands to: struct int_s { int value; };
```

### 3. Variadic Macros (`...` and `__VA_ARGS__`)
Macros that accept a variable number of arguments (C99).

```c
#define LOG(fmt, ...) printf("[LOG] " fmt "\n", __VA_ARGS__)

LOG("Value: %d", 10);
// Expands to: printf("[LOG] " "Value: %d" "\n", 10);
```

### 4. X-Macros
A technique to maintain parallel lists of data (e.g., Enum + String Array) without duplication.

**Define the data:**
```c
#define COLORS \
    X(RED)     \
    X(GREEN)   \
    X(BLUE)
```

**Generate Enum:**
```c
#define X(name) name,
enum Color { COLORS };
#undef X
// Expands to: enum Color { RED, GREEN, BLUE, };
```

**Generate Strings:**
```c
#define X(name) #name,
const char *ColorNames[] = { COLORS };
#undef X
// Expands to: const char *ColorNames[] = { "RED", "GREEN", "BLUE", };
```

### 5. Generic Selection (`_Generic`) (C11)
Allows function overloading based on argument type. This is how `tgmath.h` works.

```c
#define print(x) _Generic((x), \
    int: print_int, \
    double: print_double, \
    default: print_unknown \
)(x)

void print_int(int x) { printf("Int: %d\n", x); }
void print_double(double x) { printf("Double: %f\n", x); }
void print_unknown(...) { printf("Unknown type\n"); }

int main() {
    print(10);      // Calls print_int
    print(3.14);    // Calls print_double
}
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
