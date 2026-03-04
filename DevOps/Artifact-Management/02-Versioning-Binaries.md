# Semantic Versioning (SemVer)

Binaries should be versioned using SemVer: `MAJOR.MINOR.PATCH` (e.g., `1.2.3`).

## Rules
1.  **MAJOR**: Incompatible API changes. (e.g., removing a function).
2.  **MINOR**: Backwards-compatible functionality (e.g., adding a function).
3.  **PATCH**: Backwards-compatible bug fixes.

## ABI Stability (Application Binary Interface)
In C, changing a `struct` layout breaks ABI. If you do this, you MUST increment the MAJOR version if the struct was public.

## Automated Versioning
Tools like `semantic-release` can analyze your commit messages (e.g., `fix: ...`, `feat: ...`) and automatically bump the version number and publish a release.

---
[[00-Index|Back to Index]]
