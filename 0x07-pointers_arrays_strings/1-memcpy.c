#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	/* Copy bytes from src to dest */
	for (i = 0; i < n; i++)
		dest[i] = src[i];

	/* Return pointer to the destination memory area */
	return dest;
}
