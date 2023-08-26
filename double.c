#include "monty.h"
/**
 * add_dnodeint - adds nodes at the beginning of the linked list
 * @head: head of the linked list
 * @n: value of the node to be added
 * Return: pointer to the new node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vg();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at end of doubly linked lists
 * @head: head of the list
 * @n: value of node to be added
 * Return: ponter to added node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *temp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vg();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	return (temp->next);
}

/**
 * free_listintd - frees doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_listintd(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
