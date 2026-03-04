# Docker Basics for C

A `Dockerfile` describes how to build your application inside an isolated environment.

## Simple Dockerfile
This uses the official GCC image to compile and run your code.

```dockerfile
# Start from a Linux image with GCC installed
FROM gcc:latest

# Set working directory
WORKDIR /usr/src/app

# Copy source code
COPY . .

# Compile
RUN gcc -o myapp main.c

# Run
CMD ["./myapp"]
```

## Building and Running

```bash
# Build the image
docker build -t my-c-app .

# Run the container
docker run --rm my-c-app
```

## Why use this?
-   **Reproducibility**: If it builds on your machine, it builds on the CI server.
-   **Isolation**: No need to install libraries globally on your host OS.

---
[[00-Index|Back to Index]] | [[02-Multi-Stage-Builds|Next: Multi-Stage Builds]]
