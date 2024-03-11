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
        if (withOutput) {
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
        fprintf(stderr, "reverse: cannot open file '%s'\n", filename);
        exit(1);
    }
    return file;
}

int main(int argc, char *argv[]) {
    if (argc > 3) {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    FILE *outputFile = stdout;
    if (argc == 3) {
        outputFile = fopen(argv[2], "w");
        if (outputFile == NULL) {
            fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
            exit(1);
        }
    }

    reverseText(inputFile, outputFile, argc == 3);

    fclose(inputFile);
    if (argc == 3) {
        fclose(outputFile);
    }

    return 0;
}

