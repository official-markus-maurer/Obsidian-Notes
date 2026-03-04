# GDB Advanced Techniques

The GNU Debugger (GDB) is powerful. Most people only know `break` and `run`.

## 🎯 Watchpoints
Stop execution when a variable *changes*.

```bash
(gdb) watch my_variable
(gdb) continue
# GDB stops when my_variable is written to.
```

## ❓ Conditional Breakpoints
Stop only when a condition is met.

```bash
(gdb) break loop_function if i == 999
```

## 📜 TUI Mode (Text User Interface)
View source code alongside the debugger.
```bash
(gdb) layout src
(gdb) layout split # Shows source and assembly
```

## 🐍 Python Scripting
You can automate GDB with Python.
```python
# my_script.py
import gdb

class HelloCommand(gdb.Command):
    def __init__(self):
        super(HelloCommand, self).__init__("hello", gdb.COMMAND_USER)
    
    def invoke(self, arg, from_tty):
        print("Hello from GDB!")

HelloCommand()
```
Run inside GDB: `source my_script.py` -> `hello`.

---
[[00-Index|Back to Debugging Index]]
