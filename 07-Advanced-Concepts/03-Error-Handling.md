# Error Handling

C does not have exceptions like Java or Python. Errors are handled using return values and the global variable `errno`.

## 🚨 `errno`
Defined in `<errno.h>`. When a system call fails, it sets `errno` to a specific error code.

## 🗣️ `perror` and `strerror`
- `perror("message")`: Prints the error message corresponding to `errno` to stderr.
- `strerror(errno)`: Returns the string description of the error code (requires `<string.h>`).

## 📝 Example

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *pf;
    pf = fopen("nonexistent.txt", "rb");

    if (pf == NULL) {
        printf("Error value: %d\n", errno);
        perror("Error printed by perror");
        printf("Error string: %s\n", strerror(errno));
    } else {
        fclose(pf);
    }
    return 0;
}
```

---
[[00-Index|Back to Advanced Index]]
