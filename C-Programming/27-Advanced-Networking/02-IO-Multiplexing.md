# I/O Multiplexing

I/O Multiplexing allows a single thread to monitor multiple file descriptors (sockets) and wait for *any* of them to become ready.

## 1. `select()`
The oldest, most portable method.
-   **Limit**: Monitors up to `FD_SETSIZE` (usually 1024) sockets.
-   **Performance**: O(N). It scans the entire list of sockets to find which one is ready.

## 2. `poll()`
Similar to `select`, but uses an array of structs.
-   **Limit**: No hard limit on file descriptors.
-   **Performance**: O(N). Still scans the whole array.

## 3. `epoll()` (Linux Only)
The gold standard for high performance (Nginx, Redis, Node.js).
-   **Performance**: O(1). The OS maintains a list of *only* the ready events.
-   **Mechanism**: You register events once, and `epoll_wait` returns only the sockets that triggered an event.

### `epoll` Example

```c
#include <sys/epoll.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_EVENTS 10

int main() {
    struct epoll_event ev, events[MAX_EVENTS];
    int epollfd = epoll_create1(0);
    
    // Add socket to monitor (assume listen_sock exists)
    ev.events = EPOLLIN; // Read available
    ev.data.fd = listen_sock;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev);

    while (1) {
        // Wait for events (blocks CPU efficiently)
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        
        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                // Accept new connection
            } else {
                // Handle data from client
            }
        }
    }
    return 0;
}
```

---
[[00-Index|Back to Advanced Networking Index]]
