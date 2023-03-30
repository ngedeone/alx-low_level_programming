#include "3-calc.h"

/**
 * op_add - Adds two integers
 *
 * @a: The first integer to be added
 * @b: The second integer to be added
 *
 * Return: The result of the addition
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtracts two integers
 *
 * @a: The first integer to be subtracted
 * @b: The second integer to be subtracted
 *
 * Return: The result of the subtraction
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two integers
 *
 * @a: The first integer to be multiplied
 * @b: The second integer to be multiplied
 *
 * Return: The result of the multiplication
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides two integers
 *
 * @a: The first integer to be divided
 * @b: The second integer to be divided
 *
 * Return: The result of the division
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Computes the remainder of dividing two integers
 *
 * @a: The first integer to be divided
 * @b: The second integer to be divided
 *
 * Return: The remainder of dividing a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
