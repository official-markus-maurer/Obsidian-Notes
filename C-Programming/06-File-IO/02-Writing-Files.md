# Writing Files

## 📂 Opening a File for Writing

Use `fopen` with appropriate modes.

### Modes
| Mode | Description | behavior if exists | behavior if missing |
| :--- | :--- | :--- | :--- |
| `"w"` | Write (Overwrite) | Truncates to 0 bytes | Creates new |
| `"a"` | Append | Keeps data, adds to end | Creates new |
| `"r+"` | Read/Write | Overwrites from start | Error (NULL) |
| `"w+"` | Read/Write | Truncates to 0 bytes | Creates new |

```c
FILE *fptr = fopen("output.txt", "w");
if (fptr == NULL) {
    perror("Error creating file");
    return 1;
}
```

## 🖊️ Writing Methods

### 1. `fputc` (Character)
Writes a single character.

```c
fputc('A', fptr);
fputc('\n', fptr);
```

### 2. `fputs` (String)
Writes a string. Unlike `puts`, it **does not** automatically add a newline.

```c
fputs("Hello, World!", fptr);
fputs("\n", fptr);
```

### 3. `fprintf` (Formatted Output)
Writes formatted output, exactly like `printf` but to a file stream.

```c
int id = 123;
char name[] = "Alice";
fprintf(fptr, "ID: %d, Name: %s\n", id, name);
```

### 4. `fwrite` (Block Write)
Usually for binary files, but can write text too. See [[03-Binary-Files|Binary Files]].

## 🧹 Buffering and Flushing
Standard I/O is buffered. Data might sit in memory before being written to disk.
-   **Full Buffering**: Writes only when buffer (e.g., 4KB) is full. (Files)
-   **Line Buffering**: Writes on `\n`. (Stdout)
-   **No Buffering**: Writes immediately. (Stderr)

Force a write using `fflush()`:
```c
fprintf(fptr, "Important Log");
fflush(fptr); // Ensure it's on disk immediately
```

---
[[00-Index|Back to File I/O Index]]
