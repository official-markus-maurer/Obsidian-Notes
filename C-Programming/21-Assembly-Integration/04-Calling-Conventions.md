# Calling Conventions (x86-64)

The **Calling Convention** is a set of rules that functions must follow to communicate (pass arguments and return values).

## 🌍 The Two Standards

### 1. System V AMD64 ABI (Linux / macOS)

**Arguments**:
Passed in registers (left to right):
1.  `RDI`
2.  `RSI`
3.  `RDX`
4.  `RCX`
5.  `R8`
6.  `R9`
7.  Stack (pushed in reverse order)

**Return Value**:
-   `RAX` (64-bit integer / pointer)
-   `XMM0` (Floating point)

**Caller-Saved (Volatile)**:
Registers the *caller* must save if they want to keep the value: `RAX`, `RCX`, `RDX`, `RSI`, `RDI`, `R8`-`R11`.

**Callee-Saved (Non-Volatile)**:
Registers the *called function* must save/restore: `RBX`, `RSP`, `RBP`, `R12`-`R15`.

### 🟥 The Red Zone (System V only)
The 128 bytes **below** the stack pointer (`RSP` to `RSP-128`) are reserved for the current function.
-   **Leaf functions** (functions that call no other functions) can use this space for local variables without adjusting `RSP` (`push`/`sub`).
-   Signal handlers and Interrupts must NOT overwrite this area.

### 2. Microsoft x64 ABI (Windows)

**Arguments**:
Passed in registers:
1.  `RCX`
2.  `RDX`
3.  `R8`
4.  `R9`
5.  Stack (pushed in reverse order)

**Shadow Space (Home Space)**:
The caller *must* reserve **32 bytes** of stack space (shadow space) right before the `CALL`.
-   This allows the callee to spill `RCX`, `RDX`, `R8`, `R9` onto the stack if needed (e.g., for debugging or varargs).
-   The caller does NOT clean this up; `RSP` is restored after the call returns.

**Return Value**:
-   `RAX` (Integer / Pointer)
-   `XMM0` (Float)

**Volatile Registers**:
`RAX`, `RCX`, `RDX`, `R8`-`R11`.

**Non-Volatile Registers**:
`RBX`, `RBP`, `RDI`, `RSI`, `R12`-`R15`, `XMM6`-`XMM15`.

## ⚠️ Implications for Inline Assembly

If you write inline assembly, you must respect the ABI of your platform.
-   On Linux, `RDI` holds the first argument.
-   On Windows, `RCX` holds the first argument.

To write portable assembly, use GCC constraints (`"D"`, `"c"`) rather than hardcoding registers (`%rdi`, `%rcx`).

---
[[00-Index|Back to Assembly Index]]
