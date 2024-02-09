/* header files go up here */
/* note that C comments are enclosed within a slash and
a star, and may wrap over lines */
// two slashes work too (and may be preferred)
#include <stdio.h>

// main returns an integer
int main(int argc, char *argv[])
{
    /* printf is our output function;
    by default, writes to standard out */
    /* printf returns an integer, but we ignore that */
    printf("hello, world\n");
    /* return 0 to indicate all went well */
    return (0);
}