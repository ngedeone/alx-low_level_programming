#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

char *_strstr(char *haystack, char *needle)
{
	char *p1, *p2, *p3;

	if (*needle == '\0')
	{
		return haystack;
	}

	p1 = haystack;

	while (*p1 != '\0')
	{
		p2 = needle;
		p3 = p1;

		while (*p2 != '\0' && *p3 != '\0' && *p2 == *p3)
		{
			p2++;
			p3++;
		}
		if (*p2 == '\0')
		{
			return (p1);
		}
		p1++;
	}

	return (NULL);
}
