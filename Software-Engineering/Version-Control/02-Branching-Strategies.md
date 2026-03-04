# Branching Strategies

## Git Flow
Classic model with `develop`, `master`, `feature/*`, and `release/*` branches.
-   **Pros**: strict control, good for versioned releases.
-   **Cons**: complex, can slow down integration.

## Trunk-Based Development
Developers push directly to `main` (or short-lived feature branches).
-   **Pros**: Fast iteration, avoids "merge hell".
-   **Cons**: Requires strong CI (automated testing) to prevent breaking `main`.

## Which for C?
-   **Libraries**: Often use Git Flow or Semantic Versioning tags (v1.0.0).
-   **Applications**: Trunk-based is becoming more popular with modern CI.

---
[[00-Index|Back to Index]] | [[03-Submodules|Next: Submodules]]
