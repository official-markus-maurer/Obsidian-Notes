# Analyzing Core Dumps

A core dump is a snapshot of the program's memory at the time it crashed. It allows "post-mortem" debugging without needing to reproduce the crash live.

## 💥 Enabling Core Dumps
By default, systems often disable them (size limit 0) to save disk space.

```bash
# Check current limit
ulimit -c

# Enable unlimited core dump size
ulimit -c unlimited
```

Now run your crashing program. It will produce a file named `core` or `core.<PID>`.
*Note: On Ubuntu/systemd, cores might be handled by `apport` or `systemd-coredump` (check `/var/lib/systemd/coredump/`).*

## 🕵️ Analyzing with GDB

You need the executable (with debug symbols `-g`) and the core file.

```bash
gdb ./my_program core
```

GDB will open and show you exactly where the crash happened.

```gdb
(gdb) bt
#0  0x00007f... in raise () from /lib64/libc.so.6
#1  0x00007f... in abort () from /lib64/libc.so.6
#2  0x000000... in vulnerable_function () at main.c:10
#3  0x000000... in main () at main.c:15
```

## 🔍 Inspecting State
Once loaded, you can inspect variables just like a live session.

```gdb
(gdb) frame 2       # Jump to stack frame #2 (your function)
(gdb) print buffer  # See what data caused the crash
(gdb) info locals
```

## 💡 Why use Core Dumps?
1.  **Production Crashes**: Servers can capture a core dump when a service dies, allowing devs to debug it later.
2.  **Heisenbugs**: Bugs that disappear when you attach a debugger (timing issues) might be captured in a core dump.

---
[[00-Index|Back to Debugging Index]]
