/* This program illustrates the usage of pointers to
exchange the contents of two variables */

#include <stdio.h>

main() {
    int x, y;
    int *p1, *p2, *p3; /* pointers to integers */
    printf("\n Enter two integer values");
    scanf("%d %d", &x, &y);
    /* Assign the addresses x and y to p1 and p2 */
    p1 = &x;
    p2 = &y;
    /* Exchange the pointers */
    p3 = p1;
    p1 = p2;
    p2 = p3;
    /* Print the contents through exchanged contents */
    printf("\n The exchanged contents are");
    printf(" %d & %d", *p1, *p2);
}