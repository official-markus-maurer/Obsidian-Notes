# IPC: Pipes and FIFOs

Inter-Process Communication (IPC) allows processes to exchange data.

## 🚰 Pipes (Unnamed Pipes)

Pipes are unidirectional channels for communication between related processes (e.g., parent and child).

### `pipe()`
Creates a pair of file descriptors:
-   `fd[0]`: Read end.
-   `fd[1]`: Write end.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); // Create pipe
    
    if (fork() == 0) {
        // Child: Write to pipe
        close(fd[0]); // Close unused read end
        char *msg = "Hello from child";
        write(fd[1], msg, 16);
        close(fd[1]);
    } else {
        // Parent: Read from pipe
        close(fd[1]); // Close unused write end
        char buffer[100];
        read(fd[0], buffer, 100);
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
```

## 📛 Named Pipes (FIFOs)

FIFOs are pipes that exist as files on the filesystem. They allow communication between *unrelated* processes.

1.  **Create FIFO**: `mkfifo("my_fifo", 0666)`
2.  **Writer**: Opens "my_fifo" for writing (`open`, `write`).
3.  **Reader**: Opens "my_fifo" for reading (`open`, `read`).

Blocks until both ends are open.

---
[[00-Index|Back to System Programming Index]]
