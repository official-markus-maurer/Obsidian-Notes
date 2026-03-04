# Buffer Overflows

A buffer overflow occurs when a program writes data past the end of a fixed-size buffer.

## The Mechanism
1.  **Stack Layout**: Local variables (buffers) sit next to the Return Address.
2.  **Overwrite**: If you write past the buffer, you overwrite the Return Address.
3.  **Exploit**: Attacker points the Return Address to their own malicious code (Shellcode).

## Prevention
-   **Use Safe Functions**: `strncpy` instead of `strcpy`, `snprintf` instead of `sprintf`.
-   **Stack Canaries**: Compiler inserts a random value before the Return Address. If modified, the program crashes safely.
-   **ASLR**: Randomizes memory locations so attackers can't guess addresses.

---
[[00-Index|Back to Security Index]]
