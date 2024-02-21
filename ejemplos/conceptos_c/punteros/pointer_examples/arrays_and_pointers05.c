#include <stdio.h>

char *item [] = { 
                  "Chair",
                  "Table",
                  "Stool",
                  "Desk"
                };


int main() {
    char *ptr;      // declare a pointer to a string
    ptr = item[1]; // assign the appropriate pointer to ptr

    printf("Item 1:%s\n", ptr);

    printf("Items:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\n", item[i]);
    }
    return 0;
}

