#include "main.h"

/**
 * get_bit - Return the value of a bit.
 *
 * @n: The number to get the bit from.
 * @index: The index of the bit to get.
 *
 * Return: The value of the bit, or -1 if an erro.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
