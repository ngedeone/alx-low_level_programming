#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: the array of arguments
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

    /* Compute the length of the concatenated string */
	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++;
		/* Add 1 for the newline character */
	}

    /* Allocate memory for the concatenated string */
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

    /* Copy the arguments into the concatenated string */
	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0'; /* Add null terminator */
	return (str);
}
