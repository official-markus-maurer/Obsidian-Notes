# Signals

Signals are software interrupts sent to a process to notify it of an event (e.g., user pressed Ctrl+C, segmentation fault, timer expired).

## 🔔 Common Signals

-   `SIGINT`: Interrupt (Ctrl+C). Default: Terminate.
-   `SIGTERM`: Terminate request. Default: Terminate.
-   `SIGSEGV`: Segmentation Fault. Default: Dump core and terminate.
-   `SIGKILL`: Kill immediately. Cannot be caught or ignored.

## 🛡️ Handling Signals

You can register a custom function to handle signals using `signal()` or the more robust `sigaction()`.

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal Handler
void handle_sigint(int sig) {
    printf("\nCaught signal %d (SIGINT). Exiting gracefully...\n", sig);
    // Cleanup code here...
    _exit(0);
}

int main() {
    // Register handler
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to test...\n");
    while(1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
```

> **Warning**: Signal handlers should be short and safe. Avoid calling functions that are not "Async-Signal-Safe" (like `printf` or `malloc`) inside a handler if possible, or be very careful.

---
[[00-Index|Back to System Programming Index]]
