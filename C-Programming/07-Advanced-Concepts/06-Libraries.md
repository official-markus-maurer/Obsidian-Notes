# Libraries: Static vs. Dynamic

Libraries are collections of pre-compiled functions that you can reuse in your programs.

## 📦 Static Libraries (`.a` / `.lib`)

Code from the library is **copied directly** into your executable at compile time.

### Pros
-   **Portability**: Executable is self-contained. No external dependencies.
-   **Speed**: Slightly faster startup (no linking at runtime).

### Cons
-   **Size**: Executable is larger.
-   **Updates**: If the library changes, you must recompile your program.

### Creating and Using (Linux/GCC)

1.  **Compile to Object Code**:
    ```bash
    gcc -c mylib.c -o mylib.o
    ```
2.  **Create Archive (Library)**:
    ```bash
    ar rcs libmylib.a mylib.o
    ```
3.  **Link**:
    ```bash
    gcc main.c -L. -lmylib -o app
    ```

## 🚀 Dynamic Libraries (`.so` / `.dll`)

Code is **referenced** by your executable but loaded at **runtime**.

### Pros
-   **Size**: Executable is smaller.
-   **Sharing**: Multiple programs can share one copy of the library in memory.
-   **Updates**: You can update the library file (`.so`/`.dll`) without recompiling the program.

### Cons
-   **Dependency Hell**: The library must be present on the target system.
-   **Startup**: Slightly slower startup time.

### Creating and Using (Linux/GCC)

1.  **Compile with Position Independent Code (PIC)**:
    ```bash
    gcc -c -fPIC mylib.c -o mylib.o
    ```
2.  **Create Shared Object**:
    ```bash
    gcc -shared -o libmylib.so mylib.o
    ```
3.  **Link**:
    ```bash
    gcc main.c -L. -mylib -o app
    ```
4.  **Run**:
    You may need to set `LD_LIBRARY_PATH`.
    ```bash
    export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
    ./app
    ```

---
[[00-Index|Back to Advanced Index]]
