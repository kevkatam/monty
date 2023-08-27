#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void _add(stack_t **h, unsigned int nline)
{
	int count = 0;
	stack_t *temp = NULL;

	temp = *h;
	for (; temp != NULL; temp = temp->next, count++)
		;
	if (count < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	temp->n += (*h)->n;
	_pop(h, nline);
}

/**
 * _nop - doesn’t do anything.
 * @h: head of the list
 * @nline: line number
 * Return: no return
 */
void _nop(stack_t **h, unsigned int nline)
{
	(void)h;
	(void)nline;
}

/**
 * _sub -  subtracts the top element of the stack from the second
 * top element of the stack.
 * @h: head of the linked list
 * @nline: line number
 * Return: no return
 */
void _sub(stack_t **h, unsigned int nline)
{
	int count = 0;
	stack_t *temp = NULL;

	temp = *h;
	for (; temp != NULL; temp = temp->next, count++)
		;
	if (count < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	temp->n -= (*h)->n;
	_pop(h, nline);
}
/**
 * _div - divides the second top element of the stack by the top
 *  element of the stack.
 *  @h: head of the linked list
 *  @nline: line number
 *  Return: no return
 */
void _div(stack_t **h, unsigned int nline)
{
	int count = 0;
	stack_t *temp = NULL;

	temp = *h;
	for (; temp != NULL; temp = temp->next, count++)
		;
	if (count < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	temp->n /= (*h)->n;
	_pop(h, nline);
}
