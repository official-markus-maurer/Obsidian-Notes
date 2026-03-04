# Memory Hierarchy

Modern CPUs are incredibly fast, but memory (RAM) is slow. The cache bridges this gap.

## The Hierarchy (Latency)
1.  **Registers**: < 1 ns (Instant)
2.  **L1 Cache**: ~1 ns
3.  **L2 Cache**: ~4 ns
4.  **L3 Cache**: ~10-20 ns
5.  **RAM**: ~100 ns
6.  **SSD**: ~10,000 ns
7.  **HDD**: ~10,000,000 ns

## Cache Locality
-   **Spatial Locality**: Accessing memory addresses near each other (e.g., iterating an array).
-   **Temporal Locality**: Accessing the same memory address repeatedly.

**Linked Lists vs Arrays**: Arrays are cache-friendly (contiguous). Linked Lists are cache-hostile (scattered pointers).

---
[[00-Index|Back to Index]]
