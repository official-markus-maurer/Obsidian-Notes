# Signals

Signals are software interrupts sent to a process to notify it of an event.

## Common Signals
-   **SIGINT (2)**: Interrupt from keyboard (Ctrl+C). Default action: Terminate.
-   **SIGSEGV (11)**: Segmentation Fault (Invalid memory access). Default: Core Dump.
-   **SIGKILL (9)**: Force kill. Cannot be caught or ignored.
-   **SIGTERM (15)**: Request to terminate. Can be caught for cleanup.

## Handling Signals
You can register a "Signal Handler" function to intercept signals (except SIGKILL/SIGSTOP).

```c
void handler(int sig) {
    printf("Caught signal %d\n", sig);
}
```

---
[[00-Index|Back to OS Index]]
