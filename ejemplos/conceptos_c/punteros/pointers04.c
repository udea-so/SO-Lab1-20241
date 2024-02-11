#include <stdio.h>

main() {
    int x = 15;
    int *y;
    y = &x;
    printf("\n Value of x = %d", x);
    printf("\n Address of x = %u", &x);
    printf("\n Value of x = %d", *y);
    printf("\n Address of x = %u", y);
    printf("\n Address of y = %u", &y);
}