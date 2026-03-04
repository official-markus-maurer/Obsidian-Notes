# Vectors in C

A vector is an array of numbers representing a direction and magnitude.

## Struct Definition
```c
typedef struct {
    float x, y, z;
} Vec3;
```

## Operations

### Dot Product
`a · b = ax*bx + ay*by + az*bz`
-   Result is a scalar.
-   If 0, vectors are perpendicular.
-   Used for lighting calculations (Lambertian reflectance).

### Cross Product
`a x b`
-   Result is a vector perpendicular to both `a` and `b`.
-   Used to find surface normals.

---
[[00-Index|Back to Index]]
