# Binary Files

Binary files store data in the same format as it is stored in memory, making I/O faster and more compact than text files.

## 📂 Modes
Use "rb" (read binary) and "wb" (write binary).

## 💾 `fwrite`
Writes a block of data to the file.

```c
struct Person {
    int id;
    char name[20];
};

struct Person p = {1, "Alice"};
fwrite(&p, sizeof(struct Person), 1, fptr);
```
- Pointer to data block
- Size of each element
- Number of elements
- File pointer

## 📖 `fread`
Reads a block of data from the file.

```c
struct Person p;
fread(&p, sizeof(struct Person), 1, fptr);
printf("Read: %d %s\n", p.id, p.name);
```

---
[[00-Index|Back to File I/O Index]]
