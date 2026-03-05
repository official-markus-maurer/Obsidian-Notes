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
    **SONAME**: It is best practice to include a version in the library name (e.g., `libmylib.so.1`).
    ```bash
    gcc -shared -Wl,-soname,libmylib.so.1 -o libmylib.so.1.0 mylib.o
    ```

3.  **Link**:
    ```bash
    ln -s libmylib.so.1.0 libmylib.so
    gcc main.c -L. -lmylib -o app
    ```

4.  **Run (RPATH)**:
    Instead of `LD_LIBRARY_PATH`, you can bake the search path into the binary using **RPATH**.
    ```bash
    gcc main.c -L. -lmylib -Wl,-rpath,'$ORIGIN' -o app
    ```
    *`$ORIGIN` tells the loader to look in the same directory as the executable.*

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
