# Virtual Memory

Virtual memory is a technique that gives an application the impression that it has contiguous working memory (an address space), while in fact it is fragmented in physical RAM and may even overflow to disk storage.

## Key Components
-   **MMU (Memory Management Unit)**: Hardware that translates Virtual Addresses to Physical Addresses.
-   **Pages**: Fixed-size blocks (usually 4KB).
-   **Page Tables**: Data structures mapping virtual pages to physical frames.
-   **Page Fault**: Occurs when a program accesses a page not currently in RAM.

## Benefits
1.  **Isolation**: Process A cannot access Process B's memory.
2.  **Security**: Read-only pages (code) cannot be modified.
3.  **Efficiency**: Only load parts of the program that are actually used.

---
[[00-Index|Back to Memory Index]]
