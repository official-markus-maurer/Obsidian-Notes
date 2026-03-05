# Linking Assembly with C

For small snippets, inline assembly is fine. For larger functions or complex logic, it's better to write assembly in a separate `.s` file and link it with your C code.

## 📝 The Workflow

1.  **Write Assembly (`func.s`)**: Implement the function logic.
2.  **Declare Prototype (`func.h`)**: Tell C the function exists.
3.  **Call from C (`main.c`)**: Use the function like any other C function.
4.  **Compile & Link**: Use `gcc` to combine them.

## 1. The Assembly File (`func.s`)

Must follow the ABI (Calling Convention).
-   **Linux**: `RDI`, `RSI`, `RDX`... Return in `RAX`.
-   **Windows**: `RCX`, `RDX`, `R8`... Return in `RAX`.

```asm
; func.s (Linux x86-64)
section .text
global my_add           ; Export symbol for linker

; int my_add(int a, int b)
; a = RDI, b = RSI
my_add:
    mov rax, rdi        ; rax = a
    add rax, rsi        ; rax += b
    ret                 ; Return result in rax
```

## 2. The Header File (`func.h`)

```c
#ifndef FUNC_H
#define FUNC_H

// Declare the external assembly function
// Use extern "C" if calling from C++
int my_add(int a, int b);

#endif
```

## 3. The C File (`main.c`)

```c
#include <stdio.h>
#include "func.h"

int main() {
    int result = my_add(10, 20);
    printf("Result: %d\n", result);
    return 0;
}
```

## 4. Compiling

You can compile both files in one command:

```bash
# Assemble and Compile
gcc main.c func.s -o app

# Run
./app
```

Or step-by-step (better for Makefiles):

```bash
nasm -f elf64 func.s -o func.o   # Assemble (if using NASM syntax)
gcc -c main.c -o main.o          # Compile C
gcc main.o func.o -o app         # Link
```

## ⚠️ Important Considerations
-   **Name Mangling**: C++ mangles names. Use `extern "C"` in headers.
-   **Underscores**: On macOS (Mach-O) and older 32-bit systems, C functions are prefixed with `_` in assembly (e.g., `_my_add`). On modern Linux/Windows (ELF/PE), they are not.
-   **Stack Alignment**: If your assembly function calls other functions (like `printf`), ensure `RSP` is 16-byte aligned before the `CALL`.

---
[[00-Index|Back to Assembly Index]]
