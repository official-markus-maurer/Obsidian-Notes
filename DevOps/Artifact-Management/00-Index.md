# Artifact Management

When your C code compiles successfully, you get a "binary artifact" (e.g., `app.exe`, `libmath.so`). You need a place to store these so they can be deployed.

## Topics
1.  [[01-Binary-Repositories]]: Artifactory, Nexus, and GitHub Packages.
2.  [[02-Versioning-Binaries]]: Semantic Versioning (SemVer) for compiled code.

## Why store artifacts?
-   **Speed**: Don't recompile everything on every deployment.
-   **History**: Rollback to `v1.2.3` if `v1.2.4` crashes.
-   **Security**: Ensure the binary hasn't been tampered with (checksums).

---
[[../00-Index|Back to DevOps Index]] | [[01-Binary-Repositories|Next: Binary Repos]]
