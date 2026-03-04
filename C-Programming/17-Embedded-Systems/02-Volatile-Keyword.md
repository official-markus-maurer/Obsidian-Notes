# The `volatile` Keyword

The `volatile` keyword is the most misunderstood and critical concept in embedded C.

## 🛑 What it does
It tells the compiler: **"The value of this variable may change at any time, without any code here modifying it."**

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
The compiler sees that the loop body doesn't change `*status_reg`. It optimizes the code to read the value **once** into a register and loop forever if it's 0.
```assembly
mov r0, [0x1234]  ; Read once
loop:
cmp r0, 0
je loop           ; Infinite loop!
```

**With `volatile`**:
```c
volatile uint32_t *status_reg = (uint32_t *)0x1234;
```
The compiler generates code to read from memory **every iteration**.

## 📝 Rule of Thumb
Use `volatile` for:
1.  Memory-mapped hardware registers.
2.  Global variables modified by an Interrupt Service Routine (ISR).
3.  Global variables shared between threads (though `atomic` is preferred).

---
[[00-Index|Back to Embedded Index]]
