# Time Travel Debugging (rr)

`rr` (Record and Replay) is a debugging tool for Linux that records a program execution and allows you to replay it deterministically.

## ⏪ The Problem
Bugs like race conditions or memory corruption are often intermittent. "It works on my machine" or "It happens 1 in 100 times".

## 📼 Recording
```bash
rr record ./my_program
```
This runs the program and saves the trace to disk.

## 📺 Replaying
```bash
rr replay
```
This opens GDB. You can now use **reverse execution** commands!

```bash
(gdb) continue
# Crash happens
(gdb) reverse-continue
# Go BACKWARDS to see what led to the crash
(gdb) reverse-step
(gdb) watch my_var
(gdb) reverse-continue
# Stops at the moment my_var was last changed!
```

This is a superpower for debugging complex C bugs.

---
[[00-Index|Back to Debugging Index]]
