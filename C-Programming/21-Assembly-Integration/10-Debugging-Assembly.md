# Debugging Assembly (GDB)

Debugging at the assembly level is essential when:
1.  **Optimization**: The compiler optimized away your variables.
2.  **Crashes**: Understanding where a `Segmentation Fault` actually happened.
3.  **Reverse Engineering**: Analyzing binaries without source code.

## 🖥️ Viewing Assembly

### Disassemble a Function
`disassemble main` (or `disas main`)

### Switch to Assembly Layout
GDB has a built-in TUI (Text User Interface) mode.
`layout asm`

Shows the disassembly window. You can also add register view:
`layout regs`

## 🚶 Stepping Instructions

-   **`stepi` (si)**: Step one assembly instruction. Step *into* function calls.
-   **`nexti` (ni)**: Step one assembly instruction. Step *over* function calls.

## 🔍 Inspecting Registers

-   **`info registers`**: Show general purpose registers (`rax`, `rbx`, etc.).
-   **`info all-registers`**: Show all registers (including SSE/AVX `xmm`).
-   **`print $rax`**: Print the value of a specific register.

## 📍 Setting Breakpoints

-   **`break *0x401000`**: Set a breakpoint at a specific memory address.
-   **`break *main+10`**: Set a breakpoint 10 bytes into `main`.

## 🛠️ Typical Workflow

1.  **Compile with Debug Symbols**: `gcc -g -O0 main.c -o main`
2.  **Start GDB**: `gdb ./main`
3.  **Set Breakpoint**: `break main`
4.  **Run**: `run`
5.  **Switch View**: `layout asm`
6.  **Step**: `si` until crash or interest point.
7.  **Inspect**: `print $rax` to check return values or pointers.

## ⚠️ Common Pitfalls

### "Why is my variable gone?"
If you compile with `-O2` or `-O3`, the compiler might keep variables solely in registers and never write them to memory. GDB might say `<optimized out>`. You must inspect the register where the value is stored.

### "The line numbers don't match!"
Compiler optimizations can reorder instructions. One line of C code might be split into multiple chunks of assembly spread out.

---
[[00-Index|Back to Assembly Index]]
