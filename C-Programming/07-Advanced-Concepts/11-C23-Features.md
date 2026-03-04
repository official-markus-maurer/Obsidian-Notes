# C23: The New Standard

C23 (ISO/IEC 9899:2024) is the latest major revision of the C language. It removes many obsolete features and adds quality-of-life improvements inspired by C++.

## 🔑 New Keywords
-   `true`, `false`: Now keywords. No need for `<stdbool.h>`.
-   `bool`: Now a keyword (alias for `_Bool`).
-   `alignas`, `alignof`: Alignment specifiers.
-   `static_assert`: Compile-time assertions.
-   `thread_local`: Thread-local storage.
-   `nullptr`: Type-safe null pointer (finally!).

## 🛠️ New Features

### Type Inference (`auto`)
Like C++, `auto` can now infer the type from the initializer.
```c
auto x = 5;      // int
auto y = 3.14;   // double
```
*Note: This reuses the old `auto` keyword which meant "automatic storage duration" (stack variable), but that meaning was almost never used.*

### Binary Literals & Separators
```c
int flags = 0b1010_0011; // Binary with digit separators
```

### `#embed`
Directly embed binary files into your executable.
```c
const unsigned char icon[] = {
    #embed "icon.png"
};
```

### Zero Initialization
```c
struct Point p = {}; // All members set to 0/NULL
```

### `typeof`
Getting the type of an expression.
```c
typeof(x) y = x + 1;
```

## 🗑️ Removed Features
-   **K&R Function Definitions**: `void f(a) int a; {}` is gone.
-   **Trigraphs**: `??=` for `#` is gone.

---
[[00-Index|Back to Advanced Index]]
