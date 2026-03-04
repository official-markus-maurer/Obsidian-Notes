# Binary Repositories

A binary repository manager is to binaries what Git is to source code.

## Popular Tools
1.  **JFrog Artifactory**: The industry standard. Supports Conan packages, Docker images, generic files.
2.  **Sonatype Nexus**: Open source alternative.
3.  **GitHub Packages**: Integrated with GitHub Actions.

## Workflow
1.  **Commit Code** -> GitHub.
2.  **CI Build** -> GitHub Actions compiles code.
3.  **Publish** -> Push `myapp-1.0.0.tar.gz` to Artifactory.
4.  **Deploy** -> Production server pulls `myapp-1.0.0.tar.gz` from Artifactory.

## Why not Git?
Git is designed for text diffs. Storing large binaries in Git bloats the repository size forever (every version is kept in history).

---
[[00-Index|Back to Index]] | [[02-Versioning-Binaries|Next: Versioning]]
