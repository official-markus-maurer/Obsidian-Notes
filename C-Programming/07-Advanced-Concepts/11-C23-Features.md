# C23 Features

C23 is the latest standard of the C programming language (ISO/IEC 9899:2024). It modernizes the language, removing obsolete features and adopting conveniences from C++.

## 🧹 Removed / Deprecated
-   **K&R Function Declarations**: `int func(a, b) int a, b; { ... }` is finally dead.
-   **Trigraphs**: `??=` replaced by `#`.
-   **`#include <stdnoreturn.h>`**: The `noreturn` keyword is now an attribute.

## 🆕 Keywords & Attributes

### `nullptr`
A type-safe null pointer constant (like in C++). Replaces `NULL`.
`NULL` is typically `(void*)0` or `0`, which can behave unexpectedly in generic macros. `nullptr` is of type `nullptr_t`.

```c
void* ptr = nullptr;
```

### `constexpr`
Defines variables that are constant *at compile time*.
Unlike `const` (which is read-only at runtime), `constexpr` can be used in array sizes and static assertions.

```c
constexpr int max_size = 100;
int buffer[max_size]; // Valid
```

### `auto` (Type Inference)
Allows the compiler to infer the type of a variable from its initializer.

```c
auto x = 10;        // int
auto y = 3.14;      // double
auto ptr = &x;      // int*
```
*Note: This is strictly type inference, not dynamic typing.*

### `bool`, `true`, `false`
Native keywords! You no longer need `#include <stdbool.h>`.

## 🏷️ Standard Attributes (`[[...]]`)

Standardized syntax for compiler hints (replacing `__attribute__` and `#pragma`).

-   `[[nodiscard]]`: Warn if return value is ignored.
-   `[[maybe_unused]]`: Suppress "unused variable" warnings.
-   `[[deprecated]]`: Mark function/variable as deprecated.
-   `[[noreturn]]`: Function never returns (e.g., `exit`).
-   `[[unsequenced]]`: Function has no side effects (pure).

```c
[[nodiscard]] int compute() { return 42; }

[[deprecated("Use new_func instead")]]
void old_func() {}
```

## 🔢 Binary Literals & Separators
Better readability for constants.

```c
int bin = 0b1010_0011; // 0b prefix and _ separator
```

## �️ BitInt
Fixed-width integers for specific bit counts (useful for FPGA/hardware).

```c
_BitInt(12) sensor_val; // 12-bit integer
```

---
[[00-Index|Back to Advanced Index]]
