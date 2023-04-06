#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits needed
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits to flip to get from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result;
	unsigned int count = 0;

	xor_result = n ^ m; /* get the XOR of n and m */

	while (xor_result > 0) /* count the number of 1 bits in the XOR */
	{
		if ((xor_result & 1) == 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
