# IPC: Shared Memory

Shared memory is the fastest form of IPC because processes access the same chunk of RAM directly, avoiding kernel copying.

## 🧠 POSIX Shared Memory

### Steps
1.  **`shm_open`**: Create/Open a shared memory object.
2.  **`ftruncate`**: Set the size.
3.  **`mmap`**: Map the shared memory into the process's address space.
4.  **Read/Write**: Use pointers normally.
5.  **`munmap`**: Unmap.
6.  **`shm_unlink`**: Delete the object.

### Example (Writer)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    const char *msg = "Hello Shared Memory!";

    int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    
    void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    sprintf(ptr, "%s", msg);
    
    printf("Written to shared memory: %s\n", (char*)ptr);
    return 0;
}
```

> **Note**: You must link with `-lrt` (Realtime Library).

---
[[00-Index|Back to System Programming Index]]
