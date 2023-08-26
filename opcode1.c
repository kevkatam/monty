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
