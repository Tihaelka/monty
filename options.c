#include "monty.h"

/**
 * usage - Display program usage information
 * @option: Integer option that determine type of usage
 *
 * Return: None
 */
int usage(int option)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[option]);
	return (EXIT_FAILURE);
}

/**
 * open - open a file specified by the given name
 *
 * @filename: a pointer to a null terminated string representig file name
 *
 * Return: 0 on success, -1 on failure
 */
int open(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * print - print information based on provided option and line number.
 * @option: an integer that determine line information
 * @line_num: an ineteger representing the line number
 * Return: None
 */
int print(int option, unsigned int line_num)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
	     "can\'t pop an empty stack", "can\'t swap, stack too short",
	     "can\'t add, stack too short", "can\'t sub, stack too short",
	     "can\'t div, stack too short", "division by zero",
	     "can\'t mul, stack too short", "can\'t mod, stack too short",
	     "can\'t pchar, value out of range", "can\'t pchar, stack empty"};

	fprintf(stderr, "L%d: %s\n", line_num, errors[option]);
	return (EXIT_FAILURE);
}
