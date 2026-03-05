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

## 🚀 Example: Hello World (No libc)

This program writes "Hello" to stdout and exits, without using `printf` or `main`.

```asm
; assemble with: nasm -f elf64 hello.asm
; link with: ld hello.o -o hello

section .data
    msg db "Hello, World!", 0xA  ; String + Newline
    len equ $ - msg              ; Calculate length

section .text
    global _start                ; Entry point for linker

_start:
    ; 1. write(fd, buf, count)
    ; syscall number 1 is sys_write
    mov rax, 1          ; sys_write
    mov rdi, 1          ; fd = 1 (stdout)
    mov rsi, msg        ; buf = msg
    mov rdx, len        ; count = len
    syscall             ; Invoke kernel

    ; 2. exit(status)
    ; syscall number 60 is sys_exit
    mov rax, 60         ; sys_exit
    mov rdi, 0          ; status = 0
    syscall
```

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
