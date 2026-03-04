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

int main() {
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

int main() {
    int x = 10;
    change(x);
    printf("%d", x); // Output will be 10, not 100
}
```

---
[[00-Index|Back to Functions Index]]
