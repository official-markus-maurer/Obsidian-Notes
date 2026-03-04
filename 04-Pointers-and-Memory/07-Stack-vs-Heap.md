# Stack vs Heap

Understanding the difference between the Stack and the Heap is one of the most important concepts in C and low-level programming.

## ⚔️ Comparison Table

| Feature | Stack | Heap |
| :--- | :--- | :--- |
| **Management** | **Automatic**: Variables are allocated when entering a scope/function and freed when leaving. | **Manual**: You must explicitly allocate (`malloc`) and deallocate (`free`). |
| **Speed** | **Very Fast**: Allocation is just moving a pointer (stack pointer). | **Slower**: Requires looking for a free block of memory, updating bookkeeping data, etc. |
| **Size Limit** | **Small**: Fixed size (e.g., 1MB - 8MB). Easy to overflow with large arrays or deep recursion. | **Large**: Limited only by system virtual memory (RAM + Swap). |
| **Scope** | **Local**: Variables only exist within the function they were created. | **Global**: Memory is accessible anywhere (if you have the pointer) and persists until freed. |
| **Fragmentation**| **No**: Memory is contiguous. | **Yes**: Frequent allocation/deallocation can leave holes in memory. |
| **Safety** | **Safer**: Harder to have memory leaks (though stack overflow is possible). | **Risky**: Prone to memory leaks, dangling pointers, and double frees. |

## 📦 The Stack (Automatic Memory)

Think of the stack like a stack of plates.
-   When a function is called, a **stack frame** is "pushed" onto the stack.
-   This frame contains:
    -   Function arguments.
    -   Return address (where to go back after the function finishes).
    -   Local variables.
-   When the function returns, the frame is "popped" (the stack pointer moves back), effectively freeing the memory.

```c
void foo() {
    int x = 10; // x is on the Stack
} // x is destroyed here
```

## 🗑️ The Heap (Dynamic Memory)

Think of the heap as a large pool of free memory.
-   You ask for a specific amount: `void* ptr = malloc(100);`
-   The allocator finds a chunk of that size and gives you a pointer.
-   The pointer `ptr` itself (the variable holding the address) is usually on the **Stack**, but it points to data on the **Heap**.
-   The data persists even after the function returns.

```c
int* createInteger() {
    int* p = malloc(sizeof(int)); // Memory allocated on Heap
    *p = 10;
    return p; // Safe to return! The address is still valid.
}

void useIt() {
    int* myInt = createInteger();
    printf("%d", *myInt);
    free(myInt); // Don't forget to clean up!
}
```

## ⚠️ Common Pitfall: Returning Pointer to Stack Variable

**NEVER** do this:

```c
int* badFunction() {
    int x = 10;
    return &x; // DANGER! x will be destroyed when function returns.
}
```
The memory address `&x` is no longer valid after `badFunction` returns. Accessing it results in **Undefined Behavior** (garbage value or crash).

---
[[00-Index|Back to Pointers Index]]
