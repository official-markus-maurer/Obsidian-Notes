# Binary Serialization

Binary is faster and smaller than text (JSON), but harder to debug.

## 📦 Struct Packing

By default, C compilers add padding to structs for alignment.
```c
struct Data {
    char c; // 1 byte
    // 3 bytes padding
    int i;  // 4 bytes
}; // Total: 8 bytes
```

To send this over network, you want it packed (5 bytes).

```c
struct __attribute__((packed)) PackedData {
    char c;
    int i;
};
```

## 🔄 Endianness
Different CPUs store integers differently (Little Endian vs Big Endian).
-   **Sender**: `htonl()` (Host to Network Long)
-   **Receiver**: `ntohl()` (Network to Host Long)

Always convert to Network Byte Order (Big Endian) before sending binary data.

---
[[00-Index|Back to Serialization Index]]
