#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints the opcodes of a given function
 * @n: number of opcodes to print
 */
void print_opcodes(int n);

/**
 * main - entry point of program
 * @argc: argument count
 * @argv: array of pointers to argument strings
 *
 * Return: 0 on success, 1 if incorrect arguments, 2 if negative byte count
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	int n = atoi(argv[1]);

	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}

	print_opcodes(n);

	return (0);
}

void print_opcodes(int n)
{
	unsigned char *p = (unsigned char *)print_opcodes;
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%02x ", *p);
		p++;
	}

	printf("\n");
}

