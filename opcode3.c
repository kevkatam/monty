#include "monty.h"
/**
 * _mul - multiplies the second top element of the stack with the top
 *  element of the stack.
 *  @h: head of linked list
 *  @nline: line number
 *  Return: no return
 */
void _mul(stack_t **h, unsigned int nline)
{
	int count = 0;
	stack_t *temp = NULL;

	temp = *h;
	for (; temp != NULL; temp = temp->next, count++)
		;
	if (count < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = (*h)->next;
	temp->n *= (*h)->n;
	_pop(h, nline);
}
