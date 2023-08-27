#include "monty.h"

/**
 * _push - pushes an element into the stack
 * @h: head of the list
 * @nline: line number
 * Return: no return
 */
void _push(stack_t **h, unsigned int nline)
{
	int i, j;

	if (!vg.arg)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "usage: push integer\n");
		free_vg();
		exit(EXIT_FAILURE);
	}
	for (j = 0; vg.arg[j] != '\0'; j++)
	{
		if (!isdigit(vg.arg[j]) && vg.arg[j] != '-')
		{
			dprintf(2, "L%u: ", nline);
			dprintf(2, "usage: push integer\n");
			free_vg();
			exit(EXIT_FAILURE);
		}
	}
	i = atoi(vg.arg);
	if (vg.lifo == 1)
		add_dnodeint(h, i);
	else
		add_dnodeint_end(h, i);
}

/**
 * _pall - prints all the values on the stack, starting from the
 *  top of the stack.
 *  @h: head of the linked list
 *  @nline: line numbers
 *  Return: no return
 */
void _pall(stack_t **h, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *h;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint -  prints the value at the top of the stack, followed by a new line.
 * @h: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void _pint(stack_t **h, unsigned int nline)
{
	(void)nline;

	if (*h == NULL)
	{
		dprintf(2, "L%u: ", nline);
		dprintf(2, "can't pint, stack empty\n");
		free_vg();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
/**
 * _pop -  removes the top element of the stack.
 * @h: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void _pop(stack_t **h, unsigned int nline)
{
	stack_t *temp;

	if (h == NULL || *h == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = (*h)->next;
	free(temp);
}

/**
 * _swap - swaps the top two elements of the stack.
 * @h: head of the linked list
 * @nline: line numbers
 * Return: no return
 */
void _swap(stack_t **h, unsigned int nline)
{
	int count = 0;
	stack_t *temp = NULL;

	temp = *h;
	for (; temp != NULL; temp = temp->next, count++)
		;
	if (count < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nline);
		free_vg();
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = (*h)->next;
	temp->next = (*h)->next;
	temp->prev = *h;
	(*h)->next = temp;
	(*h)->prev = NULL;
}
