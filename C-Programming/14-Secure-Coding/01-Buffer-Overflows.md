# Buffer Overflows

A buffer overflow occurs when a program writes more data to a buffer (array) than it can hold. This overwrites adjacent memory, which can corrupt data, crash the program, or allow attackers to execute malicious code.

## 💥 The Vulnerability

```c
void vulnerable_function(char *str) {
    char buffer[10];
    strcpy(buffer, str); // ⚠️ DANGER: No size check!
}

int main() {
    vulnerable_function("This string is way too long for the buffer");
    return 0;
}
```

## 🛡️ Prevention

Always use "n" versions of string functions that take a size limit.

1.  **`strcpy` -> `strncpy`** (or `strlcpy` if available)
    ```c
    strncpy(buffer, str, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
    ```

2.  **`sprintf` -> `snprintf`**
    ```c
    snprintf(buffer, sizeof(buffer), "%s", str);
    ```

3.  **`gets` -> `fgets`**
    Never use `gets()`. It was removed from C11 because it's impossible to use safely.

---
[[00-Index|Back to Secure Coding Index]]
