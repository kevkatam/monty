#include "monty.h"

/**
 * strsch - searches if a char is inside a string
 * @str: string
 * @c: char to search
 * Return: 1 if succes 0 if not
 */
int strsch(char *str, char c)
{
	int cont = 0;

	while (str[cont] != '\0')
	{
		if (str[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (str[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtok - cuts a string into tokens depending on delimiter
 * @str: string to cut
 * @d: delimiter
 * Return: first part
 */
char *_strtok(char *str, char *d)
{
	static char *u;
	int i = 0, j = 0;

	if (!str)
		str = u;
	while (str[i] != '\0')
	{
		if (strsch(d, str[i]) == 0 && str[i + 1] == '\0')
		{
			u = str + i + 1;
			*u = '\0';
			str = str + j;
			return (str);
		}
		else if (strsch(d, str[i]) == 0 && strsch(d, str[i + 1]) == 0)
			i++;
		else if (strsch(d, str[i]) == 0 && strsch(d, str[i + 1]) == 1)
		{
			u = str + i + 1;
			*u = '\0';
			u++;
			str = str + j;
			return (str);
		}
		else if (strsch(d, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
