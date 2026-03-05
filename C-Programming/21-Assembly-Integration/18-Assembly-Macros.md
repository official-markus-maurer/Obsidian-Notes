# Assembly Macros (NASM)

Just like C has `#define`, assembly (NASM) has `%macro`. Macros are text substitutions that can save you from typing repetitive code blocks.

## 📝 Defining a Macro

A macro is defined with `%macro Name NumArgs`.

```asm
; Define a macro to print a string (Linux x64)
%macro PRINT_STRING 2
    ; %1 = String address
    ; %2 = String length
    
    mov rax, 1          ; sys_write
    mov rdi, 1          ; fd = stdout
    mov rsi, %1         ; Buffer
    mov rdx, %2         ; Count
    syscall
%endmacro
```

## 🚀 Using the Macro

```asm
section .data
    msg db "Hello", 0xA
    len equ $ - msg

section .text
global _start

_start:
    PRINT_STRING msg, len   ; Expands to the 5 instructions above
    
    mov rax, 60
    xor rdi, rdi
    syscall
```

## 🏷️ Local Labels

If your macro contains a label (for a loop or jump), you'll get a "symbol redefinition error" if you use the macro twice.
**Solution**: Use `%%label` for macro-local labels.

```asm
%macro ABS 1
    ; Calculate absolute value of register %1
    cmp %1, 0
    jge %%skip      ; Unique label for each expansion
    neg %1
%%skip:
%endmacro

_start:
    mov rax, -5
    ABS rax         ; rax = 5
    
    mov rbx, -10
    ABS rbx         ; rbx = 10 (Different %%skip label)
```

## 🔄 Conditional Assembly

You can use `%if` to generate different code based on flags.

```asm
%define DEBUG 1

%macro LOG 1
    %if DEBUG == 1
        PRINT_STRING %1, 10
    %endif
%endmacro
```

---
[[00-Index|Back to Assembly Index]]
