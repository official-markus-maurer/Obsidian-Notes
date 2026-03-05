# Non-Local Jumps (`setjmp` / `longjmp`)

These functions allow you to jump from one function to another, bypassing the normal call stack return sequence. They can be used to implement exception handling.

## 📚 Header
```c
#include <setjmp.h>
```

## 🚀 How it Works

1.  **`setjmp(env)`**: Saves the current CPU state (registers, SP, FP, PC) into `env`. Returns `0` initially.
2.  **`longjmp(env, val)`**: Restores the CPU state from `env`. It's like a "time travel" back to the `setjmp` call. `setjmp` will appear to return `val`.

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
    // Volatile is required for local vars modified between setjmp and longjmp!
    volatile int counter = 0;

    if (setjmp(savebuf) == 0) {
        // "Try" block
        printf("Calling sub_function...\n");
        counter++;
        sub_function();
    } else {
        // "Catch" block
        printf("Caught an exception! Counter: %d\n", counter);
    }
    return 0;
}
```

## 🛑 The "Volatile" Trap
The compiler optimizes local variables by keeping them in registers (`RBX`, `R12`...).
-   `setjmp` saves these registers.
-   Code runs, modifies the variable (in the register).
-   `longjmp` restores the **old** register values from the snapshot.
-   **Result**: The variable reverts to its old value!

Declaring it `volatile` forces the compiler to store it in memory (Stack), which is **not** reverted by `longjmp` (because `longjmp` only restores the Stack Pointer, not the stack content itself).

## 👻 Resource Leaks
Resources allocated between `setjmp` and `longjmp` (like `malloc`, open files, mutexes) will **leak**.
The stack frames are popped, but no cleanup code (destructors/defer) runs.
You must manually clean up or use a pool allocator.

---
[[00-Index|Back to Error Handling Index]]
