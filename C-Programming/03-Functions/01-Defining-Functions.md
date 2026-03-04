# Defining and Using Functions

## 🔨 Anatomy of a Function

```c
return_type function_name(parameter_list) {
    // Function body
    return value;
}
```

- **return_type**: Data type of the value the function returns (e.g., `int`, `void`, `float`).
- **function_name**: The identifier for the function.
- **parameters**: Variables that accept values passed to the function.

## 📝 Declaration vs. Definition

It is good practice to declare functions before `main()` and define them after. This declaration is called a **prototype**.

```c
#include <stdio.h>

// Function Declaration (Prototype)
int add(int, int);

int main(void) {
    int result = add(5, 3); // Function Call
    printf("Result: %d\n", result);
    return 0;
}

// Function Definition
int add(int a, int b) {
    return a + b;
}
```

## 📦 Parameters and Arguments

- **Parameters**: Variables listed in the function definition.
- **Arguments**: Real values passed to the function when it is called.

### Pass by Value
By default, C passes arguments by value. This means a copy of the data is passed to the function. Changes inside the function do not affect the original variable.

```c
void change(int num) {
    num = 100;
}

int main(void) {
    int x = 10;
    change(x);
    printf("%d", x); // Output will be 10, not 100
}
```

## 📜 C Standards: Function Prototypes

### K&R C (Pre-1989)
Old style, avoid using.
```c
int add(a, b) int a; int b; { return a + b; }
```

### C89 / C90
Prototypes introduced to check types.
```c
int add(int a, int b);
```
**Note on `main`**: `int main()` in C89 means "takes unspecified arguments".

### C99 / C11
Added `inline` keyword.
```c
inline int max(int a, int b) { return (a > b) ? a : b; }
```
**Note on `main`**: Use `int main(void)` to explicitly say "no arguments".

### C23
-   `int main()` now implies `int main(void)` (no arguments).
-   Attributes like `[[noreturn]]` and `[[nodiscard]]`.

```c
[[nodiscard]] int compute_important_value() { return 42; }

[[noreturn]] void fatal_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
```

---
[[00-Index|Back to Functions Index]]
