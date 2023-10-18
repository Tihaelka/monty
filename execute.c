#include "monty.h"

/**
 * execute - Function that checks for a command "opcode" and execute the
 * function if there's a match.
 * @token: Tokane containing the opcode to execute.
 * @stack: Doubly linked list representation of a stack.
 * @line_num: Line number where the opcode was found.
 * Return: EXIT_SUCCESS in success, or EXIT_FAILURE on failure.
 */

int execute(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", pall},
		{"pint", mpint},
		{"pop", mpop},
		{"swap", mswap},
		{"add", madd},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}

/**
  * push - A function that pushes an element to stack.
  * @stack: The pointer to the stck struct.
  * @token: The pointer to command.
  * @line_num: The number of the line.
  * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
  */
int push(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new;
	int i = 0;

	if (token[1] == NULL)
		return (print(0, line_num));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (print(0, line_num));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage(0));

	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}

/**
 * mpush - A function that pushes an element to queue.
 * @stack: The pointer to the stck struct.
 * @token: The pointer to command.
 * @line_num: The number of the line.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int mpush(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new, *tmp = NULL;
	int i = 0;

	if (token[1] == NULL)
		return (print(0, line_num));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (print(0, line_num));
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage(0));
	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(token[1]);
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * pall - A function that prints the values of the stack_t.
 * @stack: The pointer to the top of a stack_t.
 * @line_num: The number of the line.
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
