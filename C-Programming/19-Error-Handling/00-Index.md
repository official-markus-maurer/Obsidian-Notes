# Error Handling in C

C does not have exceptions (`try-catch`). Error handling is manual and explicit.

## 📋 Topics

1.  **[[01-Errno|The `errno` Variable]]**
    -   Using `<errno.h>`
    -   `perror` and `strerror`

2.  **[[02-Goto-Cleanup|Cleanup with `goto`]]**
    -   The one valid use case for `goto`
    -   Resource management pattern

3.  **[[03-Setjmp-Longjmp|Non-Local Jumps]]**
    -   `setjmp` and `longjmp`
    -   Simulating exceptions

---
**Next Section**: [[../20-Interop/00-Index|Interoperability]]
