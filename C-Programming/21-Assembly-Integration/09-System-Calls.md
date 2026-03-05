# System Calls (Linux x86-64)

A **System Call (syscall)** is how a program requests a service from the operating system kernel (e.g., opening a file, writing to stdout, exiting).

In C, we usually call wrapper functions like `write()` or `exit()`. In assembly, we invoke the kernel directly.

## 📞 The `SYSCALL` Instruction

On x86-64 Linux, the `syscall` instruction triggers a switch to kernel mode.

### Arguments (Linux ABI)
The arguments for a syscall are different from the function calling convention!

| Argument | Register |
| :--- | :--- |
| **Syscall Number** | `RAX` |
| **Arg 1** | `RDI` |
| **Arg 2** | `RSI` |
| **Arg 3** | `RDX` |
| **Arg 4** | `R10` (Not RCX!) |
| **Arg 5** | `R8` |
| **Arg 6** | `R9` |
| **Return Value** | `RAX` |

> **Note**: The kernel clobbers `RCX` and `R11`.

## 🚀 The Cost of Syscalls

Syscalls are expensive (~1000 cycles). The CPU must:
1.  Save user-space state.
2.  Switch to Ring 0 (Kernel Mode).
3.  Perform security checks (Page Tables).
4.  Execute the function.
5.  Restore user-space state.
6.  Return to Ring 3 (User Mode).

### vDSO (Virtual Dynamic Shared Object)

For some frequent syscalls (`gettimeofday`, `getcpu`), the kernel maps a read-only page of kernel memory directly into every process.
-   The "syscall" becomes a simple function call to this page.
-   **No context switch**! It's as fast as a normal function call.
-   **Example**: `clock_gettime`.

## 📜 Common Syscall Numbers (x86-64)

| Name | RAX | RDI | RSI | RDX |
| :--- | :--- | :--- | :--- | :--- |
| `sys_read` | 0 | fd | buf | count |
| `sys_write` | 1 | fd | buf | count |
| `sys_open` | 2 | filename | flags | mode |
| `sys_close` | 3 | fd | - | - |
| `sys_exit` | 60 | status | - | - |

## ⚠️ Windows Syscalls
Windows does **not** use a stable syscall ABI. Syscall numbers change between Windows versions.
**Always** call the Windows API (e.g., `WriteFile`, `ExitProcess`) via `kernel32.dll` instead of using `syscall` directly.

---
[[00-Index|Back to Assembly Index]]
