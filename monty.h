#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global - global structure to use in functions
 * @lifo: stack or queue
 * @cont: current line
 * @arg: second paramater in current line
 * @fd: file descriptor
 * @head: head of doubly linked list
 * @buf: input text
 *
 * Description: doubly linked list node structure for
 * stack, queues, LIFO, FIFO
 */
typedef struct global
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buf;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vg;

stack_t *add_dnodeint(stack_t **h, const int n);
void free_vg(void);
void initialize(FILE *fd);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_listintd(stack_t *head);
void _push(stack_t **h, unsigned int nline);
void (*getopcodes(char *op))(stack_t **stack, unsigned int line_number);
int strsch(char *s, char c);
char *_strtok(char *str, char *d);
void _pall(stack_t **h, unsigned int nline);
void _pint(stack_t **h, unsigned int nline);
void _pop(stack_t **h, unsigned int nline);
void _swap(stack_t **h, unsigned int nline);
void _add(stack_t **h, unsigned int nline);


#endif
