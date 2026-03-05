# Buffer Overflows

A buffer overflow occurs when a program writes more data to a buffer (array) than it can hold. This overwrites adjacent memory, which can corrupt data, crash the program, or allow attackers to execute malicious code.

## 💥 The Vulnerability

```c
void vulnerable_function(char *str) {
    char buffer[10];
    // ⚠️ DANGER: strcpy does not check bounds!
    // If str is > 9 chars, it overwrites the stack.
    strcpy(buffer, str); 
}

int main() {
    vulnerable_function("This string is way too long for the buffer");
    return 0;
}
```

## 🧠 Under the Hood (The Stack Frame)

When `vulnerable_function` is called, the stack looks like this (simplified):

```
| Return Address (8 bytes) |  <-- Attack Target
| Saved RBP (8 bytes)      |
| buffer[0..9] (10 bytes)  |  <-- Stack grows down, buffer fills up
| ...                      |
```

If we write 20 bytes into `buffer`:
1.  **Bytes 0-9**: Fill `buffer`.
2.  **Bytes 10-17**: Overwrite `Saved RBP`.
3.  **Bytes 18-25**: Overwrite **Return Address**.

When the function returns (`ret` instruction), the CPU pops the corrupted Return Address into `RIP` and jumps to it.
-   **Crash**: If the address is invalid (Segfault).
-   **Exploit**: If the address points to malicious code (Shellcode).

## 🛡️ Prevention Techniques

### 1. Use Safe String Functions
Always use "n" versions or safer alternatives that take a size limit.

-   **`strcpy` -> `strncpy`**: Be careful, `strncpy` does **not** null-terminate if the string is truncated!
    ```c
    strncpy(buffer, src, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Manually ensure null-termination
    ```
-   **`strlcpy` (BSD/macOS)**: Safer than `strncpy`, always null-terminates. Not standard C but widely available.
-   **`sprintf` -> `snprintf`**: Returns the number of characters that *would* have been written.
    ```c
    int len = snprintf(buffer, sizeof(buffer), "%s", src);
    if (len >= sizeof(buffer)) {
        // Handle truncation error
    }
    ```
-   **`gets` -> `fgets`**: Never use `gets()`. It was removed from C11 because it's impossible to use safely.

### 2. Stack Canaries (Compiler Protection)
Modern compilers insert a "canary" (random value) before the return address on the stack. Before returning, the function checks if the canary is modified.

**Enable with GCC/Clang:**
```bash
gcc -fstack-protector-all program.c -o program
```

### 3. Address Space Layout Randomization (ASLR)
The OS randomizes the location of the stack, heap, and libraries in memory. This makes it harder for attackers to jump to specific addresses (like shellcode).
*Enabled by default on modern Linux/Windows/macOS.*

---
[[00-Index|Back to Secure Coding Index]]
