# C Project Structure

Organizing a C project correctly is crucial for maintainability, especially as the codebase grows. A chaotic structure leads to circular dependencies, slow build times, and "spaghetti code."

## Topics
1.  [[01-Standard-Layout]]: The `src`, `include`, `build` convention.
2.  [[02-Header-Files]]: Include guards, `#pragma once`, and what belongs in a header.
3.  [[03-Opaque-Pointers]]: Implementing encapsulation (Private members in C).

## Why Structure Matters
-   **Separation of Concerns**: Interface (`.h`) vs Implementation (`.c`).
-   **Build Speed**: Proper dependencies allow incremental builds.
-   **Distribution**: Easier to package libraries for others to use.

---
[[../00-Start-Here|Back to Roadmap]] | [[01-Standard-Layout|Next: Standard Layout]]
