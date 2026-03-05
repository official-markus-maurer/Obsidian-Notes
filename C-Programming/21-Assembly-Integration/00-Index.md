# Assembly Integration

C is often called "portable assembly", but sometimes you need actual assembly for maximum performance, hardware access, or understanding how your code executes.

## 📋 Topics

### 🏗️ Basics & Syntax
1.  **[[01-Assembly-Basics|Assembly Basics (x86-64)]]**
    -   Intel vs AT&T Syntax
    -   Why learn Assembly?
2.  **[[19-ARM64-Assembly-Basics|ARM64 (AArch64) Basics]]**
    -   RISC architecture
    -   Registers (`X0`-`X30`) and Instructions (`LDR`, `STR`)
3.  **[[02-Registers-Memory|Registers and Memory (x86)]]**
    -   General Purpose Registers (`RAX`, `RBX`...)
    -   Stack Pointer (`RSP`) and Instruction Pointer (`RIP`)
4.  **[[21-Data-Types|Data Types & Endianness]]**
    -   Sizes (`BYTE`, `WORD`, `DWORD`, `QWORD`)
    -   Little Endian vs Big Endian
    -   Signed vs Unsigned Arithmetic
5.  **[[03-Common-Instructions|Common Instructions]]**
    -   Data Movement (`MOV`, `LEA`)
    -   Arithmetic (`ADD`, `SUB`, `MUL`)
6.  **[[22-Bit-Manipulation|Bit Manipulation]]**
    -   Shifts (`SHL`, `SAR`)
    -   Rotates (`ROL`, `ROR`)
    -   Byte Swap (`BSWAP`)
7.  **[[11-Floating-Point|Floating Point Assembly]]**
    -   `XMM` Registers (SSE/AVX)
    -   Scalar Operations (`ADDSS`, `MOVSS`)

### ⚙️ Control & Stack
8.  **[[07-Control-Flow|Control Flow]]**
    -   Compare (`CMP`, `TEST`)
    -   Conditional Jumps (`JE`, `JG`, `JNE`)
    -   Implementing Loops
9.  **[[08-Stack-Operations|Stack Operations]]**
    -   `PUSH` and `POP`
    -   Stack Frames (`RBP`)
    -   Alignment requirements
10. **[[04-Calling-Conventions|Calling Conventions]]**
    -   System V AMD64 ABI (Linux/Mac)
    -   Microsoft x64 ABI (Windows)
    -   Red Zone and Shadow Space

### 🔗 Linking & System
11. **[[20-ELF-File-Format|The ELF File Format]]**
    -   Structure of an executable (`.text`, `.data`)
    -   Relocations and Symbols
12. **[[13-Position-Independent-Code|Position Independent Code (PIC)]]**
    -   RIP-Relative Addressing
    -   Global Offset Table (GOT) and PLT
13. **[[09-System-Calls|System Calls]]**
    -   Invoking the kernel directly (`syscall`)
    -   vDSO (Virtual Dynamic Shared Object)
    -   Linux Syscall ABI vs Function Calls
14. **[[16-Linking-with-C|Linking Assembly with C]]**
    -   Calling assembly functions from C (`extern`)
    -   Writing separate `.s` files

### 🚀 Optimization & Advanced
15. **[[14-Assembly-Optimization|Optimization Techniques]]**
    -   Loop Unrolling
    -   Vectorization (SIMD)
    -   Eliminating Branches (`CMOV`)
16. **[[05-Inline-Assembly|Inline Assembly]]**
    -   GCC `asm` syntax
    -   Input/Output Constraints
17. **[[18-Assembly-Macros|Assembly Macros]]**
    -   Defining NASM macros (`%macro`)
    -   Local labels (`%%label`)
18. **[[06-Intrinsics|Compiler Intrinsics]]**
    -   Using built-in functions (`__builtin_popcount`, `__builtin_expect`)
    -   Atomic Operations (`__atomic_fetch_add`)

### 🕵️ Analysis & Security
19. **[[10-Debugging-Assembly|Debugging Assembly]]**
    -   Using GDB to view disassembly (`layout asm`)
    -   Stepping instructions (`si`, `ni`)
20. **[[15-Reverse-Engineering|Reverse Engineering]]**
    -   Recognizing function prologues/epilogues
    -   Identifying loops and switch statements
21. **[[17-Writing-Shellcode|Writing Shellcode]]**
    -   Avoiding Null Bytes
    -   Syscall injection

---
**Next Section**: [[../22-SIMD/00-Index|SIMD & Vectorization]]
