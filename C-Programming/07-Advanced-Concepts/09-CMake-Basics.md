# CMake Basics

CMake is a cross-platform build system generator. It generates native build files (like Makefiles or Visual Studio projects) for your environment.

## 📄 `CMakeLists.txt`

Every project root must have this file.

### Basic Example

```cmake
cmake_minimum_required(VERSION 3.10)

# Project Name
project(MyProject)

# Set C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add Executable (Target -> Source Files)
add_executable(my_app main.c utils.c)
```

## 🏗️ Building

1.  **Create a build directory** (out-of-source build):
    ```bash
    mkdir build
    cd build
    ```
2.  **Generate Build Files**:
    ```bash
    cmake ..
    ```
3.  **Compile**:
    ```bash
    cmake --build .
    ```

## 📦 Adding Libraries

```cmake
# Create a library
add_library(my_lib math.c)

# Link library to executable
target_link_libraries(my_app my_lib)
```

## 🌐 Variables

```cmake
set(SOURCES main.c utils.c)
add_executable(my_app ${SOURCES})
```

---
[[00-Index|Back to Advanced Index]]
