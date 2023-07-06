#include "main.h"

/**
 * flip_bits - returns the number of bits needed
 * one number to another.
 * @n: first number.
 * @m: second number.
 *
 * Return: the number of bits you would need to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask = n ^ m;
	unsigned int count = 0;

	while (mask > 0)
	{
		count += mask & 1;
		mask >>= 1;
	}

	return (count);
}
