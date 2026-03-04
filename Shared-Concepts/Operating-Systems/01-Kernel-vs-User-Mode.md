# Kernel vs User Mode

To protect the system from crashing, modern CPUs operate in at least two modes.

## User Mode (Ring 3)
-   **Restrictions**: Cannot access hardware directly. Cannot modify critical CPU registers.
-   **Crash Impact**: Only the application crashes.
-   **Normal Code**: Your C programs run here.

## Kernel Mode (Ring 0)
-   **Privileges**: Full access to all hardware and memory.
-   **Crash Impact**: The entire OS crashes (Blue Screen of Death / Kernel Panic).
-   **Execution**: Drivers, Kernel code.

## Context Switching
Switching between User and Kernel mode is expensive. It involves saving registers, flushing caches (TLB), and changing privilege levels. Minimizing context switches is key to high performance.

---
[[00-Index|Back to OS Index]]
