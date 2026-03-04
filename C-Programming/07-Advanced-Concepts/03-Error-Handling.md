# Error Handling

C does not have exceptions like Java or Python. Errors are handled using return values and the global variable `errno`.

## 🚨 Return Values
Functions usually return a specific value to indicate success or failure.
-   **Int functions**: Return `0` for success, `-1` or non-zero for failure.
-   **Pointer functions**: Return `NULL` for failure.

```c
if (func() != 0) {
    // Handle error
}
```

## 📜 `errno` (`<errno.h>`)
When a system call fails, it sets the global variable `errno` to a specific error code.
*Note: `errno` is thread-local in modern C.*

Common Error Codes:
-   `EACCES`: Permission denied.
-   `ENOENT`: No such file or directory.
-   `ENOMEM`: Out of memory.

## 🗣️ Printing Errors
-   `perror("prefix")`: Prints "prefix: error message" to stderr.
-   `strerror(errno)`: Returns the string description of the error code (requires `<string.h>`).

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h> // for exit()

int main(void) {
    FILE *pf = fopen("nonexistent.txt", "rb");

    if (pf == NULL) {
        // Method 1: perror (Recommended)
        perror("Error opening file");
        
        // Method 2: strerror (Manual formatting)
        fprintf(stderr, "Error code %d: %s\n", errno, strerror(errno));
        
        exit(EXIT_FAILURE); // Portable failure code
    }

    fclose(pf);
    return EXIT_SUCCESS;
}
```

## 🚪 Exit Status (`<stdlib.h>`)
When a program finishes, it returns an exit status to the OS.
-   `EXIT_SUCCESS` (usually 0): Program ran successfully.
-   `EXIT_FAILURE` (usually 1): Program encountered an error.

```c
exit(EXIT_FAILURE);
```

## 🛡️ Goto for Cleanup
In C, `goto` is often used for centralized error handling (cleanup pattern).
See [[../19-Error-Handling/02-Goto-Cleanup|Goto Cleanup]].

---
[[00-Index|Back to Advanced Index]]
