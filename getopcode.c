#include "monty.h"

/**
 * getopcodes - selects the opcode to perform
 *
 * @op: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*getopcodes(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, op) == 0)
			break;
	}
	return (instruct[i].f);
}
