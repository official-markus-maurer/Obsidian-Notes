# TCP vs UDP

## TCP (Transmission Control Protocol)
-   **Connection-Oriented**: Requires a handshake (SYN, SYN-ACK, ACK).
-   **Reliable**: Guarantees delivery and order. Retransmits lost packets.
-   **Flow Control**: Adjusts speed to prevent congestion.
-   **Use Cases**: Web (HTTP), Email (SMTP), File Transfer (FTP).

## UDP (User Datagram Protocol)
-   **Connectionless**: Fire and forget.
-   **Unreliable**: Packets may be lost, duplicated, or arrive out of order.
-   **Fast**: Low overhead (no handshake, no ACKs).
-   **Use Cases**: Streaming, Gaming, VoIP, DNS.

## Comparison
| Feature | TCP | UDP |
| :--- | :--- | :--- |
| Reliability | High | Low |
| Ordering | Guaranteed | None |
| Speed | Slower | Faster |
| Overhead | High (20 bytes header) | Low (8 bytes header) |

---
[[00-Index|Back to Networking Index]]
