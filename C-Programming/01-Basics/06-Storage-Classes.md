# Storage Classes

Storage classes define the scope (visibility) and lifetime of variables/functions.

## 📦 `auto`
-   **Default** for local variables.
-   Stored on the **Stack**.
-   Created when block is entered, destroyed when exited.

## 🌍 `extern`
-   Used to tell the compiler that a variable is defined in **another file**.
-   Used for global variables shared across files.

```c
// file1.c
int globalVar = 10;

// file2.c
extern int globalVar; // Declaration only
void print() { printf("%d", globalVar); }
```

## 🔒 `static`
Has two meanings depending on where it's used.

1.  **Inside a function**: The variable retains its value between function calls.
    ```c
    void count() {
        static int c = 0; // Initialized once
        c++;
    }
    ```
2.  **Global (File Scope)**: The variable/function is **private** to this file. It cannot be accessed by other files using `extern`.

## ⚡ `register`
-   Hint to store the variable in a CPU register instead of RAM.
-   Faster access.
-   You cannot get the address (`&`) of a register variable.
-   *Note*: Modern compilers are good at optimizing this automatically, so this is rarely used manually.

---
[[00-Index|Back to Basics Index]]
