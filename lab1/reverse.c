/* header files go up here */
/* note that C comments are enclosed within a slash and
a star, and may wrap over lines */
// two slashes work too (and may be preferred)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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
            printf("%s", lines[i - 1]);
        }
        
    }

    // Free remaining allocated memory
    free(lines);
    free(buffer);
}



FILE *openFile(char *filename, char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }
    return file;
}

// main returns an integer
int main(int argc, char *argv[])
{
    FILE *input = NULL;   
    FILE *output = stdout;

    switch(argc){
        case 1: //Case if ./reverse
            printf("Enter the file location, then press CTRL + D");
            input = stdin;
            reverseText(input, output, false);
            exit(0);
        break;
        case 2: //Case if ./reverse input.txt
            input = openFile(argv[1], "r");
            reverseText(input, output, false);
            exit(0);
        break;
        case 3: //Case if ./reverse input.txt output.txt
            input = openFile(argv[1], "r");
            output = openFile(argv[2], "w");
            reverseText(input, output, true);
            exit(0);
        break;
        default: //If more than 3
            fprintf(stderr, "usage: reverse <input> <output>\n");
            exit(1);
    }

}