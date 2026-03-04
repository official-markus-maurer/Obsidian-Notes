# Binary Serialization

Binary serialization involves writing data structures directly to a file or network stream. It is faster and smaller than text formats (JSON, XML), but requires careful handling of padding and endianness.

## 📦 Struct Packing and Padding

By default, C compilers add padding bytes to structs for memory alignment. This makes structs non-portable across different architectures or compilers.

```c
struct Data {
    char c;     // 1 byte
    // 3 bytes PADDING (compiler inserted)
    int i;      // 4 bytes
}; 
// Total Size: 8 bytes
```

If you send this 8-byte struct to a machine that packs structs differently (or just expects 5 bytes), data will be corrupted.

### Solution: Packed Structs
Force the compiler to remove padding.

```c
// GCC / Clang
struct __attribute__((packed)) PackedData {
    char c;
    int i;
};
// Total Size: 5 bytes
```
*Note: Accessing unaligned members in a packed struct can be slow or cause faults on ARM/RISC-V.*

## 🔄 Endianness (Byte Order)

Different CPUs store multi-byte integers differently:
-   **Little Endian (x86, ARM, RISC-V)**: Least Significant Byte first (`0x78 0x56 0x34 0x12` for `0x12345678`).
-   **Big Endian (Network Standard, PowerPC)**: Most Significant Byte first (`0x12 0x34 0x56 0x78`).

### The Rule
**Always convert to Network Byte Order (Big Endian) before sending, and to Host Byte Order after receiving.**

```c
#include <arpa/inet.h> // Linux/macOS
// or <winsock2.h> for Windows

struct Packet {
    uint32_t id;
    uint16_t value;
} __attribute__((packed));

void send_packet(int sock, struct Packet *p) {
    struct Packet network_p;
    network_p.id = htonl(p->id);      // Host to Network Long
    network_p.value = htons(p->value); // Host to Network Short
    
    send(sock, &network_p, sizeof(network_p), 0);
}

void receive_packet(int sock) {
    struct Packet network_p;
    recv(sock, &network_p, sizeof(network_p), 0);
    
    struct Packet p;
    p.id = ntohl(network_p.id);       // Network to Host Long
    p.value = ntohs(network_p.value); // Network to Host Short
    
    printf("ID: %u, Value: %u\n", p.id, p.value);
}
```

---
[[00-Index|Back to Serialization Index]]
