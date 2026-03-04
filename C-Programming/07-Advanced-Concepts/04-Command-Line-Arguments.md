# Command Line Arguments

You can pass arguments to your C program when you run it from the command line.

## 📥 `main` Parameters

```c
int main(int argc, char *argv[]) {
    // ...
}
```

-   **`argc` (Argument Count)**: The number of arguments passed (including the program name).
-   **`argv` (Argument Vector)**: An array of strings containing the arguments.
    -   `argv[0]`: The program name (e.g., `./myprogram`).
    -   `argv[1]`: The first user argument.
    -   `argv[argc]`: Always `NULL` (guaranteed by standard).

## 📝 Example: Simple Parser

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        printf("Help message...\n");
    } else {
        printf("Hello, %s!\n", argv[1]);
    }
    return 0;
}
```

## 🛠️ Parsing Options with `getopt` (POSIX)
On Unix/Linux, `getopt` (`<unistd.h>`) simplifies parsing flags like `-v` or `-f file`.

```c
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int opt;
    // Parsing options: -v (verbose), -f (filename, requires arg)
    while ((opt = getopt(argc, argv, "vf:")) != -1) {
        switch (opt) {
            case 'v':
                printf("Verbose mode on\n");
                break;
            case 'f':
                printf("Filename: %s\n", optarg);
                break;
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-v] [-f file]\n", argv[0]);
                return 1;
        }
    }
    return 0;
}
```

---
[[00-Index|Back to Advanced Index]]
