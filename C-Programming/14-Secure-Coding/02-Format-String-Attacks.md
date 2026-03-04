# Format String Attacks

Format string vulnerabilities occur when a program evaluates user input as a command.

## 💥 The Vulnerability

The `printf` family of functions expects a format string as the first argument. If you pass user input directly, an attacker can inject format specifiers.

### Vulnerable Code
```c
char buffer[100];
fgets(buffer, 100, stdin);

// ⚠️ DANGER: User input is treated as the format string!
printf(buffer); 
```

### The Attack Vectors

1.  **Information Leak (`%x`, `%s`)**:
    -   Input: `%x %x %x %x`
    -   Effect: Pops values off the stack and prints them. Can leak return addresses, pointers, or sensitive data.
    -   Input: `%s`
    -   Effect: Treats the next value on the stack as a pointer and tries to print the string at that address. Can cause a Segfault (Denial of Service) if the address is invalid.

2.  **Arbitrary Write (`%n`)**:
    -   The `%n` specifier writes the number of characters printed so far *to an integer pointer* on the stack.
    -   Effect: An attacker can overwrite memory (e.g., return address, GOT entries) to execute arbitrary code.

## 🛡️ Prevention

**NEVER** pass user input directly as the format string. Always use a constant format string.

### Safe Code
```c
// ✅ Safe: User input is just data
printf("%s", buffer); 
```

### Compiler Protections
Modern compilers often warn about this vulnerability by default.

```bash
gcc -Wformat -Wformat-security program.c
```
**Output:** `warning: format not a string literal and no format arguments [-Wformat-security]`

Many Linux distributions compile system binaries with `-D_FORTIFY_SOURCE=2`, which crashes the program if `%n` is used in a writable memory segment.

---
[[00-Index|Back to Secure Coding Index]]
