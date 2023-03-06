#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

char *_strpbrk(char *s, char *accept)
{
	char *p;

	while (*s != '\0')
	{
		p = accept;

		while (*p != '\0')
		{
			if (*p == *s)
			{
				return (s);
			}
			p++;
		}
		s++;
	}

	return (NULL);
}
