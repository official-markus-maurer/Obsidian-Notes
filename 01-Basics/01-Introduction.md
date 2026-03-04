# Introduction to C

## 📜 History
C was developed at Bell Labs by **Dennis Ritchie** between 1972 and 1973. It was derived from an earlier language called B. It is a general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system.

## 🏗️ Structure of a C Program

Every C program follows a specific structure:

1. **Documentation Section**: Comments describing the program.
2. **Link Section**: Includes header files.
3. **Definition Section**: Define symbolic constants.
4. **Global Declaration Section**: Declare global variables and functions.
5. **Main Function Section**: The entry point of the program.
6. **Subprogram Section**: User-defined functions.

### Example: Hello World

```c
#include <stdio.h> // Link Section (Header file)

// Main Function - Execution starts here
int main() {
    // Print "Hello, World!" to the console
    printf("Hello, World!\n");

    return 0; // Return 0 indicates successful execution
}
```

## ⚙️ Compilation Process

The compilation process involves four main stages:

1. **Preprocessing**:
   - Expands macros and includes header files.
   - Comments are removed.
   - Output file extension: `.i`

2. **Compiling**:
   - Converts preprocessed code into assembly code.
   - Output file extension: `.s`

3. **Assembling**:
   - Converts assembly code into machine code (object code).
   - Output file extension: `.o` or `.obj`

4. **Linking**:
   - Merges object code with libraries to create an executable.
   - Output file extension: `.exe` (Windows) or `.out` (Linux/Mac)

---
[[00-Index|Back to Basics Index]]
