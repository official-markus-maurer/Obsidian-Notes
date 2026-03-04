# Makefiles and Build Systems

As your project grows beyond a single file, compiling manually with `gcc main.c utils.c -o app` becomes tedious. Makefiles automate this process.

## 🛠️ Basic Makefile

Create a file named `Makefile` (no extension).

```makefile
# Variables
CC = gcc
CFLAGS = -Wall -g

# Target: Dependencies
# [TAB] Command

all: myprogram

myprogram: main.o utils.o
	$(CC) $(CFLAGS) -o myprogram main.o utils.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o myprogram
```

### Explanation
1.  **Variables**: Define compiler (`CC`) and flags (`CFLAGS`) once.
2.  **Targets**: The file you want to create (e.g., `myprogram`, `main.o`).
3.  **Dependencies**: Files needed to create the target. If `main.c` changes, `main.o` is rebuilt.
4.  **Commands**: The shell command to run. **MUST Start with a TAB character**.

## 🚀 Running Make
-   `make`: Builds the first target (`all`).
-   `make clean`: Runs the `clean` target (deletes files).

## 🧩 Advanced Features

### Pattern Rules
Instead of writing a rule for every `.c` file, use `%`.

```makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
-   `$@`: The target name (e.g., `main.o`).
-   `$<`: The first dependency (e.g., `main.c`).

### Automatic Variables
-   `$^`: All dependencies.

## 🏗️ Other Build Systems
While Make is standard, modern C projects often use:
-   **CMake**: Generates Makefiles. Cross-platform and standard for large projects.
-   **Ninja**: Faster alternative to Make.
-   **Meson**: User-friendly build system.

---
[[00-Index|Back to Advanced Index]]
