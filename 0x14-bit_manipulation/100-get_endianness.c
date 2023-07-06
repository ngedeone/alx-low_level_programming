#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	union
	{
		int i;
		char c[sizeof(int)];
	} u;

	u.i = 1;
	return (u.c[0] == 1);
}
