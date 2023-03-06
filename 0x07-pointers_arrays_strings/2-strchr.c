#include "main.h"

/*
 * takes two arguments: a pointer to the string s, and the character c to search for.
 * For each character, the function checks if it is equal to the character c.
 * If it is, the function returns a pointer to that character in the string.
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	return (NULL);
}
