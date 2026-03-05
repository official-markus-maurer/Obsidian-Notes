# Libraries: Static vs. Dynamic

Libraries are collections of pre-compiled functions that you can reuse in your programs.

## 📦 Static Libraries (`.a` / `.lib`)

Code from the library is **copied directly** into your executable at compile time.

### Pros
-   **Portability**: Executable is self-contained. No external dependencies.
-   **Speed**: Slightly faster startup (no linking at runtime) and allows LTO (Link Time Optimization) across the library boundary.

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
-   **Dependency Hell**: The library must be present on the target system (and the correct version).
-   **Startup**: Slower startup time due to symbol resolution.

### Creating and Using (Linux/GCC)

1.  **Compile with Position Independent Code (PIC)**:
    ```bash
    gcc -c -fPIC mylib.c -o mylib.o
    ```
    *PIC allows code to be loaded at any address in memory, which is required for shared libraries.*

2.  **Create Shared Object**:
    ```bash
    gcc -shared -o libmylib.so mylib.o
    ```
3.  **Link**:
    ```bash
    gcc main.c -L. -lmylib -o app
    ```
4.  **Run**:
    You may need to set `LD_LIBRARY_PATH` so the loader finds the `.so` file.
    ```bash
    export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
    ./app
    ```

## 🧠 Under the Hood: PLT and GOT

How does a program call a function (like `printf`) if it doesn't know the address until runtime?

### 1. Global Offset Table (GOT)
A table in the data section that stores the **absolute addresses** of global variables and functions.
-   Initially, it points back to the PLT.
-   After the first call, the dynamic linker updates it to point to the real function address.

### 2. Procedure Linkage Table (PLT)
A trampoline code stub in the text section.

**The Flow:**
1.  Code calls `printf@plt`.
2.  `printf@plt` jumps to the address stored in the GOT.
3.  **First Call**: The GOT points back to the resolver code. The dynamic linker runs, finds `printf` in `libc.so`, and updates the GOT.
4.  **Subsequent Calls**: The GOT points directly to `printf`. This is called **Lazy Binding**.

---
[[00-Index|Back to Advanced Index]]
