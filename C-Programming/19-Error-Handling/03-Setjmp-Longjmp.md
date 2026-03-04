# Non-Local Jumps (`setjmp` / `longjmp`)

These functions allow you to jump from one function to another, bypassing the normal call stack return sequence. They can be used to implement exception handling.

## 📚 Header
```c
#include <setjmp.h>
```

## 🚀 How it Works

1.  **`setjmp(env)`**: Saves the current stack context into `env`. Returns `0` initially.
2.  **`longjmp(env, val)`**: Jumps back to the `setjmp` point. `setjmp` will return `val`.

## ⚠️ Example (Simulating Try-Catch)

```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf savebuf;

void sub_function() {
    printf("Inside sub_function. An error occurs!\n");
    longjmp(savebuf, 1); // Throw exception (1)
    printf("This will never print.\n");
}

int main() {
    if (setjmp(savebuf) == 0) {
        // "Try" block
        printf("Calling sub_function...\n");
        sub_function();
    } else {
        // "Catch" block
        printf("Caught an exception! Returned from longjmp.\n");
    }
    return 0;
}
```

## 🛑 Dangers
-   Local variables in the function calling `setjmp` might be clobbered unless declared `volatile`.
-   Resources allocated between `setjmp` and `longjmp` (like `malloc`) will leak because the stack is unwound without calling destructors/free.

---
[[00-Index|Back to Error Handling Index]]
