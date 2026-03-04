# The `volatile` Keyword

The `volatile` keyword is the most misunderstood and critical concept in embedded C.

## 🛑 What it does
It tells the compiler: **"The value of this variable may change at any time, without any code here modifying it."**

This forces the compiler to reload the value from memory **every single time** it is accessed, disabling optimizations like caching in a register.

## ⚡ Why is it needed?

### Scenario: Polling a Hardware Flag

```c
uint32_t *status_reg = (uint32_t *)0x1234;

// Wait until bit 0 becomes 1
while ((*status_reg & 1) == 0) {
    // Wait
}
```

**Without `volatile`**:
The compiler sees that the loop body doesn't change `*status_reg`. It assumes the value is constant and optimizes the loop to:
1.  Read `*status_reg` once.
2.  Check if bit 0 is 0.
3.  If so, loop forever (infinite loop).

**With `volatile`**:
```c
volatile uint32_t *status_reg = (uint32_t *)0x1234;
```
The compiler generates code to read from memory address `0x1234` **every iteration**, allowing it to see the hardware update the bit.

## 📝 Rule of Thumb
Use `volatile` for:
1.  **Memory-mapped hardware registers** (e.g., UART status, GPIO input).
2.  **Global variables shared with an ISR** (Interrupt Service Routine).
3.  **Global variables shared between threads** (though `_Atomic` is better in C11).

## ❌ What it is NOT
-   `volatile` is **NOT** a mutex. It does not prevent race conditions.
-   It does **NOT** guarantee atomic access (reading a 64-bit volatile on a 32-bit CPU can be interrupted).

---
[[00-Index|Back to Embedded Index]]
