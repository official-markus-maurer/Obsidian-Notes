# Symmetric Encryption (AES)

Symmetric encryption uses the same key for encryption and decryption.

## 🛡️ AES-GCM
Always use **Authenticated Encryption** (like AES-GCM or ChaCha20-Poly1305). It ensures data hasn't been tampered with.

## 📝 Concept (using Libsodium)
Libsodium is easier and safer than OpenSSL for beginners.

```c
#include <sodium.h>

int main() {
    if (sodium_init() < 0) return 1;

    unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    unsigned char message[] = "Secret Message";
    unsigned char ciphertext[crypto_secretbox_MACBYTES + sizeof(message)];

    // Generate random key and nonce
    randombytes_buf(key, sizeof key);
    randombytes_buf(nonce, sizeof nonce);

    // Encrypt
    crypto_secretbox_easy(ciphertext, message, sizeof message, nonce, key);

    // Decrypt
    unsigned char decrypted[sizeof message];
    if (crypto_secretbox_open_easy(decrypted, ciphertext, sizeof ciphertext, nonce, key) != 0) {
        // Decryption failed (wrong key or tampered data)
        return 1;
    }
    
    return 0;
}
```

---
[[00-Index|Back to Cryptography Index]]
