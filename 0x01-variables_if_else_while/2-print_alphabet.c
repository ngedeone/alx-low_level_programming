#include <stdio.h>

/**
 * main -  A program that prints the alphabet in lowercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 'a';
	
	do {
		putchar(c);
		c++;
	} while (c <= 'z');
	putchar('\n');
	return 0;
}
