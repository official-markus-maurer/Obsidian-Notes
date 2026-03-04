# Hashing (SHA-256)

Hashing transforms data into a fixed-size string of bytes. It is one-way (irreversible).

## 🛠️ Using OpenSSL (`libssl-dev`)

OpenSSL is the industry standard, but the API can be complex.

```c
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void sha256_string(const char *string, char outputBuffer[65]) {
    EVP_MD_CTX *mdctx;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    // 1. Create Context
    mdctx = EVP_MD_CTX_new();
    
    // 2. Init (SHA-256)
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    
    // 3. Update (Feed data)
    EVP_DigestUpdate(mdctx, string, strlen(string));
    
    // 4. Finalize
    EVP_DigestFinal_ex(mdctx, hash, &md_len);
    EVP_MD_CTX_free(mdctx);

    // Convert to Hex String
    for(unsigned int i = 0; i < md_len; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int main() {
    char hash[65];
    sha256_string("Hello World", hash);
    printf("SHA256: %s\n", hash);
    return 0;
}
```
*Compile with `-lssl -lcrypto`*

## ⚠️ Important Notes
-   **Never use MD5 or SHA1**: They are broken and insecure. Use SHA-256 or SHA-3 (Keccak).
-   **Password Hashing**: Do NOT use SHA-256 for passwords. It is too fast (vulnerable to brute-force). Use **Argon2** or **bcrypt**.

---
[[00-Index|Back to Cryptography Index]]
