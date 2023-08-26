#include "monty.h"

global_t vg;
/**
 * free_vg - frees the global variables
 *
 * Return: no return
 */
void free_vg(void)
{
	free_listintd(vg.head);
	free(vg.buf);
	fclose(vg.fd);
}

/**
 * initialize - initializes global variables
 * @fd: file descriptor
 * Return: no return
 */
void initialize(FILE *fd)
{
	vg.lifo = 1;
	vg.cont = 1;
	vg.arg = NULL;
	vg.head = NULL;
	vg.fd = fd;
	vg.buf = NULL;
}

/**
 * check_input - check if the file exists and it can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *line[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	initialize(fd);
	nlines = getline(&vg.buf, &size, fd);
	while (nlines != -1)
	{
		line[0] = _strtok(vg.buf, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = getopcodes(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vg.cont);
				dprintf(2, "unknown instruction %s\n", line[0]);
				free_vg();
				exit(EXIT_FAILURE);
			}
			vg.arg = _strtok(NULL, " \t\n");
			f(&vg.head, vg.cont);
		}
		nlines = getline(&vg.buf, &size, fd);
		vg.cont++;
	}
	free_vg();
	return (0);
}

