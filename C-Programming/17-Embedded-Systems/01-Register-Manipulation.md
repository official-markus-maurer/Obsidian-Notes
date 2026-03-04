# Register Manipulation

In embedded systems, you control hardware by reading and writing to specific memory addresses called **Registers**.

## 🔢 Bitwise Operations

You rarely change an entire register. Instead, you modify specific bits.

### Setting a Bit (OR)
To set bit `n` to 1:
```c
REGISTER |= (1 << n);
```

### Clearing a Bit (AND NOT)
To set bit `n` to 0:
```c
REGISTER &= ~(1 << n);
```

### Toggling a Bit (XOR)
To flip bit `n`:
```c
REGISTER ^= (1 << n);
```

### Checking a Bit
To check if bit `n` is 1:
```c
if (REGISTER & (1 << n)) {
    // Bit is set
}
```

## 🏗️ Structs for Registers

Instead of raw pointers, use structs to map memory.

```c
typedef struct {
    volatile uint32_t CR;  // Control Register
    volatile uint32_t SR;  // Status Register
    volatile uint32_t DR;  // Data Register
} UART_TypeDef;

#define UART1 ((UART_TypeDef *) 0x40011000)

void UART_Send(char c) {
    while (!(UART1->SR & (1 << 7))); // Wait for Empty
    UART1->DR = c;
}
```

---
[[00-Index|Back to Embedded Index]]
