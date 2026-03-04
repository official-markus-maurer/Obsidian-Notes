# The OSI Model

The Open Systems Interconnection (OSI) model conceptualizes how diverse communication systems communicate using standard protocols.

## The 7 Layers

1.  **Physical Layer**: Hardware (Cables, WiFi). Bitstream.
2.  **Data Link Layer**: Ethernet frames. MAC Addresses.
3.  **Network Layer**: IP Packets. Routing. (IP).
4.  **Transport Layer**: End-to-end connections. (TCP, UDP).
5.  **Session Layer**: Maintaining sessions.
6.  **Presentation Layer**: Data formatting (Encryption, Compression).
7.  **Application Layer**: User-facing protocols (HTTP, FTP, SSH).

## Why it matters
When writing C network code, you usually interact with Layer 4 (Transport) via Sockets, or Layer 7 (Application) via libraries like `libcurl`.

---
[[00-Index|Back to Networking Index]]
