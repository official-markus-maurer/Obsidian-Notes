# Memory Layout of a C Program

When a C program is compiled and executed, the operating system allocates memory to it. This memory is organized into several segments. Understanding these segments is crucial for mastering pointers and memory management.

## 🏗️ The Segments

A typical memory layout of a running process looks like this (from low address to high address):

1.  **Text Segment (Code Segment)**
2.  **Initialized Data Segment (Data)**
3.  **Uninitialized Data Segment (BSS)**
4.  **Heap**
5.  **Stack**

### 1. Text Segment (Code Segment)
-   **Content**: Contains the compiled machine code (binary instructions) of the program.
-   **Properties**:
    -   Usually **read-only** to prevent accidental modification.
    -   Shared among multiple instances of the same program.
    -   Fixed size.

### 2. Initialized Data Segment (Data)
-   **Content**: Stores global and static variables that are explicitly initialized by the programmer.
-   **Example**:
    ```c
    int globalVar = 10; // Stored in Data Segment
    static int staticVar = 20; // Stored in Data Segment
    ```
-   **Properties**: Read-write.

### 3. Uninitialized Data Segment (BSS)
-   **Content**: Stores global and static variables that are *not* explicitly initialized (or initialized to zero).
-   **Name**: Stands for "Block Started by Symbol" (an old assembly operator).
-   **Example**:
    ```c
    int globalVar; // Stored in BSS (default value 0)
    ```
-   **Properties**: Automatically initialized to zero by the OS before the program starts.

### 4. Heap
-   **Content**: Used for **dynamic memory allocation** (`malloc`, `calloc`, `realloc`).
-   **Direction**: Grows **upwards** (towards higher memory addresses).
-   **Management**: Manually managed by the programmer. You must `free()` what you allocate.
-   **Size**: Limited by the available virtual memory.

### 5. Stack
-   **Content**: Stores local variables, function parameters, and return addresses.
-   **Structure**: LIFO (Last In, First Out).
-   **Direction**: Grows **downwards** (towards lower memory addresses) on most modern architectures (x86, ARM).
-   **Management**: Automatically managed by the compiler/CPU.
-   **Size**: Limited (typically a few MBs). Recursion too deep causes a **Stack Overflow**.

---
[[00-Index|Back to Pointers Index]]
