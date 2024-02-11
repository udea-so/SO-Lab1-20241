/* This program illustrates the usage of pointer to a string */
#include <stdio.h>

main()
{
    char text[] = "ENGINEERING"; /* The string */
    char *p;                     /* The pointer */
    p = text;                    /* Assign the starting address of string to p */
    printf("\n The string..");   /* Print the string */
    while (*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
}