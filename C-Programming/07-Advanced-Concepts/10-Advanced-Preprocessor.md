# Advanced Preprocessor

The C Preprocessor is powerful metaprogramming tool.

## 🌀 Variadic Macros

Macros can accept a variable number of arguments using `...` and `__VA_ARGS__`.

```c
#define LOG(level, ...) printf("[" level "] " __VA_ARGS__)

LOG("INFO", "Value is %d\n", 42); 
// Expands to: printf("[" "INFO" "] " "Value is %d\n", 42);
```

## ❌ X Macros

A technique to maintain parallel lists of code (e.g., Enum + String Array) from a single source of truth.

### Definition
Define a list macro:
```c
#define COLORS \
    X(RED) \
    X(GREEN) \
    X(BLUE)
```

### Usage 1: Generate Enum
```c
#define X(name) name,
enum Color {
    COLORS
};
#undef X
```

### Usage 2: Generate Strings
```c
#define X(name) #name,
char *ColorStrings[] = {
    COLORS
};
#undef X
```

Now `ColorStrings[RED]` is `"RED"`. If you add a color to `COLORS`, both the enum and the string array update automatically.

---
[[00-Index|Back to Advanced Index]]
