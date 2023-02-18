#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, j;

	for (i = 0; i <= 99; i++)
	{
		for (j = i; j <= 99; j++)
		{
			if (i != j)
			{
				if (i != 0 || j != 1)
				{
					putchar(',');
					putchar(' ');
				}

				if (i < 10)
				{
					putchar('0');
					putchar(i + '0');
				}
				else
				{
					putchar((i / 10) + '0');
					putchar((i % 10) + '0');
				}

				putchar(' ');
				if (j < 10)
				{
					putchar('0');
					putchar(j + '0');
				}
				else
				{
					putchar((j / 10) + '0');
					putchar((j % 10) + '0');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}

