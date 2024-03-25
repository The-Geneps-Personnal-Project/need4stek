#include "lib.h"

char *get_input() {
    char *input = NULL;
    size_t bufsize = 0;

    // Read input from stdin
    ssize_t characters = getline(&input, &bufsize, stdin);
    
    // Check for errors or EOF
    if (characters == -1) {
        fprintf(stderr, "Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // Remove newline character if present
    if (input[characters - 1] == '\n')
        input[characters - 1] = '\0';

    return input;
}
