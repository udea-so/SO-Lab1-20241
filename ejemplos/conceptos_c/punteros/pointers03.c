#include <stdio.h>

int main() {
    int num = 10;
    int * pnum = &num;
    printf("num = %d\n", num);
    printf("*pnum = %d\n", *pnum);
    printf("&num = %p\n", &num);
    printf("pnum = %p\n", pnum);
    ++pnum;
    printf("pnum = %p\n", pnum);
    
    int arr[5] = {10, 20, 30, 40 ,50};
    int * parr = &arr[0];
    
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("%p\t", parr);
        printf("%d\n", *parr);
        parr++;
    }
    
    return 0;
}