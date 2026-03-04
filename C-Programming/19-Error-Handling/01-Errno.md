# The `errno` Variable

When a standard library function fails (like `open`, `malloc`), it often sets a global variable called `errno` to a specific error code.

## 📚 Header
```c
#include <errno.h>
#include <string.h> // for strerror
#include <stdio.h>  // for perror
```

## 🛠️ Usage

1.  **Check the return value** of the function first (usually `-1` or `NULL`).
2.  **Inspect `errno`** to see what went wrong.

```c
FILE *f = fopen("non_existent_file.txt", "r");
if (f == NULL) {
    printf("Error Code: %d\n", errno);
    perror("fopen failed"); // Prints: "fopen failed: No such file or directory"
    printf("Error Message: %s\n", strerror(errno));
}
```

## ⚠️ Important
-   `errno` is **not cleared** automatically. Only check it if a function failed.
-   `errno` is thread-local in modern C (safe to use in threads).

---
[[00-Index|Back to Error Handling Index]]
