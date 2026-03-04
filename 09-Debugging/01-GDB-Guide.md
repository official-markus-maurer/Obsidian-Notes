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
-   `info break`: List all breakpoints.
-   `delete 1`: Delete breakpoint #1.

### Stepping
-   `next` or `n`: Execute next line (steps **over** function calls).
-   `step` or `s`: Execute next line (steps **into** function calls).
-   `continue` or `c`: Continue execution until the next breakpoint.
-   `finish`: Run until the current function returns.

### Inspecting Variables
-   `print var_name` or `p var_name`: Print the value of a variable.
-   `display var_name`: Automatically print the variable's value every time execution stops.
-   `info locals`: Print all local variables.

### Backtrace
If your program crashes (Segfault), use `backtrace` (or `bt`) to see the function call stack that led to the crash.

```gdb
(gdb) bt
#0  0x0000555555555149 in bad_function () at program.c:5
#1  0x0000555555555163 in main () at program.c:10
```

### TUI Mode (Text User Interface)
Press `Ctrl + X` then `A` (or type `tui enable`) to see the source code in a split window while debugging. It's a game changer!

### Quitting
-   `quit` or `q`: Exit GDB.

---
[[00-Index|Back to Debugging Index]]
