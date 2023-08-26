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
