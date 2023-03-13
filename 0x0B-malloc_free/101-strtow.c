#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words in str
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			++count;
		}
	}
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, len, words;
	char **array;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	words = count_words(str);
	if (words == 0)
	{
		return (NULL);
	}
	array = malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0, j = 0; j < words; ++j)
	{
		while (str[i] == ' ')
		{
			++i;
		}
		len = 0;
		while (str[i + len] != ' ' && str[i + len] != '\0')
		{
			++len;
		}
		array[j] = malloc(sizeof(char) * (len + 1));
		if (array[j] == NULL)
		{
			for (k = 0; k < j; ++k)
			{
				free(array[k]);
			}
			free(array);
			return (NULL);
		}
		for (k = 0; k < len; ++k)
        {
            array[j][k] = str[i + k];
        }
		array[j][len] = '\0';
		i += len;
	}
	array[j] = NULL;
	return (array);
}
