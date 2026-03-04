# JSON Parsing (cJSON)

C doesn't have built-in JSON support. `cJSON` is a popular, lightweight, and robust library for embedded systems and small applications.

## 📦 Setup

1.  Download `cJSON.c` and `cJSON.h`.
2.  Include `cJSON.h` and compile `cJSON.c` with your project.

## 📝 Creating JSON

```c
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create Root Object: {}
    cJSON *root = cJSON_CreateObject();
    
    // Add Items
    cJSON_AddStringToObject(root, "name", "John Doe");
    cJSON_AddNumberToObject(root, "age", 30);
    cJSON_AddBoolToObject(root, "active", 1);
    
    // Add Array: "scores": [10, 20, 30]
    int numbers[3] = {10, 20, 30};
    cJSON *scores = cJSON_CreateIntArray(numbers, 3);
    cJSON_AddItemToObject(root, "scores", scores);
    
    // Print to String (heap allocated)
    char *json_str = cJSON_Print(root);
    printf("%s\n", json_str);
    
    // Cleanup
    cJSON_Delete(root); // Recursively deletes all children
    free(json_str);     // Don't forget to free the string!
    return 0;
}
```

## 🔍 Parsing JSON

```c
const char *json_data = "{\"name\": \"Jane\", \"age\": 25, \"active\": true}";

cJSON *root = cJSON_Parse(json_data);
if (root == NULL) {
    printf("Error parsing JSON!\n");
    return 1;
}

// Access Items Safely
cJSON *name = cJSON_GetObjectItemCaseSensitive(root, "name");
if (cJSON_IsString(name) && (name->valuestring != NULL)) {
    printf("Name: %s\n", name->valuestring);
}

cJSON *age = cJSON_GetObjectItemCaseSensitive(root, "age");
if (cJSON_IsNumber(age)) {
    printf("Age: %d\n", age->valueint);
}

cJSON_Delete(root);
```

## ⚠️ Memory Management
`cJSON_Delete(root)` frees the entire tree. Never use a child pointer after deleting the root.

---
[[00-Index|Back to Serialization Index]]
