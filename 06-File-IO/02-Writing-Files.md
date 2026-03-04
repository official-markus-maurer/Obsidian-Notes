# Writing Files

## 📂 Opening a File for Writing

Use "w" (write) or "a" (append) mode.
- "w": Overwrites existing file or creates a new one.
- "a": Appends to the end of the file.

```c
FILE *fptr = fopen("output.txt", "w");
```

## 🖊️ Writing Methods

### 1. `fputc` (Character)
Writes a single character.

```c
fputc('A', fptr);
```

### 2. `fputs` (String)
Writes a string.

```c
fputs("Hello, World!\n", fptr);
```

### 3. `fprintf` (Formatted Output)
Writes formatted output, similar to `printf`.

```c
int id = 123;
char name[] = "Alice";
fprintf(fptr, "ID: %d, Name: %s\n", id, name);
```

---
[[00-Index|Back to File I/O Index]]
