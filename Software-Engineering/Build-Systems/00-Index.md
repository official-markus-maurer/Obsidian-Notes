# Modern Build Systems

Gone are the days when manually writing Makefiles was the only way to build C projects. Modern build systems abstract complexity, handle cross-compilation, and manage dependencies efficiently.

## Topics
1.  [[01-Meson-Build]]: A high-level, user-friendly build system (like CMake but simpler).
2.  [[02-Ninja-Build]]: A small build system focused on speed (replaces Make).
3.  [[03-Package-Managers]]: Using Conan and vcpkg for C dependencies.

## Why Modern Build Systems?
-   **Speed**: Ninja builds are significantly faster than Make due to better parallelization.
-   **Usability**: Meson's syntax is Python-like and readable.
-   **Dependencies**: Automatic fetching and building of libraries (libcurl, OpenSSL, etc.).
-   **Cross-Compilation**: Native support for building for ARM/Embedded from x86.

---
[[../00-Index|Back to SE Index]] | [[../../C-Programming/00-Start-Here|Back to C Roadmap]] | [[01-Meson-Build|Next: Meson]]
