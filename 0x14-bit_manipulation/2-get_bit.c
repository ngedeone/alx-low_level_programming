#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for exit() */
#include <limits.h> /* for ULONG_MAX */

/**
 * get_bit - gets the value of a bit at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit to get
 *
 * Return: the value of the bit at index index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * CHAR_BIT)
		return (-1);

	return ((n >> index) & 1); /* shift n right by index bits, then mask with 1 */
}
