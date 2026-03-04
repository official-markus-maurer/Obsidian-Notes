# Doxygen Setup

Doxygen reads special comments in your `.h` and `.c` files and generates HTML, LaTeX, or XML documentation.

## Installation
```bash
sudo apt install doxygen graphviz
# or
brew install doxygen
```

## Configuration
Generate a configuration file:
```bash
doxygen -g
```
This creates a `Doxyfile`. Edit it to set:
-   `PROJECT_NAME = "My Project"`
-   `OUTPUT_DIRECTORY = doc`
-   `RECURSIVE = YES`
-   `HAVE_DOT = YES` (requires Graphviz, generates dependency graphs)

## Running Doxygen
```bash
doxygen
```
Open `doc/html/index.html` to see your documentation.

---
[[00-Index|Back to Index]] | [[02-Comment-Style|Next: Comment Style]]
