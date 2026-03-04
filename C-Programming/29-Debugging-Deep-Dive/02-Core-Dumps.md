# Analyzing Core Dumps

A core dump is a snapshot of the program's memory at the time it crashed.

## 💥 Enabling Core Dumps
By default, systems often disable them (size limit 0).

```bash
ulimit -c unlimited
```

Now run your crashing program. It will produce a file named `core` or `core.PID`.

## 🕵️ Analyzing with GDB

```bash
gdb ./my_program core
```

GDB will open and show you exactly where the crash happened.

```bash
(gdb) bt
#0  0x00007f... in raise () from /lib64/libc.so.6
#1  0x00007f... in abort () from /lib64/libc.so.6
#2  0x000000... in vulnerable_function () at main.c:10
#3  0x000000... in main () at main.c:15
```

This allows you to debug crashes that happen on production servers where you can't run GDB interactively.

---
[[00-Index|Back to Debugging Index]]
