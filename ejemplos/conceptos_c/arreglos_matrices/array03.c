/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture03/array03.c 
*/

#include <stdio.h>

#define MAX 10

int main()
{
    int a[MAX];

    int i;

    // initialize the array to zeros.
    for (i = 0; i < MAX; ++i) {
        a[i] = 0;
    }

    // What happens if the array index is out of bounds?
    // Compare the behaviour with Java.
    for (i = 0; i < 2 * MAX; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

