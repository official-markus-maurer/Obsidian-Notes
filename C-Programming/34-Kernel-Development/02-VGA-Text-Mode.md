# Writing to Video Memory (VGA)

On x86, the video memory for text mode is mapped to address `0xb8000`.

## 📺 VGA Buffer Structure
The screen is a grid of 80x25 characters.
Each character uses 2 bytes:
1.  **ASCII Code** (1 byte)
2.  **Attribute Byte** (Color)

## 🎨 Color Byte
-   **Lower 4 bits**: Foreground color
-   **Upper 4 bits**: Background color

## 📝 Simple Kernel "Hello World"

```c
#include <stdint.h>

// Video memory starts here
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;

// VGA Colors
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_WHITE = 15,
};

uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

void kernel_main(void) {
    const char* str = "Hello Kernel World!";
    uint8_t color = VGA_COLOR_GREEN | VGA_COLOR_BLACK << 4;
    
    for (int i = 0; str[i] != '\0'; i++) {
        vga_buffer[i] = vga_entry(str[i], color);
    }
}
```

This code writes directly to the hardware video buffer to display text on the screen.

---
[[00-Index|Back to Kernel Index]]
