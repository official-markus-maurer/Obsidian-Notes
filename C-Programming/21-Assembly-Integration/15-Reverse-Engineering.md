# Reverse Engineering (Assembly)

Reverse engineering is the process of analyzing compiled code to understand its logic, often without source code.

## 🕵️ Recognizing Common Patterns

### 1. Function Prologue (x86-64)
```asm
push rbp            ; Save caller's base pointer
mov rbp, rsp        ; Establish new stack frame
sub rsp, 0x10       ; Allocate local variables
```
**Interpretation**: "This is the start of a function."

### 2. Function Epilogue
```asm
leave               ; Restore stack (mov rsp, rbp; pop rbp)
ret                 ; Return to caller
```
**Interpretation**: "This is the end of a function."

### 3. Loop Structures
```asm
    mov ecx, 0      ; i = 0
loop_start:
    cmp ecx, 10     ; i < 10
    jge loop_end    ; Exit loop
    ...             ; Body
    inc ecx         ; i++
    jmp loop_start  ; Repeat
loop_end:
```
**Interpretation**: `for (int i=0; i<10; i++)`

### 4. Switch Statements (Jump Tables)
Compilers optimize `switch` statements into jump tables (arrays of addresses).

```asm
    mov rax, [case_variable]
    jmp [jump_table + rax*8] ; Jump to address at index 'rax'
```

## 🛠️ Tools of the Trade

1.  **GDB / LLDB**: Interactive debugging.
2.  **Objdump**: Simple disassembly.
    ```bash
    objdump -d -M intel ./program
    ```
3.  **Ghidra / IDA Pro**: Powerful decompilers (convert assembly back to pseudo-C).
4.  **Strings**: Find text in binary.
    ```bash
    strings ./program
    ```

## 🛡️ Anti-Reversing Tricks

Malware or DRM often use tricks to confuse analysis:
1.  **Obfuscation**: Adding useless instructions (`nop`, complex math that cancels out).
2.  **Self-Modifying Code**: Program decrypts itself at runtime.
3.  **Anti-Debugging**: Detecting if a debugger is attached (e.g., `ptrace` fails).

---
[[00-Index|Back to Assembly Index]]
