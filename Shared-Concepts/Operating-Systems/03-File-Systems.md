# File Systems

In Unix-like systems, "Everything is a file".

## Key Concepts

### Inode (Index Node)
A data structure that stores metadata about a file (permissions, owner, size, timestamps, location of data blocks). It does **not** store the filename.

### File Descriptor (FD)
An integer that uniquely identifies an open file for a process.
-   `0`: Standard Input (stdin)
-   **1**: Standard Output (stdout)
-   **2**: Standard Error (stderr)

### Permissions (chmod)
-   **Read (r)**: 4
-   **Write (w)**: 2
-   **Execute (x)**: 1
-   **Owner / Group / Others**: `rwxr-xr--` (754).

---
[[00-Index|Back to OS Index]]
