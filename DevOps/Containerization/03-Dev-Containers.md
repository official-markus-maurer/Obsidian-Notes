# Dev Containers (VS Code)

Dev Containers allow you to use a Docker container as your full-featured development environment.
The VS Code UI runs on your host (Windows/Mac), but the compiler, debugger, and terminal run inside Linux (Docker).

## Setup
1.  Install "Dev Containers" extension in VS Code.
2.  Create `.devcontainer/devcontainer.json`.

## Configuration Example

```json
{
    "name": "C Development",
    "image": "mcr.microsoft.com/devcontainers/cpp:debian",
    "extensions": [
        "ms-vscode.cpptools"
    ],
    "postCreateCommand": "apt-get update && apt-get install -y cppcheck"
}
```

## Benefits
-   **Onboarding**: New team members just open the project and click "Reopen in Container". Everything is installed automatically.
-   **Consistency**: Everyone uses the exact same compiler version.

---
[[00-Index|Back to Index]]
