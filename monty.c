#include "monty.h"

/**
 * main - The entry point
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (usage(1));

	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (open(av[1]));

	exit_status = mrun(fd);
	fclose(fd);
	return (exit_status);
		open(av[1]);
	mrun(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
