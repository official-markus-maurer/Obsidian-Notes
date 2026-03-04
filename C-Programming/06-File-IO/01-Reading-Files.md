# Reading Files

## 📂 Opening a File

Use `fopen()` to open a file. It returns a `FILE*` pointer (a handle to the file stream).

```c
#include <stdio.h>
#include <stdlib.h>

FILE *fptr;
fptr = fopen("filename.txt", "r"); // "r" for read mode
```

### Modes
| Mode | Description | behavior if missing |
| :--- | :--- | :--- |
| `"r"` | Read text | Returns NULL |
| `"rb"` | Read binary | Returns NULL |
| `"r+"` | Read/Write text | Returns NULL |

### Error Handling
Always check if the file opened successfully. Use `perror` to print the exact system error (e.g., "Permission denied", "No such file").

```c
if (fptr == NULL) {
    perror("Error opening file");
    return 1;
}
```

## 📖 Reading Methods

### 1. `fgetc` (Character by Character)
Reads a single character. Returns `EOF` (End of File) when done.

```c
int ch; // Must be int to handle EOF (-1)
while ((ch = fgetc(fptr)) != EOF) {
    putchar(ch);
}
```

### 2. `fgets` (Line by Line)
Reads a string until a newline or end of file. **Safer than `gets`** because you specify the buffer size.

```c
char buffer[256];
// Reads up to 255 chars or until newline
while (fgets(buffer, sizeof(buffer), fptr)) {
    printf("%s", buffer);
}
```
*Note: `fgets` keeps the newline character `\n` at the end of the buffer if it was read.*

### 3. `fscanf` (Formatted Input)
Reads formatted input, similar to `scanf`. Stops at whitespace.

```c
char word[20];
int number;
// Unsafe if word > 20 chars! Use width specifier.
if (fscanf(fptr, "%19s %d", word, &number) == 2) {
    printf("Read: %s, %d\n", word, number);
}
```

## 🔒 Closing a File
Always close the file to release system resources (file descriptors).
```c
fclose(fptr);
```

## 🛡️ C11 Safe Functions
C11 introduced `fopen_s` which forces you to handle errors.
```c
#ifdef __STDC_LIB_EXT1__
    errno_t err = fopen_s(&fptr, "filename.txt", "r");
    if (err != 0) { ... }
#endif
```

---
[[00-Index|Back to File I/O Index]]
