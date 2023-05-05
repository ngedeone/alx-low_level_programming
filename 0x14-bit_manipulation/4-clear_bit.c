#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0.
 * @n: pointer to the unsigned long int to modify.
 * @index: index of the bit to clear, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1 << index;
	mask = ~mask;
	*n &= mask;

	return (1);
}
