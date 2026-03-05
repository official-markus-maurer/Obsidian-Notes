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

### Thread-Safe `strerror_r`
`strerror` is **not** thread-safe (returns a pointer to a static buffer). Use `strerror_r` in multithreaded apps.

```c
char err_buf[256];
if (strerror_r(errno, err_buf, sizeof(err_buf)) == 0) {
    fprintf(stderr, "Error: %s\n", err_buf);
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
