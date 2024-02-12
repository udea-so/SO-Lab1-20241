/*
Author: Adalbert Gerald Soosai Raj
URL: https://pages.cs.wisc.edu/~gerald/cs354/Spring2019/code/lecture04/dynamic_array01.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
		exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

	// create a variable length array (vla)
    int a[num];

    for (int i = 0; i < num; ++i) {
        a[i] = 0;
    }

    for (int i = 0; i < num; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

