#include <stdio.h>

main() {
    int x = 15;
    printf("\n Value of x = %d", x);
    printf("\n Address of x = %u", &x);
    printf("\n Value at address %d = %d", *(&x));
}