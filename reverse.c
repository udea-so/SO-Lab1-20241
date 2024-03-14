/* header files go up here */
/* note that C comments are enclosed within a slash and
a star, and may wrap over lines */
// two slashes work too (and may be preferred)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
This method is the one that reverses the text line by line.
It takes the input and passes it through a buffer, reads each line and then prints it in reverse
*/
void reverseText(FILE *input, FILE *output, bool withOutput) {
    char **lines = NULL;
    char *buffer = NULL;
    size_t line_count = 0;
    ssize_t read;

    // Read lines from input file into dynamically allocated memory
    while ((read = getline(&buffer, &read, input)) != -1) {
        lines = realloc(lines, (line_count + 1) * sizeof(char *));
        lines[line_count] = malloc(read);
        strcpy(lines[line_count], buffer);
        line_count++;
    }

    // Print lines in reverse order to output file or stdout
    for (size_t i = line_count; i > 0; i--) {
        if(withOutput){
            fprintf(output, "%s", lines[i - 1]);
            free(lines[i - 1]);
        } else {
            fprintf(stdout, "%s", lines[i - 1]);
        }
        
    }

    // Free remaining allocated memory
    free(lines);
    free(buffer);
}