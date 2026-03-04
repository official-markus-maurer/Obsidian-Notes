# Symmetric Encryption (AES-GCM)

Symmetric encryption uses the same key for encryption and decryption.

## 🛡️ The Rule: Authenticated Encryption
**NEVER** use encryption without authentication (like standard AES-CBC). It allows attackers to tamper with the data (Bit-Flipping Attacks).

Always use **AEAD** (Authenticated Encryption with Associated Data).
-   **AES-256-GCM** (Hardware accelerated, standard).
-   **ChaCha20-Poly1305** (Faster on mobile/software, standard).

## 📝 Example: Libsodium (Easy Mode)
Libsodium is a modern, easy-to-use crypto library. It uses ChaCha20-Poly1305 by default for `secretbox`.

```c
#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main() {
    if (sodium_init() < 0) return 1;

    // 1. Generate Key (Keep this secret!)
    unsigned char key[crypto_secretbox_KEYBYTES];
    crypto_secretbox_keygen(key);

    // 2. Generate Nonce (Number used ONCE). Must be unique per message.
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof nonce);

    // 3. Encrypt
    unsigned char message[] = "Attack at Dawn";
    unsigned char ciphertext[crypto_secretbox_MACBYTES + sizeof message];

    crypto_secretbox_easy(ciphertext, message, sizeof message, nonce, key);

    // 4. Decrypt
    unsigned char decrypted[sizeof message];
    if (crypto_secretbox_open_easy(decrypted, ciphertext, sizeof ciphertext, nonce, key) != 0) {
        printf("⚠️ Decryption failed! Message tampered or wrong key.\n");
        return 1;
    }
    
    printf("Decrypted: %s\n", decrypted);
    return 0;
}
```
*Compile with `-lsodium`*

---
[[00-Index|Back to Cryptography Index]]
