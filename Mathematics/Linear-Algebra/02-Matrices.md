# Matrices in C

In 3D graphics, we typically use 4x4 matrices to represent transformations.

## Row-Major vs Column-Major
C is typically Row-Major (like `mat[row][col]`), but OpenGL expects Column-Major data. Be careful when passing arrays to GPUs.

## Transformations

### Translation
Moves an object.
```
[ 1 0 0 x ]
[ 0 1 0 y ]
[ 0 0 1 z ]
[ 0 0 0 1 ]
```

### Identity Matrix
The "no-op" matrix.
```
[ 1 0 0 0 ]
[ 0 1 0 0 ]
[ 0 0 1 0 ]
[ 0 0 0 1 ]
```

---
[[00-Index|Back to Index]]
