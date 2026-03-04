# MISRA C (Motor Industry Software Reliability Association)

MISRA C is a set of software development guidelines for the C programming language. Its primary goal is to facilitate code safety, security, portability, and reliability in the context of embedded systems.

## Core Philosophy
The C language is powerful but dangerous. It allows constructs that can lead to undefined behavior, implementation-defined behavior, or simply confusing code. MISRA C restricts the language to a safer subset.

## Key Rules (Examples)

### 1. No Dynamic Memory Allocation (Rule 21.3)
`malloc`, `calloc`, `realloc`, and `free` are forbidden in many safety-critical systems.
**Reason**: Fragmentation, memory leaks, and non-deterministic execution time.
**Alternative**: Static allocation or memory pools (see [[../04-Pointers-and-Memory/09-Memory-Pools|Memory Pools]]).

### 2. No Recursion (Rule 17.2)
Functions must not call themselves, directly or indirectly.
**Reason**: Risk of stack overflow.
**Alternative**: Iteration (loops).

### 3. Initialize Variables Before Use (Rule 9.1)
Automatic variables (stack) must be initialized.
```c
// Bad
int x;
if (condition) x = 5;
use(x); // x might be uninitialized

// Good
int x = 0;
```

### 4. Restricted Pointer Arithmetic
Pointer arithmetic is only allowed on pointers that point to an array.
**Reason**: Preventing out-of-bounds access.

### 5. Single Point of Exit (Advisory)
Ideally, a function should have one `return` statement at the end.
**Reason**: Simplifies control flow analysis and resource cleanup.

## Compliance
To ensure MISRA compliance, you typically use **Static Analysis Tools** like:
-   PC-Lint
-   Cppcheck (partial support)
-   Coverity
-   Parasoft

## Example: MISRA-Compliant Code
```c
#include <stdint.h>

/* Use fixed-width integers */
void safe_add(int32_t a, int32_t b, int32_t *result) {
    /* Check for null pointer */
    if (result != NULL) {
        /* Check for overflow */
        if ((b > 0) && (a > (INT32_MAX - b))) {
            *result = INT32_MAX; /* Saturate */
        } else if ((b < 0) && (a < (INT32_MIN - b))) {
            *result = INT32_MIN; /* Saturate */
        } else {
            *result = a + b;
        }
    }
}
```

---
[[00-Index|Back to Index]] | [[02-CERT-C|Next: CERT C]]
