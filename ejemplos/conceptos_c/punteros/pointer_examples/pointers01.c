/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/pointers.c
*/

#include <stdio.h>

int main()
{
    int a = 1000;
    int b = 2000;

    int *pa = &a;
    int *pb;

    pb = &b;

    // Print values of a and b.
    printf("a = %d\t *pa = %d\n", a, *pa);
    printf("b = %d\t *pb = %d\n", b, *pb);

    // Print addresses of a and b.
    printf("&a = %p\t pa = %p\n", &a, pa);
    printf("&b = %p\t pb = %p\n", &b, pb);
}
