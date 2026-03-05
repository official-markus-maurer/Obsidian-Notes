# Assembly Basics (x86-64)

Assembly language is the lowest level of abstraction above machine code. It allows you to write instructions that the CPU executes directly.

## 📝 Why Learn Assembly?
1.  **Performance**: Optimize critical loops where the compiler fails.
2.  **Debugging**: Understand what your C code actually compiles to (essential for crash analysis).
3.  **Hardware Access**: Use CPU features not exposed by C (e.g., CPUID, Control Registers).

## ⚔️ Intel vs AT&T Syntax

There are two main syntaxes for x86 assembly.
-   **Intel**: Used by Windows (MASM), NASM, and default in GDB/LLDB.
-   **AT&T**: Used by Linux, GCC/Clang inline assembly (`asm`).

| Feature | Intel Syntax | AT&T Syntax |
| :--- | :--- | :--- |
| **Order** | `op dest, src` | `op src, dest` |
| **Registers** | `eax` | `%eax` |
| **Immediates** | `10` | `$10` |
| **Memory** | `[ebx]` | `(%ebx)` |
| **Size Suffix** | `mov dword ptr` | `movl` |

### Example: Move 10 into EAX

**Intel**:
```asm
mov eax, 10
```

**AT&T**:
```asm
movl $10, %eax
```

> **Note**: This guide focuses on **x86-64** architecture, which is the standard for modern desktops and servers.

---
[[00-Index|Back to Assembly Index]]
