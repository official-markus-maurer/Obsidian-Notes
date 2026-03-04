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
    valgrind --leak-check=full --track-origins=yes ./myprogram
    ```

## 📝 Understanding Output

Valgrind will run your program and report errors.

### 1. Invalid Write/Read (Heap Corruption)
Usually means you are writing past the end of an allocated block or accessing freed memory.

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
*Tip: Use `--track-origins=yes` to see exactly where the uninitialized variable came from.*

```
==12345== Conditional jump or move depends on uninitialised value(s)
```

### 4. Double Free
You tried to free the same pointer twice. This is a serious security vulnerability.

```
==12345== Invalid free() / delete / delete[] / realloc()
==12345==    at 0x4C2BDEC: free (in /usr/lib/valgrind/vgpreload_memcheck...)
==12345==    by 0x4005E0: main (test.c:15)
==12345==  Address 0x5204040 is 0 bytes inside a block of size 10 free'd
```

### 5. Mismatched Free
Using `free` on something allocated with `new` (C++) or vice versa. In C, using `free` on a stack variable.

```
==12345== Invalid free() / delete / delete[] / realloc()
==12345==  Address 0x... is on thread 1's stack
```

## 💡 Best Practices

-   Run Valgrind on **every** C program you write that uses pointers or dynamic memory.
-   Fix errors in order. Often the first error causes a cascade of others.
-   Aim for "All heap blocks were freed -- no leaks are possible".
-   Valgrind slows down your program (20-30x slower), so use it for debugging, not production performance testing.

---
[[00-Index|Back to Debugging Index]]
