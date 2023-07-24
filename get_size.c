#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size specifiier: size to cast the argument,
 *0 if no size specifier found
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

/* check if the chr after current position is I(for long)*/
	if (format[curr_i] == 'l')
		size = S_LONG;

/* check if the chr after current position is h (for short)*/
	else if (format[curr_i] == 'h')
		size = S_SHORT;

/*If size is still 0, it means no size specifier was found*/
/*otherwise, update the pointer 'i' to point to the next position*/
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

