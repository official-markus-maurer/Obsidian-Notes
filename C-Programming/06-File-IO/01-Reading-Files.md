# Reading Files

## 📂 Opening a File

Use `fopen()` to open a file. It returns a `FILE*` pointer.

```c
FILE *fptr;
fptr = fopen("filename.txt", "r"); // "r" for read mode
```

Always check if the file opened successfully:
```c
if (fptr == NULL) {
    printf("Error opening file!\n");
    exit(1);
}
```

## 📖 Reading Methods

### 1. `fgetc` (Character by Character)
Reads a single character. Returns `EOF` (End of File) when done.

```c
char ch;
while ((ch = fgetc(fptr)) != EOF) {
    printf("%c", ch);
}
```

### 2. `fgets` (Line by Line)
Reads a string until a newline or end of file. Safer than `gets`.

```c
char buffer[100];
while (fgets(buffer, 100, fptr)) {
    printf("%s", buffer);
}
```

### 3. `fscanf` (Formatted Input)
Reads formatted input from the file, similar to `scanf`.

```c
char word[20];
while (fscanf(fptr, "%s", word) != EOF) {
    printf("%s\n", word);
}
```

## 🔒 Closing a File
Always close the file when done.
```c
fclose(fptr);
```

---
[[00-Index|Back to File I/O Index]]
