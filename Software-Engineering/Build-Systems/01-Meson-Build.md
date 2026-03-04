# Meson Build System

Meson is an open source build system meant to be both extremely fast, and, even more importantly, as user friendly as possible. It uses Ninja as a backend.

## Why Meson?
-   **Fast**: Compiles to Ninja build files.
-   **Safe**: No Turing-complete language in build definitions (prevents spaghetti code).
-   **Cross-platform**: Works on Linux, macOS, Windows.
-   **Dependency Handling**: Built-in support for `pkg-config` and subprojects.

## Getting Started
Install Meson and Ninja (requires Python 3):
```bash
pip install meson ninja
```

## Example `meson.build`
Create a file named `meson.build` in your project root:

```meson
project('my_project', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# Find a dependency
gtkdep = dependency('gtk4', required : false)

# Define source files
src = ['main.c', 'utils.c']

# Create executable
executable('demo',
           src,
           dependencies : gtkdep,
           install : true)
```

## Building
1.  **Configure**: Setup the build directory.
    ```bash
    meson setup build
    ```
2.  **Compile**: Run the build.
    ```bash
    meson compile -C build
    ```
3.  **Test**: Run tests.
    ```bash
    meson test -C build
    ```

## Subprojects (Wraps)
Meson can download dependencies automatically using `.wrap` files in a `subprojects` directory.
Example `subprojects/zlib.wrap`:
```ini
[wrap-file]
directory = zlib-1.2.11
source_url = http://zlib.net/zlib-1.2.11.tar.gz
source_filename = zlib-1.2.11.tar.gz
source_hash = ...
```

---
[[00-Index|Back to Index]] | [[02-Ninja-Build|Next: Ninja]]
