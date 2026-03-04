# Type Casting

Type casting is a way to convert a variable from one data type to another.

## 🎭 Implicit Conversion (Coercion)
Done automatically by the compiler.
-   Usually happens when promoting a smaller type to a larger type (e.g., `int` to `float`).
-   Can lose precision if demoting (e.g., `float` to `int`).

```c
int x = 10;
char y = 'a';
int sum = x + y; // y is implicitly converted to int (97)
float f = x; // 10.0
```

## 🔨 Explicit Conversion (Casting)
Done manually by the programmer.

**Syntax**: `(type_name) expression`

```c
int a = 10, b = 3;
float result = (float)a / b; // 3.333...
// Without cast: 10 / 3 = 3 (integer division)
```

## ⚠️ Dangers
-   **Truncation**: Casting `float` to `int` drops the decimal part (`3.9` -> `3`).
-   **Overflow**: Casting a large `int` to `char` will wrap around.

---
[[00-Index|Back to Basics Index]]
