# Bit Manipulation

C allows you to manipulate data at the bit level. This is useful for low-level programming, embedded systems, and optimizing storage.

## 🔢 Bitwise Operators

| Operator | Name | Description | Example (A=60, B=13) |
|---|---|---|---|
| `&` | AND | Copies a bit to result if it exists in both operands | `A & B = 12` (0000 1100) |
| `\|` | OR | Copies a bit if it exists in either operand | `A \| B = 61` (0011 1101) |
| `^` | XOR | Copies the bit if it is set in one operand but not both | `A ^ B = 49` (0011 0001) |
| `~` | NOT | Flips bits | `~A = -61` (1100 0011) |
| `<<` | Left Shift | Shifts bits to the left (multiply by 2^n) | `A << 2 = 240` |
| `>>` | Right Shift | Shifts bits to the right (divide by 2^n) | `A >> 2 = 15` |

## 🎭 Bit Masks
Used to set, clear, or toggle specific bits.

- **Set a bit**: `num |= (1 << n);`
- **Clear a bit**: `num &= ~(1 << n);`
- **Toggle a bit**: `num ^= (1 << n);`
- **Check a bit**: `if (num & (1 << n))`

---
[[00-Index|Back to Advanced Index]]
