# Encryption Basics

## Symmetric Encryption (Shared Key)
-   **Concept**: Same key for encryption and decryption.
-   **Speed**: Very fast.
-   **Examples**: AES (Advanced Encryption Standard), ChaCha20.
-   **Problem**: Key Distribution (how do I send you the key securely?).

## Asymmetric Encryption (Public/Private Key)
-   **Concept**: Two keys. Encrypt with Public, Decrypt with Private.
-   **Speed**: Slow.
-   **Examples**: RSA, Elliptic Curve (ECC).
-   **Solution**: Use Asymmetric to exchange a Symmetric Key (TLS Handshake).

---
[[00-Index|Back to Security Index]]
