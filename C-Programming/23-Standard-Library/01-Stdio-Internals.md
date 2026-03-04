# Stdio Internals

The `stdio.h` library uses buffering to minimize system calls (which are expensive).

## 📦 The `FILE` Structure

When you call `fopen`, it allocates a `FILE` struct that contains:
1.  **Buffer**: A chunk of memory (usually 4KB or 8KB).
2.  **Position**: Current read/write position in the buffer.
3.  **File Descriptor**: The integer handle for the OS kernel.

## 🔄 Buffering Modes

1.  **Full Buffering (`_IOFBF`)**:
    -   Data is stored in the buffer until it is full.
    -   Default for files.
2.  **Line Buffering (`_IOLBF`)**:
    -   Data is flushed when a newline `\n` is encountered.
    -   Default for `stdout` (terminal).
3.  **No Buffering (`_IONBF`)**:
    -   Data is flushed immediately.
    -   Default for `stderr`.

### Manual Flushing
Use `fflush(FILE *stream)` to force the buffer to write to the OS.

```c
printf("Loading..."); // Might not appear immediately
fflush(stdout);       // Forces it to appear
```

---
[[00-Index|Back to Stdlib Index]]
