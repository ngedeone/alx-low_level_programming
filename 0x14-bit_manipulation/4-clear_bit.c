#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the unsigned long int to modify
 * @index: index of the bit to clear
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8)) /* check if index is valid */
		return (-1);

	*n = (*n & ~(1 << index)); /* clear the bit at the given index */

	return (1);
}