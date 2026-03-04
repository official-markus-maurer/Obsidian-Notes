# Interrupt Handling

An Interrupt is a hardware signal that forces the CPU to pause its current task and execute a high-priority function called an **Interrupt Service Routine (ISR)**.

## 🚨 The Flow
1.  **Event Occurs**: Button press (GPIO), Timer overflow, UART data received.
2.  **Context Save**: CPU pushes current registers (PC, SP, R0-R3, LR) to the stack.
3.  **ISR Execution**: The CPU jumps to the address in the **Vector Table**.
4.  **Context Restore**: CPU pops registers and resumes the main program exactly where it left off.

## 📝 Writing an ISR

In most embedded compilers (e.g., GCC for ARM Cortex-M), ISRs are standard C functions with specific names defined in the startup file.

```c
// TIM2_IRQHandler is the vector name for Timer 2
void TIM2_IRQHandler(void) {
    // 1. Check if the update interrupt flag is set
    if (TIM2->SR & TIM_SR_UIF) {
        
        // 2. Clear the flag (CRITICAL!)
        // If you don't clear it, the ISR will run again immediately (infinite loop).
        TIM2->SR &= ~TIM_SR_UIF;
        
        // 3. Do work (Keep it short!)
        GPIOC->ODR ^= (1 << 13); // Toggle LED
    }
}
```

## ⚠️ Best Practices (The Golden Rules)

### 1. Keep it Short
ISRs block other interrupts (usually). Long ISRs cause system lag or missed data.
-   **Bad**: `printf`, `delay`, complex math.
-   **Good**: Set a flag, copy a byte to a ring buffer, increment a counter.

### 2. Use `volatile`
Variables shared between `main()` and an ISR must be `volatile`.

```c
volatile int flag = 0;

void EXTI0_IRQHandler(void) {
    flag = 1; // Signal main loop
    // Clear pending bit...
}

int main() {
    while (1) {
        if (flag) {
            process_event();
            flag = 0;
        }
    }
}
```

### 3. Atomic Access
Reading a multi-byte variable (like `long long` or `struct`) in `main()` can be interrupted by an ISR halfway through.
**Solution**: Disable interrupts briefly.

```c
__disable_irq();
long long copy = shared_64bit_counter;
__enable_irq();
```

---
[[00-Index|Back to Embedded Index]]
