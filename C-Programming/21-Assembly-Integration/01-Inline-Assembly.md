# Inline Assembly (GCC/Clang)

Inline assembly allows you to embed assembly instructions directly into your C code.

## 📝 Syntax

```c
asm ( "assembly code" 
    : output operands   /* optional */
    : input operands    /* optional */
    : clobbered list    /* optional */
);
```

## 🚀 Example: Adding two numbers (x86)

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, result;

    asm ("addl %%ebx, %%eax;"
         : "=a" (result)    // Output: store result in 'result' (eax)
         : "a" (a), "b" (b) // Input: load 'a' into eax, 'b' into ebx
    );

    printf("Result: %d\n", result);
    return 0;
}
```

## ⚠️ Constraints
-   `"r"`: Use any general register.
-   `"a"`: Use `eax`/`rax`.
-   `"m"`: Use memory.
-   `"i"`: Use an immediate integer.

> **Note**: Inline assembly is non-portable. Code written for x86 won't run on ARM.

---
[[00-Index|Back to Assembly Index]]
