# System Calls (Syscalls)

A System Call is the mechanism used by an application to request service from the kernel.

## How it works
1.  **Application**: Calls `printf("Hello")`.
2.  **Library (libc)**: `printf` calls `write()`.
3.  **Wrapper**: `write()` puts arguments in registers and executes a special CPU instruction (`syscall` on x64, `int 0x80` on x86).
4.  **CPU**: Switches to Kernel Mode.
5.  **Kernel**: Executes the `sys_write` handler.
6.  **Return**: Kernel switches back to User Mode.

## Common Syscalls (POSIX)
-   **File I/O**: `open`, `read`, `write`, `close`.
-   **Process**: `fork`, `exec`, `wait`, `exit`.
-   **Network**: `socket`, `bind`, `connect`.

---
[[00-Index|Back to OS Index]]
