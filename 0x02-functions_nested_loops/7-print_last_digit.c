#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @n: the int to extract the last digit from
 * Return: value of the last digit
 */

int print_last_digit(int n)
{
	int w;

	if (n < 0)
		n = -n;

	w = n % 10;

	if (w < 0)
		w = -w;

	_putchar(w + '0');

	return (w);
}

