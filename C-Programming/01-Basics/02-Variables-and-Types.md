# Variables and Data Types

## 📦 Variables
A variable is a container for storing data values. In C, variables must be declared before they are used.

### Syntax
```c
type variable_name = value;
```

### Naming Rules
- Must begin with a letter or underscore (`_`).
- Can contain letters, digits, and underscores.
- Case-sensitive (`myVar` and `myvar` are different).
- Cannot use reserved keywords (e.g., `int`, `return`, `if`).

## 📊 Primitive Data Types

| Type | Description | Format Specifier | Size (Typical) |
|------|-------------|------------------|----------------|
| `int` | Integer (whole number) | `%d` or `%i` | 4 bytes |
| `float` | Floating point number | `%f` | 4 bytes |
| `double` | Double precision float | `%lf` | 8 bytes |
| `char` | Single character | `%c` | 1 byte |
| `void` | Empty/No value | - | - |

### Example

```c
#include <stdio.h>

int main() {
    int age = 25;
    float height = 5.9;
    char grade = 'A';
    double pi = 3.14159265359;

    printf("Age: %d\n", age);
    printf("Height: %f\n", height);
    printf("Grade: %c\n", grade);
    printf("Pi: %lf\n", pi);

    return 0;
}
```

## 📏 Sizeof Operator
You can check the size of a data type using the `sizeof()` operator.

```c
printf("Size of int: %lu bytes\n", sizeof(int));
```

## 🔒 Constants
Constants are variables whose values cannot be changed.

```c
const int DAYS_IN_WEEK = 7;
#define PI 3.14159 // Preprocessor directive constant
```

---
[[00-Index|Back to Basics Index]]
