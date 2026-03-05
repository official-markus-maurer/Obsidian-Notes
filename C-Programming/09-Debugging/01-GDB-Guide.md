# GDB (GNU Debugger) Guide

GDB is the standard debugger for GNU systems. It allows you to see what is happening inside your program while it executes or what it was doing at the moment it crashed.

## 🛠️ Preparation

To use GDB, you must compile your C program with the `-g` flag to include debugging information.

```bash
gcc -g program.c -o program
```

## 🚀 Basic Commands

### Starting GDB
```bash
gdb ./program
```

### Running the Program
-   `run` or `r`: Starts the program.
-   `run arg1 arg2`: Starts the program with arguments.

### Breakpoints
-   `break main`: Set a breakpoint at the `main` function.
-   `break 10`: Set a breakpoint at line 10.
-   `break file.c:15`: Break at line 15 of `file.c`.
-   **Conditional Breakpoint**: `break 20 if x > 5` (Only stops if `x` is greater than 5).
-   `info break`: List all breakpoints.
-   `delete 1`: Delete breakpoint #1.

### Stepping
-   `next` or `n`: Execute next line (steps **over** function calls).
-   `step` or `s`: Execute next line (steps **into** function calls).
-   `continue` or `c`: Continue execution until the next breakpoint.
-   `finish`: Run until the current function returns.
-   `until 20`: Continue running until line 20.

### Inspecting Variables
-   `print var` or `p var`: Print the value of a variable.
-   `p/x var`: Print in Hexadecimal.
-   `p/t var`: Print in Binary.
-   `display var`: Automatically print the variable's value every time execution stops.
-   `info locals`: Print all local variables.

## 🕵️ Advanced Inspection

### Examining Memory (`x`)
The `x` command lets you examine raw memory addresses.
**Syntax**: `x /<count><format><size> <address>`

-   `x/10xw &arr`: Examine 10 (10) He**x** (x) **W**ords (w) starting at address `&arr`.
-   `x/s str`: Examine memory as a **S**tring (s).
-   `x/i $pc`: Examine the **I**nstruction (i) at the Program Counter (PC).

### Watchpoints
Stop execution when a variable's value *changes*.
-   `watch myVar`: Break when `myVar` is written to.
-   `rwatch myVar`: Break when `myVar` is read.

### TUI Mode (Text User Interface)
Press `Ctrl + X` then `A` (or type `tui enable`) to see the source code in a split window while debugging.
-   `layout src`: Show source code.
-   `layout asm`: Show assembly code.
-   `layout reg`: Show CPU registers.

## 🐍 Python API
GDB has a full Python interpreter built-in! You can script complex debugging tasks.

```python
# Save as script.py
# Usage: source script.py in GDB

import gdb

class HelloCommand(gdb.Command):
    """Prints Hello World."""
    def __init__(self):
        super(HelloCommand, self).__init__("hello", gdb.COMMAND_USER)

    def invoke(self, arg, from_tty):
        print("Hello from Python!")

HelloCommand()
```

## 💥 Handling Crashes (Core Dumps)

If your program crashes (Segfault), you can debug the "Core Dump" file to see the state of the program at the moment of the crash.

1.  Enable core dumps: `ulimit -c unlimited`
2.  Run program (let it crash): `./program`
3.  Debug core: `gdb ./program core`
4.  Use `bt` (Backtrace) to see where it died.

```gdb
(gdb) bt
#0  0x0000555555555149 in bad_function () at program.c:5
#1  0x0000555555555163 in main () at program.c:10
```

---
[[00-Index|Back to Debugging Index]]
