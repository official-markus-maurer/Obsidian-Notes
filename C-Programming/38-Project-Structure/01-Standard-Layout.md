# Standard Project Layout

Most C projects follow a convention similar to this:

```
project-root/
├── src/            # .c source files
│   ├── main.c
│   └── utils.c
├── include/        # Public .h header files
│   └── mylib/
│       └── utils.h
├── lib/            # Third-party libraries (static or dynamic)
├── build/          # Build artifacts (object files, executables)
├── tests/          # Unit tests
│   └── test_utils.c
├── doc/            # Documentation (Doxygen)
├── Makefile        # Build script
└── README.md
```

## Explanation
-   **`src/`**: Contains the actual code. This directory is often not distributed with binary releases.
-   **`include/`**: Contains the public API. If you are writing a library, these are the files users will `#include`.
-   **`build/`**: Should be in `.gitignore`. Keeps the source tree clean.

## Managing Includes
When compiling, you tell the compiler where to look for headers:
```bash
gcc -I./include -c src/main.c -o build/main.o
```
In your code:
```c
#include "mylib/utils.h" // Clean and namespaced
```

---
[[00-Index|Back to Index]] | [[02-Header-Files|Next: Header Files]]
