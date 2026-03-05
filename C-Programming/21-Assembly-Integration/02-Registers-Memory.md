# Registers and Memory

Registers are small, ultra-fast storage locations inside the CPU. They are the "variables" of assembly language.

## 💾 General Purpose Registers (x86-64)

In 64-bit mode (x86-64), registers are 64 bits wide (start with `R`).
-   `RAX`: Accumulator (Return values)
-   `RBX`: Base (Saved register)
-   `RCX`: Counter (Loop counter, Argument 4 in Win64)
-   `RDX`: Data (Argument 3 in Win64, part of MUL/DIV)
-   `RSI`: Source Index (Argument 2 in System V)
-   `RDI`: Destination Index (Argument 1 in System V)
-   `RBP`: Base Pointer (Stack Frame base)
-   `RSP`: Stack Pointer (Top of stack)
-   `R8` - `R15`: New 64-bit registers (Arguments 5, 6...)

### Sub-registers
You can access parts of a 64-bit register.
-   `RAX` (64-bit) -> `EAX` (32-bit) -> `AX` (16-bit) -> `AL` (Low 8-bit) / `AH` (High 8-bit).
-   **Important**: Writing to the 32-bit part (`mov eax, 10`) **zeros out the upper 32 bits** of `RAX`.

## 📍 Special Registers

### Instruction Pointer (`RIP`)
Points to the *next* instruction to execute.
-   Updated automatically by the CPU.
-   Cannot be written directly (use `JMP`, `CALL`, `RET`).
-   **PC-Relative Addressing**: `[rip + 0x100]` allows code to be Position Independent (PIE).

### Flags Register (`RFLAGS`)
Contains status flags updated by arithmetic/logic operations.
-   **ZF (Zero Flag)**: Result was zero (`CMP a, b` sets ZF if a == b).
-   **SF (Sign Flag)**: Result was negative.
-   **OF (Overflow Flag)**: Signed overflow occurred.
-   **CF (Carry Flag)**: Unsigned overflow occurred.

## 🧠 Memory Addressing Modes (Intel Syntax)

Memory access is denoted by brackets `[]`.

1.  **Direct**: `mov rax, [0x401000]` (Read from address)
2.  **Register Indirect**: `mov rax, [rbx]` (Read from address in RBX)
3.  **Base + Displacement**: `mov rax, [rbp - 8]` (Local variable access)
4.  **Scaled Index**: `mov rax, [rbx + rcx*8]` (Array access: Base + Index * Scale)
    -   Scale can be 1, 2, 4, or 8.

---
[[00-Index|Back to Assembly Index]]
