# Binary Files

Binary files store data exactly as it is represented in memory. This is faster and more compact than text files but less portable (due to endianness and padding).

## 📂 Modes
Use `"rb"` (read binary) and `"wb"` (write binary).
-   On **Windows**, this prevents `\n` -> `\r\n` translation.
-   On **Linux**, it is often the same as text mode, but using `"b"` is good practice for portability.

## 💾 `fwrite`
Writes a block of data (e.g., an array or a struct) to the file.

```c
struct Person {
    int id;
    char name[20];
};

struct Person p = {1, "Alice"};

FILE *fptr = fopen("data.bin", "wb");
if (fptr) {
    // &p: pointer to data
    // sizeof(struct Person): size of one element
    // 1: number of elements
    // fptr: file stream
    size_t written = fwrite(&p, sizeof(struct Person), 1, fptr);
    if (written != 1) perror("Write failed");
    fclose(fptr);
}
```

## 📖 `fread`
Reads a block of data from the file.

```c
struct Person p_read;
FILE *fptr = fopen("data.bin", "rb");
if (fptr) {
    size_t read = fread(&p_read, sizeof(struct Person), 1, fptr);
    if (read == 1) {
        printf("Read: %d %s\n", p_read.id, p_read.name);
    }
    fclose(fptr);
}
```

## 📍 Random Access (`fseek`, `ftell`)
Binary files allow you to jump to specific locations.

### `fseek`
Moves the file cursor.
```c
// Move to the 5th Person record
fseek(fptr, 4 * sizeof(struct Person), SEEK_SET);
```
-   `SEEK_SET`: Beginning of file.
-   `SEEK_CUR`: Current position.
-   `SEEK_END`: End of file.

### `ftell`
Returns current cursor position.
```c
long pos = ftell(fptr);
```

### `rewind`
Moves cursor to the beginning.
```c
rewind(fptr); // Same as fseek(fptr, 0, SEEK_SET)
```

## ⚠️ Serialization Pitfalls
Writing structs directly (`fwrite`) is fast but risky:
1.  **Endianness**: Little-endian machine cannot read Big-endian file.
2.  **Padding**: Compilers add padding bytes for alignment. Different compilers/flags change padding.
3.  **Pointers**: Never write pointers to a file! The address `0x7fff...` is meaningless in another process.

**Solution**: Serialize member-by-member or use a library (Protocol Buffers, JSON).

---
[[00-Index|Back to File I/O Index]]
