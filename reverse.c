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


/*
Compares the files making sure that both files are working correctly
returns 1 if both file names are equal
*/
int areFileNamesTheSame(const char *file1, const char *file2) {
//    int result = strcmp(file1, file2);
//    printf("%d",result);
    return strcmp(file1, file2) == 0;
    
}


/*
Validates that a file isn't hard linked
return 1 if there if the number of hardlinks is greater than one
*/
int isHardlinked(const char *filename1, const char *filename2) {
    struct stat fileInfo1, fileInfo2;
    if (stat(filename1, &fileInfo1) == -1 || stat(filename2, &fileInfo2) == -1) {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }
    return fileInfo1.st_ino == fileInfo2.st_ino;
}


/*
Attempts to open a file and if the file is null or doesn't exist it exit with an error
*/
FILE *openFile(char *filename, char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "reverse: cannot open file '/no/such/file.txt'\n");
        exit(1);
    }
    return file;
}

/*
Main method
*/
int main(int argc, char *argv[])
{
    FILE *input = NULL;   
    FILE *output = stdout;
    const char *file1 = argv[1];
    const char *file2 = argv[2];
    char filename[100];


    switch(argc){
        case 1: // When the command is passed without more arguments: ./reverse
            printf("Enter the file location, then press CTRL + D");
            scanf("%99s", filename);
            input = openFile(filename, "r");
            reverseText(input, output, false);
            exit(0);
        break;
        case 2: //When the command is passed with the input file: ./reverse input.txt
            input = openFile(argv[1], "r");
            reverseText(input, output, false);
            exit(0);
        break;
        case 3: //When the command is passed with both input and output files: ./reverse input.txt output.txt
            input = openFile(argv[1] , "r");
            output = openFile(argv[2], "w");
            if(areFileNamesTheSame(file1, file2) || isHardlinked(file1, file2)){
                fprintf(stderr, "reverse: input and output file must differ\n");
                exit(1);
            }
            reverseText(input, output, true);
            exit(0);
        break;
        default: //When too many arguments are passed, meaning more than 2 files or other invalid arguments
            fprintf(stderr, "usage: reverse <input> <output>\n");
            exit(1);
        break;    
    }

}
