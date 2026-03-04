# C Standards History

C has evolved significantly over the decades. Understanding the standards helps you write portable, modern, and safe code.

## 📜 K&R C (1978)
The original specification from Kernighan and Ritchie's book. Not an official standard, but the de facto one for years.
-   **Function Definitions**: Old style (`int main(argc, argv) int argc; char **argv; { ... }`).
-   **No `void`**: Functions returned `int` by default.

## 📜 C89 / C90 (ANSI C)
The first official standard by ANSI (1989) and ISO (1990). Still widely supported in embedded systems.
-   **Function Prototypes**: `int main(int argc, char **argv);`.
-   **`void` Pointers**: Generic pointers.
-   **`const` and `volatile`**: Type qualifiers.
-   **Comments**: Only `/* ... */` block comments.
-   **Declarations**: Must be at the top of a block `{ ... }`.

## 📜 C99 (ISO/IEC 9899:1999)
A major update that modernized the language.
-   **`//` Comments**: Single-line comments.
-   **Mixed Declarations**: Declare variables anywhere (e.g., `for (int i=0; ...)`).
-   **New Types**:
    -   `long long int` (at least 64-bit).
    -   `_Bool` (available as `bool` via `<stdbool.h>`).
    -   `_Complex`.
-   **Headers**:
    -   `<stdint.h>`: Fixed-width integers (`int32_t`, `uint64_t`).
    -   `<inttypes.h>`: Format specifiers for fixed-width ints (`PRId64`).
-   **VLAs**: Variable Length Arrays (arrays with size determined at runtime).
-   **Designated Initializers**: `struct Point p = {.x = 1, .y = 2};`.

## 📜 C11 (ISO/IEC 9899:2011)
Focused on multithreading and safety.
-   **Multithreading**: Native support via `<threads.h>` (optional feature).
-   **Atomics**: `_Atomic` type qualifier and `<stdatomic.h>`.
-   **Generics**: `_Generic` keyword for type-generic macros (simulating function overloading).
-   **Anonymous Structs/Unions**: Simplifies nested data structures.
-   **Static Assert**: `_Static_assert` for compile-time checks.
-   **VLA Optional**: Compiler support for VLAs became optional (`__STDC_NO_VLA__`).
-   **`gets()` Removed**: The dangerous function was finally removed.

## 📜 C17 (ISO/IEC 9899:2018)
A bug-fix release for C11. No new features, just clarifications. This is the current default for many compilers (GCC 8+, Clang 6+).

## 📜 C23 (ISO/IEC 9899:2024)
The latest major revision.
-   **Keywords**: `true`, `false`, `bool`, `alignas`, `alignof`, `static_assert`, `thread_local` became keywords (no headers needed).
-   **`typeof`**: Operator to get the type of an expression (from GCC extension).
-   **`#embed`**: Preprocessor directive to include binary data directly.
-   **`nullptr`**: Type-safe null pointer constant (like C++).
-   **Attributes**: C++ style attributes `[[nodiscard]]`, `[[maybe_unused]]`, `[[deprecated]]`.
-   **Zero Initialization**: `int x = {};` initializes to 0.
-   **Bit-precise Integers**: `_BitInt(N)`.

---
[[00-Index|Back to Advanced Index]]
