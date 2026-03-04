# Git Basics for C

## The `.gitignore` File
C builds generate many intermediate files (`.o`, `.d`, `.a`, `.so`). You must ignore them to keep the repo clean.

```gitignore
# Object files
*.o
*.obj

# Libraries
*.a
*.so
*.dll
*.dylib

# Executables (Windows)
*.exe

# Build directories
build/
bin/
dist/
```

## Compilation Artifacts
**NEVER commit compiled binaries.** They cause:
1.  Repo bloat (binaries are large and change often).
2.  Merge conflicts (binary files cannot be merged).
3.  Platform mismatch (your Windows `.exe` won't run on Linux).

---
[[00-Index|Back to Index]] | [[02-Branching-Strategies|Next: Branching Strategies]]
