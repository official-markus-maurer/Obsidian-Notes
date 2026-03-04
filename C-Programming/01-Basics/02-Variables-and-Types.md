# Variables and Data Types

## 📦 Variables
A variable is a container for storing data values. In C, variables must be declared before they are used.

### Syntax
```c
// C89: Declarations must be at the start of a block
void func() {
    int x;
    x = 5;
}

// C99+: Declarations can be anywhere
void func() {
    func_call();
    int x = 5;
}
```

## 📊 Primitive Data Types

| Type | Description | Format | Size (Typical) | Standard |
|------|-------------|--------|----------------|----------|
| `int` | Integer | `%d` | 4 bytes | C89 |
| `char` | Character | `%c` | 1 byte | C89 |
| `float` | Float | `%f` | 4 bytes | C89 |
| `double` | Double | `%lf` | 8 bytes | C89 |
| `long long` | Big Int | `%lld` | 8 bytes | **C99** |
| `_Bool` | Boolean | `%d` | 1 byte | **C99** |

## 🧠 Boolean Types
### Pre-C99
C didn't have a boolean type. Programmers used `int` (0 is false, non-zero is true).

### C99 (`<stdbool.h>`)
Introduced `_Bool` type and macros `bool`, `true`, `false`.
```c
#include <stdbool.h>
bool isValid = true;
```

### C23
`bool`, `true`, and `false` are now keywords. No header needed.

## 📏 Fixed-Width Integers (C99)
Included via `<stdint.h>`. Essential for systems programming where exact size matters.

| Type | Size | Format (via `<inttypes.h>`) |
|------|------|-----------------------------|
| `int8_t` | 1 byte | `PRId8` |
| `uint8_t` | 1 byte (unsigned) | `PRIu8` |
| `int32_t` | 4 bytes | `PRId32` |
| `uint64_t` | 8 bytes | `PRIu64` |

```c
#include <stdint.h>
#include <inttypes.h>

uint64_t big_num = 9000000000;
printf("Num: %" PRIu64 "\n", big_num);
```

## 🔒 Constants
-   `const int x = 5;`: Read-only variable.
-   `#define PI 3.14`: Preprocessor macro (text replacement).
-   `enum { RED, GREEN }`: Enumerated constants.

---
[[00-Index|Back to Basics Index]]
