# Package Managers for C

Historically, C didn't have a standard package manager (like `npm` for Node or `cargo` for Rust). Dependencies were handled by system package managers (`apt`, `brew`) or git submodules.
Now, **Conan** and **vcpkg** are the industry standards for cross-platform C/C++ dependency management.

## 1. Conan
Conan is a decentralized package manager. It allows you to host your own packages.

### Installation
```bash
pip install conan
```

### Usage (conanfile.txt)
Create a `conanfile.txt` to list dependencies:
```ini
[requires]
fmt/8.1.1
zlib/1.2.11

[generators]
cmake
```

### Install Dependencies
```bash
mkdir build && cd build
conan install ..
```
This downloads libraries and generates a `conanbuildinfo.cmake` file.

### Integrate with CMake
```cmake
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(app main.c)
target_link_libraries(app ${CONAN_LIBS})
```

## 2. vcpkg
Developed by Microsoft, vcpkg is a command-line package manager that simplifies acquiring and building open source libraries on Windows, Linux, and macOS.

### Installation
```bash
git clone https://github.com/Microsoft/vcpkg.git
./vcpkg/bootstrap-vcpkg.sh
```

### Usage
Install a library:
```bash
./vcpkg install curl
```

Integrate with CMake (toolchain file):
```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
```

### Why use them?
-   **Version Locking**: Ensure all developers use the exact same version of a library.
-   **Cross-Compilation**: Easily build dependencies for Android, iOS, or Embedded Linux.
-   **Static Linking**: Switch between static and dynamic linking with a simple flag.

---
[[00-Index|Back to Index]] | [[../37-State-Machines/00-Index|Next Module: State Machines]]
