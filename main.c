#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    char *token;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&content, &size, file)) != -1) {
        counter++;

        token = strtok(content, " \t\n");
        if (token && *token != '#') {
            execute(&token, &stack, counter);
        }

        free(content);
        content = NULL;
    }

    free_stack(&stack);
    fclose(file);
    return (0);
}

