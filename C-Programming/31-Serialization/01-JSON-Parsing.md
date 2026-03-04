# JSON Parsing (cJSON)

C doesn't have built-in JSON support. `cJSON` is a popular, lightweight library.

## 📝 Creating JSON

```c
#include "cJSON.h"

int main() {
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "John Doe");
    cJSON_AddNumberToObject(root, "age", 30);
    
    char *json_str = cJSON_Print(root);
    printf("%s\n", json_str);
    
    cJSON_Delete(root);
    free(json_str);
    return 0;
}
```

## 🔍 Parsing JSON

```c
char *json_data = "{\"name\": \"Jane\", \"age\": 25}";
cJSON *root = cJSON_Parse(json_data);

cJSON *name = cJSON_GetObjectItem(root, "name");
cJSON *age = cJSON_GetObjectItem(root, "age");

printf("Name: %s, Age: %d\n", name->valuestring, age->valueint);

cJSON_Delete(root);
```

---
[[00-Index|Back to Serialization Index]]
