#include <stdio.h>
#include <assert.h>
#include "mymath.h"

int main() {
    printf("Running tests...\n");
    
    assert(math_add(2, 3) == 5);
    assert(math_sub(5, 2) == 3);
    
    printf("All tests passed!\n");
    return 0;
}
