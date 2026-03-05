# Assembly Integration

C is often called "portable assembly", but sometimes you need actual assembly for maximum performance, hardware access, or understanding how your code executes.

## 📋 Topics

1.  **[[01-Assembly-Basics|Assembly Basics (x86-64)]]**
    -   Intel vs AT&T Syntax
    -   Why learn Assembly?

2.  **[[02-Registers-Memory|Registers and Memory]]**
    -   General Purpose Registers (`RAX`, `RBX`...)
    -   Stack Pointer (`RSP`) and Instruction Pointer (`RIP`)
    -   Flags Register (`RFLAGS`)

3.  **[[03-Common-Instructions|Common Instructions]]**
    -   Data Movement (`MOV`, `LEA`)
    -   Arithmetic (`ADD`, `SUB`, `MUL`)

4.  **[[11-Floating-Point|Floating Point Assembly]]**
    -   `XMM` Registers (SSE/AVX)
    -   Scalar Operations (`ADDSS`, `MOVSS`)

5.  **[[07-Control-Flow|Control Flow]]**
    -   Compare (`CMP`, `TEST`)
    -   Conditional Jumps (`JE`, `JG`, `JNE`)
    -   Implementing Loops

6.  **[[08-Stack-Operations|Stack Operations]]**
    -   `PUSH` and `POP`
    -   Stack Frames (`RBP`)
    -   Alignment requirements

7.  **[[04-Calling-Conventions|Calling Conventions]]**
    -   System V AMD64 ABI (Linux/Mac)
    -   Microsoft x64 ABI (Windows)
    -   Red Zone and Shadow Space

8.  **[[09-System-Calls|System Calls]]**
    -   Invoking the kernel directly (`syscall`)
    -   Linux Syscall ABI vs Function Calls

9.  **[[05-Inline-Assembly|Inline Assembly]]**
    -   GCC `asm` syntax
    -   Input/Output Constraints
    -   Clobbers and Volatile

10. **[[06-Intrinsics|Compiler Intrinsics]]**
    -   Using built-in functions (`__builtin_popcount`, `__builtin_expect`)
    -   Atomic Operations (`__atomic_fetch_add`)

11. **[[10-Debugging-Assembly|Debugging Assembly]]**
    -   Using GDB to view disassembly (`layout asm`)
    -   Stepping instructions (`si`, `ni`)
    -   Inspecting registers (`info registers`)

---
**Next Section**: [[../22-SIMD/00-Index|SIMD & Vectorization]]
