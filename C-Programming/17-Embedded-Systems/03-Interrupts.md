# Interrupt Handling

An Interrupt is a signal to the processor to stop what it's doing and handle a high-priority event.

## 🚨 The Flow
1.  **Event Occurs**: GPIO pin change, Timer overflow, UART data received.
2.  **Context Save**: CPU pushes current registers (PC, SP, etc.) to the stack.
3.  **ISR Execution**: The CPU jumps to the **Interrupt Service Routine** (ISR) defined in the Vector Table.
4.  **Context Restore**: CPU pops registers and resumes main program.

## 📝 Writing an ISR

In most embedded compilers (GCC for ARM), ISRs are just functions with specific names.

```c
// Name defined in startup file (e.g., startup_stm32.s)
void TIM2_IRQHandler(void) {
    // 1. Check if the update interrupt flag is set
    if (TIM2->SR & TIM_SR_UIF) {
        
        // 2. Clear the flag (CRITICAL!)
        TIM2->SR &= ~TIM_SR_UIF;
        
        // 3. Do work (Keep it short!)
        GPIOC->ODR ^= (1 << 13); // Toggle LED
    }
}
```

## ⚠️ Best Practices
1.  **Keep it Short**: Do minimal work (set a flag, copy data to a buffer) and exit. Long ISRs block other interrupts.
2.  **Use `volatile`**: Variables shared between main code and ISR must be `volatile`.
3.  **Atomic Access**: Be careful when modifying shared variables. You might need to disable interrupts temporarily.

---
[[00-Index|Back to Embedded Index]]
