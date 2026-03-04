# Standard Project Layout

A well-organized project structure prevents dependency headaches and makes your codebase approachable for new contributors.

## 📁 Recommended Structure

```
project-root/
├── .gitignore          # Files to exclude from git (e.g., build/)
├── README.md           # Project documentation
├── Makefile            # Build script
├── src/                # Implementation files (.c)
│   ├── main.c          # Entry point
│   ├── utils.c
│   └── network/        # Submodules (optional)
│       └── socket.c
├── include/            # Public Interface files (.h)
│   └── mylib/          # Namespace folder (Important!)
│       ├── utils.h
│       └── socket.h
├── lib/                # Third-party libraries (static .a or dynamic .so)
├── build/              # Intermediate build artifacts (.o files)
├── bin/                # Final executable output
├── tests/              # Unit tests
│   ├── test_main.c     # Test runner
│   └── test_utils.c
└── doc/                # Documentation (Doxygen, images)
```

## 🔑 Key Principles

### 1. `src` vs `include`
-   **`src/`**: Contains the "secret sauce". Code here is compiled into object files.
-   **`include/`**: Contains the "contract". These headers are what other developers (or other parts of your code) use to interact with your library.
    -   *Best Practice*: Put headers in a subdirectory (e.g., `include/mylib/`) to avoid name collisions (e.g., `utils.h` vs `mylib/utils.h`).

### 2. `build` vs `bin`
-   **`build/`**: Temporary object files (`.o`). Can be deleted safely.
-   **`bin/`**: The final product (executable or library).

### 3. `tests`
Tests should mirror the structure of `src` or be grouped logically. They should link against the object files from `build/`.

## 🛠️ Compiling with This Layout

You need to tell the compiler where to find headers.

```bash
# Compile utils.c to object file
gcc -I./include -c src/utils.c -o build/utils.o

# Compile main.c
gcc -I./include -c src/main.c -o build/main.o

# Link everything
gcc build/main.o build/utils.o -o bin/my_app
```

---
[[00-Index|Back to Index]] | [[02-Header-Files|Next: Header Files]]
