# Operators

Operators are symbols that perform operations on variables and values.

## ➕ Arithmetic Operators

| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `+` | Addition | Adds two values | `x + y` |
| `-` | Subtraction | Subtracts one value from another | `x - y` |
| `*` | Multiplication | Multiplies two values | `x * y` |
| `/` | Division | Divides one value by another | `x / y` |
| `%` | Modulus | Returns the division remainder | `x % y` |
| `++` | Increment | Increases value by 1 | `++x` |
| `--` | Decrement | Decreases value by 1 | `--x` |

> Note: `/` performs integer division if both operands are integers (e.g., `5 / 2` is `2`, not `2.5`). To get a float result, cast one operand: `(float)5 / 2`.

## 🤝 Relational Operators

Used to compare two values. Returns `1` (true) or `0` (false).

| Operator | Description | Example |
|----------|-------------|---------|
| `==` | Equal to | `x == y` |
| `!=` | Not equal to | `x != y` |
| `>` | Greater than | `x > y` |
| `<` | Less than | `x < y` |
| `>=` | Greater than or equal to | `x >= y` |
| `<=` | Less than or equal to | `x <= y` |

## 🧠 Logical Operators

Used to combine conditional statements.

| Operator | Name | Description | Example |
|----------|------|-------------|---------|
| `&&` | AND | Returns true if both statements are true | `x < 5 && x < 10` |
| `\|\|` | OR | Returns true if one of the statements is true | `x < 5 \|\| x < 4` |
| `!` | NOT | Reverse the result, returns false if the result is true | `!(x < 5 && x < 10)` |

## 📥 Assignment Operators

| Operator | Example | Same As |
|----------|---------|---------|
| `=` | `x = 5` | `x = 5` |
| `+=` | `x += 3` | `x = x + 3` |
| `-=` | `x -= 3` | `x = x - 3` |
| `*=` | `x *= 3` | `x = x * 3` |
| `/=` | `x /= 3` | `x = x / 3` |
| `%=` | `x %= 3` | `x = x % 3` |

---
[[00-Index|Back to Basics Index]]
