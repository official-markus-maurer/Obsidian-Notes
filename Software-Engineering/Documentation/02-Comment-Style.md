# Comment Styles

Doxygen supports multiple comment styles. Pick one and stick to it.

## Javadoc Style (Recommended)
Uses `/** ... */` block or `///` single line.

```c
/**
 * @brief Calculates the sum of two integers.
 * 
 * @param a First integer.
 * @param b Second integer.
 * @return The sum of a and b.
 */
int add(int a, int b);
```

## Qt Style
Uses `/*! ... */`.

```c
/*!
  \brief Calculates the area.
  \param r Radius.
  \return Area.
*/
double area(double r);
```

## Key Tags
-   `@brief`: Short description (one line).
-   `@details`: Long description.
-   `@param [in/out] name`: Parameter description.
-   `@return`: Return value description.
-   `@note`: Important notes/warnings.
-   `@deprecated`: Mark functions that shouldn't be used.

---
[[00-Index|Back to Index]]
