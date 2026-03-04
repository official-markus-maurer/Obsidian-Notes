# Variadic Functions

Variadic functions are functions that can accept a variable number of arguments. The most common example is `printf`.

## 📚 Header

You need to include `<stdarg.h>`.

## 🛠️ Implementing a Variadic Function

1.  At least one fixed argument is required.
2.  Use `...` (ellipsis) to indicate variable arguments.
3.  Use macros to access arguments: `va_list`, `va_start`, `va_arg`, `va_end`.

### Example: Summing Numbers

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    int total = 0;
    va_list args;
    
    // Initialize the argument list
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        // Retrieve the next argument (type int)
        total += va_arg(args, int);
    }
    
    // Clean up
    va_end(args);
    
    return total;
}

int main() {
    printf("Sum: %d\n", sum(3, 10, 20, 30)); // 60
    return 0;
}
```

## ⚠️ Important Notes

1.  **Type Safety**: `va_arg` assumes you know the type of the argument. If you guess wrong, you get garbage or a crash.
2.  **Count/Sentinel**: You need a way to know how many arguments there are (like the `count` param above, or a format string like in `printf`, or a sentinel value like `NULL` at the end).
3.  **Promotion**: `char` and `short` are promoted to `int`. `float` is promoted to `double`.

---
[[00-Index|Back to Functions Index]]
