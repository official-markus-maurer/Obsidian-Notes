# The ELF File Format

The **Executable and Linkable Format (ELF)** is the standard binary format for Unix-like systems (Linux, BSD, Solaris). It defines how an executable, object file, or shared library is structured.

## 📦 File Types

1.  **Relocatable File (`.o`)**: Holds code and data suitable for linking with other object files.
2.  **Executable File**: Holds a program suitable for execution.
3.  **Shared Object File (`.so`)**: Holds code and data suitable for linking in two contexts (compile-time and run-time).
4.  **Core Dump File**: Holds the memory image of a crashed process.

## 🏗️ Structure

An ELF file consists of:

1.  **ELF Header**: Magic number (`0x7F 'E' 'L' 'F'`), architecture (x86-64), entry point address.
2.  **Program Header Table**: Describes **Segments** (for the OS loader). Tells the kernel how to create a process image.
    -   `LOAD`: Segments to load into memory.
    -   `DYNAMIC`: Information for dynamic linking.
    -   `INTERP`: Path to the interpreter (`/lib64/ld-linux-x86-64.so.2`).
3.  **Section Header Table**: Describes **Sections** (for the linker).
    -   `.text`: Executable code.
    -   `.data`: Initialized global variables.
    -   `.bss`: Uninitialized global variables (takes no space in file).
    -   `.rodata`: Read-only data (string literals).
    -   `.symtab`: Symbol table (function/variable names).
    -   `.strtab`: String table (names of symbols).
    -   `.rel.text`: Relocation information (places in code that need patching).

## 🔗 Relocations

Relocations are entries that tell the linker how to modify the section contents.
-   **Static Relocation**: Fixup addresses at link time (e.g., `call printf` needs the address of `printf`).
-   **Dynamic Relocation**: Fixup addresses at load time (e.g., global variables in shared libraries).

## 🛠️ Tools

-   **`readelf`**: Display information about ELF files.
    ```bash
    readelf -h ./program    # Header
    readelf -l ./program    # Program Headers (Segments)
    readelf -S ./program    # Section Headers
    readelf -s ./program    # Symbols
    readelf -r ./program    # Relocations
    ```
-   **`objdump`**: Display information from object files.
    ```bash
    objdump -x ./program    # All headers
    ```
-   **`nm`**: List symbols from object files.

## 🛡️ Security Features

-   **NX (No-Execute)**: Marks the stack and heap as non-executable (in Program Header `GNU_STACK`).
-   **PIE (Position Independent Executable)**: Code is compiled as position-independent, allowing full ASLR.

---
[[00-Index|Back to Assembly Index]]
