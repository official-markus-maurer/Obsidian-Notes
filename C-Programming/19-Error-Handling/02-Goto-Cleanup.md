# Cleanup with `goto`

In many languages, `goto` is considered harmful. In C, it is a standard idiom for centralized error handling and resource cleanup.

## 🧹 The Pattern

When a function allocates multiple resources (files, memory, locks), failing halfway requires cleaning up only what was allocated.

### Without `goto` (Nested Hell)
```c
int process() {
    FILE *f = fopen("file", "r");
    if (!f) return -1;
    
    char *buf = malloc(1024);
    if (!buf) {
        fclose(f); // Duplicate cleanup
        return -1;
    }
    
    // ... work ...
    
    free(buf);
    fclose(f);
    return 0;
}
```

### With `goto` (Clean)
```c
int process() {
    FILE *f = NULL;
    char *buf = NULL;
    int ret = -1;

    f = fopen("file", "r");
    if (!f) goto cleanup;

    buf = malloc(1024);
    if (!buf) goto cleanup;

    // ... work ...
    ret = 0; // Success

cleanup:
    if (buf) free(buf);
    if (f) fclose(f);
    return ret;
}
```
This mimics the `finally` block in other languages.

---
[[00-Index|Back to Error Handling Index]]
