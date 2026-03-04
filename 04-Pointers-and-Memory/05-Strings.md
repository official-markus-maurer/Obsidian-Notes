# Strings

In C, strings are not a primitive data type. They are arrays of characters terminated by a null character `\0`.

## 🧵 Declaration

```c
char str1[] = "Hello"; // Size is 6 ('H', 'e', 'l', 'l', 'o', '\0')
char str2[10] = "World"; // Size 10, remaining filled with \0
char *str3 = "Hello"; // Pointer to string literal (Read-only memory usually)
```

> **Warning**: Trying to modify a string literal (e.g., `str3[0] = 'h';`) causes undefined behavior (often a crash). Always use arrays if you need to modify the string.

## 🛠️ String Functions (`<string.h>`)

### `strlen` - String Length
Returns the length of the string (excluding the null terminator).

```c
size_t len = strlen(str1); // 5
```

### `strcpy` - String Copy
Copies one string to another.

```c
char dest[20];
strcpy(dest, "Hello World");
```

### `strcat` - String Concatenation
Appends one string to the end of another.

```c
char str[20] = "Hello";
strcat(str, " World");
```

### `strcmp` - String Compare
Compares two strings. Returns `0` if equal.

```c
if (strcmp(str1, "Hello") == 0) {
    printf("Strings are equal");
}
```

---
[[00-Index|Back to Pointers Index]]
