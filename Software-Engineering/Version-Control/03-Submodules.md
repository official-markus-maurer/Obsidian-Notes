# Git Submodules

Before package managers like Conan, `git submodule` was the standard way to handle dependencies.

## Adding a Dependency
```bash
git submodule add https://github.com/cJSON/cJSON.git lib/cjson
```
This clones the repo into `lib/cjson` and locks it to a specific commit.

## Cloning a Repo with Submodules
Users must run:
```bash
git clone --recursive <repo-url>
# OR
git clone <repo-url>
git submodule update --init --recursive
```

## Pros vs Cons
-   **Pros**: No external tools needed (just git).
-   **Cons**: Easy to forget `--recursive`, complex to update.

---
[[00-Index|Back to Index]]
