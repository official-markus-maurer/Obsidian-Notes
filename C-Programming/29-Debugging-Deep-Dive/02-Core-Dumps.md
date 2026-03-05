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

### Systemd Coredump
On modern Linux (Ubuntu, Fedora, Arch), core dumps are managed by `systemd-coredump`.
1.  **List dumps**: `coredumpctl list`
2.  **Debug latest**: `coredumpctl debug` (Automatically opens GDB).
3.  **Extract**: `coredumpctl dump <PID> -o core.dump`

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
(gdb) info registers
```

## 💡 Why use Core Dumps?
1.  **Production Crashes**: Servers can capture a core dump when a service dies, allowing devs to debug it later.
2.  **Heisenbugs**: Bugs that disappear when you attach a debugger (timing issues) might be captured in a core dump.

## 📦 Minidumps (Google Breakpad / Crashpad)

Full core dumps can be huge (GBs). Applications like Chrome and Firefox use **Minidumps**.
-   Contains only stack trace, registers, and loaded modules.
-   Much smaller (MBs).
-   Requires special tools (`minidump_stackwalk`) to analyze.

---
[[00-Index|Back to Debugging Index]]
