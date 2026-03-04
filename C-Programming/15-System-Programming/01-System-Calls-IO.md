# System Calls (File I/O)

Standard C library functions (`fopen`, `fprintf`) are high-level wrappers around OS system calls. System calls interact directly with the kernel.

## 📂 File Descriptors
Instead of `FILE*`, system calls use **File Descriptors** (integers).
-   `0`: Standard Input (stdin)
-   `1`: Standard Output (stdout)
-   `2`: Standard Error (stderr)

## 🛠️ Key Functions (`<fcntl.h>`, `<unistd.h>`)

### `open`
Opens a file and returns a file descriptor.
```c
int fd = open("file.txt", O_RDONLY); // or O_WRONLY | O_CREAT
if (fd == -1) { perror("open"); }
```

### `write`
Writes bytes to a file descriptor.
```c
char *msg = "Hello\n";
write(fd, msg, strlen(msg));
// Write to stdout
write(1, "Log message\n", 12);
```

### `read`
Reads bytes into a buffer. Returns number of bytes read.
```c
char buffer[100];
ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
```

### `close`
Closes the file descriptor.
```c
close(fd);
```

## ⚖️ Buffered vs Unbuffered
-   `printf`/`fwrite` are **buffered**. They store data in user space and only call the kernel when the buffer is full (faster for many small writes).
-   `write` is **unbuffered**. It calls the kernel immediately (slower overhead per call, but immediate).

---
[[00-Index|Back to System Programming Index]]
