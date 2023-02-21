#include "main.h"

/**
* jack_bauer - prints every minute of the day of Jack Bauer
* starting from 00:00 to 23:59
*/

void jack_bauer(void)
{
	int w, j;

	w = 0;

	while (w < 24)
	{
		y = 0;
		while (y < 60)
		{
			_putchar((w / 10) + '0');
			_putchar((w % 10) + '0');
			_putchar(':');
			_putchar((y / 10) + '0');
			_putchar((y % 10) + '0');
			_putchar('\n');
			y++;
		}
		w++;
	}
}
