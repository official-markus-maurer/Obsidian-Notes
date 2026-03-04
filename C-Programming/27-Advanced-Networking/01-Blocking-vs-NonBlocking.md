# Blocking vs Non-Blocking I/O

## 🛑 Blocking I/O (Default)
When you call `recv()` or `accept()`, the program **stops** (sleeps) until data arrives.
-   **Pros**: Simple logic.
-   **Cons**: Need one thread/process per client. Threads are expensive (memory, context switching).

## 🏃 Non-Blocking I/O
The function returns **immediately**.
-   If data is ready: It returns the data.
-   If no data: It returns `-1` and sets `errno` to `EWOULDBLOCK` or `EAGAIN`.

### Setting Non-Blocking Mode (POSIX)

```c
#include <fcntl.h>

void set_nonblocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) return;
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}
```

### Busy Waiting (Bad!)
```c
// Don't do this! CPU usage will hit 100%.
while (1) {
    int n = recv(sock, buf, len, 0);
    if (n == -1 && errno == EWOULDBLOCK) {
        continue; // Busy loop
    }
    // Handle data
}
```
**Solution**: Use I/O Multiplexing (`select`/`poll`/`epoll`) to sleep until *something* happens.

---
[[00-Index|Back to Advanced Networking Index]]
