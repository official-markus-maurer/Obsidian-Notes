# Memory Safety with Valgrind

Valgrind is a programming tool for memory debugging, memory leak detection, and profiling. It is incredibly useful for finding C errors that don't cause immediate crashes but corrupt memory silently.

## 🛠️ Installation

On Linux (Ubuntu/Debian):
```bash
sudo apt install valgrind
```

## 🔍 How to Use

1.  **Compile with debug symbols** (`-g`):
    ```bash
    gcc -g -o myprogram myprogram.c
    ```

2.  **Run with Valgrind**:
    ```bash
    valgrind --leak-check=full ./myprogram
    ```

## 📝 Understanding Output

Valgrind will run your program and report errors.

### 1. Invalid Write/Read
Usually means you are writing past the end of an array or writing to freed memory.

```
==12345== Invalid write of size 4
==12345==    at 0x4005F6: main (test.c:10)
==12345==  Address 0x5204040 is 0 bytes after a block of size 4 alloc'd
```

### 2. Memory Leak
Means you allocated memory (`malloc`) but didn't free it (`free`).

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 40 bytes in 1 blocks
==12345==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==12345==
==12345== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
```

### 3. Use of Uninitialized Value
You are using a variable (e.g., in an `if` condition) that hasn't been set yet.

```
==12345== Conditional jump or move depends on uninitialised value(s)
```

## 💡 Best Practices

-   Run Valgrind on **every** C program you write that uses pointers or dynamic memory.
-   Fix errors in order. Often the first error causes a cascade of others.
-   Aim for "All heap blocks were freed -- no leaks are possible".

---
[[00-Index|Back to Debugging Index]]
