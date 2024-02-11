/* Pointer variable method of processing an array */
#include <stdio.h>

main() {
    static int list[] = {20, 30, 35, 36, 39};
    int *p;
    int i = 0;
    p = list; /* Assign the starting address of the list */
    printf("\n The list is ...");
    while (i < 5)
    {
        printf("\n %d %d ---element", *p, i);
        i++;
        p++; /* increment pointer */
    }
}

