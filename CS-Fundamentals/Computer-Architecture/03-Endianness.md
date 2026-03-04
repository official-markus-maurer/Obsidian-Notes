# Endianness

Endianness refers to the order in which bytes are stored in multi-byte data types (like `int`).

## Little-Endian (Intel/AMD)
Least Significant Byte (LSB) comes first.
`0x12345678` -> `78 56 34 12` in memory.

## Big-Endian (Network Order)
Most Significant Byte (MSB) comes first.
`0x12345678` -> `12 34 56 78` in memory.

## Detecting Endianness in C
```c
int num = 1;
if (*(char*)&num == 1) {
    printf("Little-Endian\n");
} else {
    printf("Big-Endian\n");
}
```

## Network Programming
TCP/IP uses Big-Endian. Always use `htons()` (Host to Network Short) and `htonl()` when sending integers over the network.

---
[[00-Index|Back to Index]]
