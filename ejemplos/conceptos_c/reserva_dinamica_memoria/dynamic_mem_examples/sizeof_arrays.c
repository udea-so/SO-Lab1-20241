/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/sizeof_arrays.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a[100];
    int *p = malloc(sizeof(int) * 100);
    printf("size of a = %d\n", sizeof(a));
    printf("size of p = %d\n", sizeof(p));
    return 0;
}
