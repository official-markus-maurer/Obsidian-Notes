# GitHub Actions for C

GitHub Actions is a CI/CD platform that automates your build, test, and deployment pipeline.

## Basic Workflow (`.github/workflows/c-cpp.yml`)

Create this file in your repository:

```yaml
name: C/C++ CI

on:
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v3
    
    - name: Install Dependencies
      run: sudo apt-get update && sudo apt-get install -y libgtk-4-dev

    - name: Configure CMake
      run: cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=Release

    - name: Build
      run: cmake --build ${{github.workspace}}/build

    - name: Test
      run: ctest --test-dir ${{github.workspace}}/build
```

## Matrix Build
Test across multiple OSes simultaneously:

```yaml
jobs:
  build:
    runs-on: ${{ matrix.os }}
    strategy:
      matrix:
        os: [ubuntu-latest, windows-latest, macos-latest]
    
    steps:
      # ... steps adapted for cross-platform ...
```

---
[[00-Index|Back to Index]] | [[02-Code-Coverage|Next: Code Coverage]]
