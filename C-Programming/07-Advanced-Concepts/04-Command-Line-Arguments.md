# Command Line Arguments

You can pass arguments to your C program when you run it from the command line.

## 📥 `main` Parameters

```c
int main(int argc, char *argv[]) {
    // ...
}
```

- **`argc` (Argument Count)**: The number of arguments passed (including the program name).
- **`argv` (Argument Vector)**: An array of strings containing the arguments.

## 📝 Example

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);

    if (argc > 1) {
        printf("Arguments passed:\n");
        for (int i = 1; i < argc; i++) {
            printf("%d: %s\n", i, argv[i]);
        }
    } else {
        printf("No arguments passed.\n");
    }
    return 0;
}
```

**Running the program:**
```bash
./myprogram arg1 arg2
```

**Output:**
```
Program name: ./myprogram
Arguments passed:
1: arg1
2: arg2
```

---
[[00-Index|Back to Advanced Index]]
