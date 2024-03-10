/* header files go up here */
/* note that C comments are enclosed within a slash and
a star, and may wrap over lines */
// two slashes work too (and may be preferred)
#include <stdio.h>
#include <stdlib.h>


void reverseText(FILE *inputFile, FILE *outputFile, bool *withOutput) {
    const MAX_LENGTH = 256;
    char line = buffer[MAX_LENGTH];

    while(fgets(line, MAX_LENGTH, inputFile) != NULL){
        int lineLength = strlen(line);

        for(int i = lineLength -1, i >= 0; i--){
            if(withOutput){
                fputc(line[i], outputFile)
            } else {
                printf("%s", line[i])
            }
            
        }
    }

}

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