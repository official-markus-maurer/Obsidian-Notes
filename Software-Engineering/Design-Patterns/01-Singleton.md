# Singleton Pattern

The Singleton pattern ensures a "class" (struct) has only one instance and provides a global point of access to it.

## 🛠️ Implementation

In C, we use a `static` variable inside a function or file scope to hold the single instance.

```c
#include <stdio.h>

typedef struct {
    int config_value;
    char *db_name;
} Config;

// Get the single instance
Config* GetConfig() {
    static Config instance; // Initialized once
    static int initialized = 0;
    
    if (!initialized) {
        instance.config_value = 100;
        instance.db_name = "main.db";
        initialized = 1;
        printf("Config Initialized.\n");
    }
    
    return &instance;
}

int main() {
    Config *c1 = GetConfig();
    Config *c2 = GetConfig();
    
    // c1 and c2 point to the SAME memory address
    printf("Addr1: %p, Addr2: %p\n", (void*)c1, (void*)c2);
    
    return 0;
}
```

---
[[00-Index|Back to Design Patterns Index]]
