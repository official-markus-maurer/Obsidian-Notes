# C Style Guides

Consistency is key. A codebase with mixed styles is hard to read and harder to maintain. Adopting a style guide allows developers to focus on logic rather than formatting.

## Popular Style Guides

### 1. Linux Kernel Coding Style
Used by the Linux kernel developers. It is very opinionated.
-   **Indentation**: 8-character tabs (no spaces).
-   **Braces**: K&R style (opening brace on the same line).
    ```c
    if (x is true) {
            we do y
    }
    ```
-   **Line Length**: 80 columns preferred (hard limit 100).
-   **Naming**: `snake_case` for variables and functions. No CamelCase.
-   **Functions**: Should be short and do one thing.

### 2. Google C++ Style Guide (for C)
Google uses C++ primarily, but their C style is also influential.
-   **Indentation**: 2 spaces.
-   **Braces**: Attached (same line).
-   **Naming**:
    -   Variables: `snake_case`
    -   Functions: `CamelCase` (UpperCamelCase)
    -   Macros: `UPPER_SNAKE_CASE`

### 3. GNU Coding Standards
Used by GNU projects (GCC, GDB).
-   **Indentation**: 2 spaces, but braces are indented too.
    ```c
    if (x)
      {
        y ();
      }
    ```
-   **Space before parentheses**: `function ()`.

## Recommended Elements of a Style Guide

Regardless of which standard you pick, define rules for:

1.  **Naming Conventions**:
    -   `g_` prefix for globals?
    -   `s_` prefix for statics?
    -   `_t` suffix for typedefs?

2.  **File Organization**:
    -   Copyright header.
    -   Includes (System <...> then Local "...").
    -   Macros.
    -   Type definitions.
    -   Global variables.
    -   Function prototypes.
    -   Function implementations.

3.  **Comments**:
    -   Use `/* ... */` for multi-line.
    -   Use `//` for single-line (C99+).
    -   Document *why*, not *what*.

## Tooling: Clang-Format
Don't argue about style in code reviews. Automate it.
Create a `.clang-format` file in your project root:

```yaml
BasedOnStyle: LLVM
IndentWidth: 4
UseTab: Never
BreakBeforeBraces: Attach
ColumnLimit: 100
```

Run it:
```bash
clang-format -i *.c *.h
```

---
[[00-Index|Back to Index]] | [[../36-Modern-Build-Systems/00-Index|Next Module: Modern Build Systems]]
