# LLDB Guide

LLDB is the default debugger for the LLVM/Clang project (used on macOS and often on Linux). Its commands are similar to GDB but with some syntax differences.

## 🛠️ Preparation

Compile with `-g`:
```bash
clang -g program.c -o program
```

## 🚀 Basic Commands Cheat Sheet

| Action | GDB | LLDB |
| :--- | :--- | :--- |
| **Start Debugger** | `gdb ./program` | `lldb ./program` |
| **Run Program** | `run` | `run` or `r` |
| **Set Breakpoint** | `break main` | `breakpoint set --name main` (or `b main`) |
| **Set Breakpoint (Line)**| `break 10` | `breakpoint set --file program.c --line 10` (or `b program.c:10`) |
| **Next Line (Step Over)**| `next` (n) | `thread step-over` (n) |
| **Step Into** | `step` (s) | `thread step-in` (s) |
| **Continue** | `continue` (c) | `process continue` (c) |
| **Print Variable** | `print x` (p x) | `frame variable x` (or `v x` / `p x`) |
| **Backtrace** | `bt` | `thread backtrace` (bt) |
| **List Breakpoints** | `info break` | `breakpoint list` |

## 🕵️ Advanced Commands

### Examining Memory
-   `memory read <address>`: Read memory at address.
-   `x <address>`: Short alias for memory read.
-   `memory read -f x -c 10 <address>`: Read 10 items in hex format.

### Watchpoints
-   `watchpoint set variable myVar`: Stop when `myVar` is modified.
-   `watchpoint set expression -- 0x123456`: Stop when address is written to.

### Registers
-   `register read`: Show general purpose registers.
-   `register read rax`: Show specific register (e.g., RAX).

### Evaluating Expressions
You can run arbitrary C code inside the debugger.
-   `expr int $i = 10`: Create a debugger variable.
-   `expr func()`: Call a function from your code.
-   `expr ptr = 0`: Change a value in memory on the fly!

## 💡 Tips

-   LLDB's output is often more colorful and readable than GDB's default output.
-   Use `help` to explore commands.
-   If you are on macOS, you are likely using LLDB by default even if you type `gcc` (which is often aliased to `clang`).

---
[[00-Index|Back to Debugging Index]]
