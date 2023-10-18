#ifndef __MONTY_H__
#define __MONTY_H__

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int main(int ac, char **av);

void free_stack(stack_t **stack);

int mrun(FILE *fd);

char **tokening(char *line, char *delim);

int empty_line(char *line, char *delims);

int execute(char **token, stack_t **stack, unsigned int line_num);

int push(stack_t **stack, char **token, unsigned int line_num);

int mpush(stack_t **stack, char **token, unsigned int line_num);

void pall(stack_t **stack, unsigned int line_num);

void mpint(stack_t **stack, unsigned int line_num);

void mpop(stack_t **stack, unsigned int line_num);

void mswap(stack_t **stack, unsigned int line_num);

void madd(stack_t **stack, unsigned int line_num);

int usage(int option);

int open(char *filename);

int print(int option, unsigned int line_num);

#endif
