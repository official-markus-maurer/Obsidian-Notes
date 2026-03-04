# Memory Layout of a C Program

When a C program is compiled and executed, the operating system allocates memory to it. This memory is organized into several segments. Understanding these segments is crucial for mastering pointers, memory management, and debugging low-level crashes.

## 🏗️ The Segments Diagram

A typical memory layout of a running process looks like this (from high address to low address):

```
+------------------+  High Address (0xFFFFFFFF on 32-bit)
| Command Line Args|  (argv, argc, env)
| & Environment    |
+------------------+
|      STACK       |  Grows Downwards
|        |         |  (Local variables, function calls)
|        v         |
|                  |
|                  |
|        ^         |
|        |         |
|       HEAP       |  Grows Upwards
+------------------+  (Dynamic memory: malloc/free)
|       BSS        |  (Uninitialized global/static variables)
+------------------+
| Initialized Data |  (Initialized global/static variables)
+------------------+
|       TEXT       |  (Code / Binary Instructions)
+------------------+  Low Address (0x00000000)
```

## 🔍 Detailed Breakdown

### 1. Text Segment (Code Segment)
-   **Content**: Contains the compiled machine code (binary instructions) of the program.
-   **Permissions**: **Read-Execute**. Writing to this segment causes a Segmentation Fault.
-   **Sharing**: Often shared among multiple instances of the same program to save memory (e.g., if you run 10 instances of `chrome`, the code is loaded once).

### 2. Initialized Data Segment (Data)
-   **Content**: Global and static variables that are explicitly initialized by the programmer.
-   **Permissions**: Read-Write.
-   **Example**:
    ```c
    int globalVar = 10; // Stored in Data Segment
    static int staticVar = 20; // Stored in Data Segment
    
    void func() {
        static int count = 0; // Stored in Data Segment (persists across calls)
    }
    ```

### 3. Uninitialized Data Segment (BSS)
-   **Content**: Global and static variables that are *not* explicitly initialized (or initialized to zero).
-   **Name**: "Block Started by Symbol".
-   **Optimization**: Does not take up space in the executable file on disk, only in memory at runtime.
-   **Example**:
    ```c
    int globalVar; // Stored in BSS (default value 0)
    ```

### 4. Heap
-   **Content**: Used for **dynamic memory allocation** (`malloc`, `calloc`, `realloc`).
-   **Management**: Manually managed. You request memory from the OS via the allocator.
-   **Fragmentation**: Since you can free blocks in any order, the heap can become fragmented (holes of free memory between used blocks).
-   **Growth**: Grows **upwards** towards the Stack. If it meets the Stack, you run out of memory.

### 5. Stack
-   **Content**: Stores **Stack Frames** for function calls.
-   **Growth**: Grows **downwards** towards the Heap.
-   **Speed**: Extremely fast allocation (just moving the Stack Pointer register).
-   **Structure**: LIFO (Last In, First Out).

## 🖼️ Anatomy of a Stack Frame

Every time a function is called, a new **Stack Frame** is pushed. It contains:

1.  **Arguments**: Parameters passed to the function.
2.  **Return Address**: The instruction address to return to when the function finishes.
3.  **Saved Base Pointer (EBP/RBP)**: The location of the previous stack frame.
4.  **Local Variables**: Variables declared inside the function.

```c
void func(int a, int b) {
    int x = 10;
    int y = 20;
}
```

**Stack Frame for `func`:**
```
|    ...         |
| Argument b     |
| Argument a     |
| Return Address |
| Saved EBP      | <--- EBP (Base Pointer) points here
| Local var x    |
| Local var y    | <--- ESP (Stack Pointer) points here
+----------------+
```

## 👻 Virtual Memory

Modern OSs give each process the illusion of having its own massive, contiguous memory space (Virtual Memory).
-   The addresses you see in C (e.g., `0x7ff...`) are **Virtual Addresses**.
-   The CPU (via the MMU - Memory Management Unit) translates these to **Physical RAM Addresses**.
-   This prevents one program from crashing another by writing to its memory.

---
[[00-Index|Back to Pointers Index]]
