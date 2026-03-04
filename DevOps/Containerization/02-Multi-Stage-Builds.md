# Multi-Stage Builds

A typical GCC image is huge (>1GB) because it contains the compiler, headers, and build tools.
You don't need these in production; you only need the compiled binary and runtime libraries.

**Multi-stage builds** solve this by using one image to build and another to run.

## Example: Static Build (Alpine)

```dockerfile
# Stage 1: Build
FROM alpine:latest AS builder
RUN apk add --no-cache build-base
WORKDIR /app
COPY . .
# Compile statically (-static) so it works without external libraries
RUN gcc -static -o myapp main.c

# Stage 2: Runtime
FROM alpine:latest
WORKDIR /app
# Copy ONLY the binary from the builder stage
COPY --from=builder /app/myapp .
CMD ["./myapp"]
```

## Result
The final image size will be tiny (<10MB), containing only Alpine Linux and your binary.

---
[[00-Index|Back to Index]] | [[03-Dev-Containers|Next: Dev Containers]]
