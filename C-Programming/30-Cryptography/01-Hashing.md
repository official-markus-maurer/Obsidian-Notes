# Hashing (SHA-256)

Hashing transforms data into a fixed-size string of bytes. It is one-way (irreversible).

## 🛠️ Using OpenSSL (`libssl-dev`)

```c
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sha256_string(char *string, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int main() {
    char *data = "Hello World";
    char hash[65];
    sha256_string(data, hash);
    printf("SHA256: %s\n", hash);
    return 0;
}
```
*Compile with `-lssl -lcrypto`*

---
[[00-Index|Back to Cryptography Index]]
