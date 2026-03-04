# Input and Output

In C, Input/Output (I/O) operations are performed using standard library functions like `printf()` and `scanf()`. These are defined in `<stdio.h>`.

## 📤 Output: `printf()`

The `printf()` function sends formatted output to the standard output (screen).

### Syntax
```c
printf("format string", argument_list);
```

### Common Format Specifiers
- `%d` or `%i`: Integer
- `%f`: Float
- `%lf`: Double
- `%c`: Character
- `%s`: String
- `%p`: Pointer address
- `%x`: Hexadecimal

### Example
```c
int age = 20;
printf("I am %d years old.\n", age);
```

### Escape Sequences
- `\n`: Newline
- `\t`: Tab
- `\\`: Backslash
- `\"`: Double quote

## 📥 Input: `scanf()`

The `scanf()` function reads formatted input from the standard input (keyboard).

### Syntax
```c
scanf("format string", &variable_address);
```
> **Crucial**: You must use the address-of operator `&` before the variable name (except for strings/arrays). This tells `scanf` *where* in memory to store the input.

### Example
```c
int age;
printf("Enter your age: ");
scanf("%d", &age); // Notice the &
printf("You entered: %d\n", age);
```

### Common Pitfalls
1. **Missing `&`**: Forgetting the ampersand for non-pointer types will cause a crash or undefined behavior.
2. **Buffer Issues**: `scanf` leaves a newline character in the buffer after reading a number. This can cause subsequent `scanf("%c", ...)` calls to read the newline instead of the intended character.
   - **Fix**: Add a space before `%c` like `scanf(" %c", &ch);` to consume whitespace.

---
[[00-Index|Back to Basics Index]]
