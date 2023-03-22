#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints a name using the function pointed to by f
 * @name: the name to print
 * @f: a pointer to the function to use for printing
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}
