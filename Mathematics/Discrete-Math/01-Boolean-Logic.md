# Boolean Logic

Logic gates are the building blocks of CPUs.

## Operators
-   **AND (`&`)**: True if both are true. `1 & 1 = 1`.
-   **OR (`|`)**: True if at least one is true. `1 | 0 = 1`.
-   **XOR (`^`)**: True if inputs are different. `1 ^ 0 = 1`.
-   **NOT (`~`)**: Inverts the bits. `~0 = 1`.

## Short-Circuit Evaluation (C Specific)
In C, `&&` and `||` short-circuit.
```c
if (ptr != NULL && ptr->value > 0) { ... }
```
If `ptr` is NULL, the second part is NEVER evaluated, preventing a crash.

---
[[00-Index|Back to Index]]
