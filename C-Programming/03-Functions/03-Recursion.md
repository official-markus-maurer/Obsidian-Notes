# Recursion

Recursion is the process of a function calling itself.

## 🔄 How it Works
A recursive function solves a problem by solving smaller instances of the same problem. It must have:
1. **Base Case**: A condition to stop the recursion.
2. **Recursive Step**: The function calls itself with modified arguments.

## ⚠️ Stack Overflow
If the base case is missing or unreachable, the function will call itself indefinitely, filling up the stack memory and causing a crash (Stack Overflow).

## 🧮 Example: Factorial
Factorial of `n` (`n!`) is `n * (n-1) * ... * 1`.
`5! = 5 * 4 * 3 * 2 * 1 = 120`.

```c
#include <stdio.h>

int factorial(int n) {
    // Base Case
    if (n <= 1)
        return 1;
    
    // Recursive Step
    return n * factorial(n - 1);
}

int main() {
    printf("Factorial of 5 is %d", factorial(5));
    return 0;
}
```

---
[[00-Index|Back to Functions Index]]
