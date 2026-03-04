# CERT C Coding Standard

The SEI CERT C Coding Standard provides rules for secure coding in the C programming language. Unlike MISRA (which focuses on safety and reliability), CERT C focuses primarily on **security vulnerabilities**.

## Categories of Rules
CERT C rules are organized by topic:
1.  **PRE (Preprocessor)**: Macros and includes.
2.  **DCL (Declarations)**: Types and variables.
3.  **EXP (Expressions)**: Evaluation order, side effects.
4.  **INT (Integers)**: Overflow, wrapping, conversion.
5.  **FLP (Floating Point)**: Precision, special values.
6.  **ARR (Arrays)**: Bounds checking.
7.  **STR (Strings)**: Null termination, truncation.
8.  **MEM (Memory)**: Allocation, freeing.
9.  **FIO (File I/O)**: Permissions, race conditions.

## Critical Rules

### 1. STR31-C: Guarantee that storage for strings has sufficient space
Ensure that destination buffers are large enough to hold the string *and* the null terminator.

```c
// Vulnerable
char src[] = "Hello";
char dest[5]; 
strcpy(dest, src); // Buffer overflow! dest needs 6 bytes.

// Secure
char src[] = "Hello";
char dest[6];
strcpy(dest, src);
```

### 2. INT32-C: Ensure that operations on signed integers do not result in overflow
Signed integer overflow is **Undefined Behavior**.

```c
// Vulnerable
int a = INT_MAX;
int b = 1;
int c = a + b; // Undefined Behavior!

// Secure
if (a > INT_MAX - b) {
    // Handle error
} else {
    int c = a + b;
}
```

### 3. MEM30-C: Do not access freed memory
Use-after-free is a major security vulnerability.

```c
char *ptr = malloc(10);
free(ptr);
// ... later ...
*ptr = 'a'; // Use-after-free!

// Mitigation
free(ptr);
ptr = NULL; // Defensive coding
```

### 4. FIO30-C: Exclude user input from format strings
Never pass user input directly as the format string to `printf`.

```c
// Vulnerable
char *user_input = get_input();
printf(user_input); // Format string attack!

// Secure
printf("%s", user_input);
```

## Tools
-   **Clang-Tidy**: Can check for many CERT rules.
-   **SonarQube**: Extensive security rulesets.

---
[[00-Index|Back to Index]] | [[03-Style-Guides|Next: Style Guides]]
