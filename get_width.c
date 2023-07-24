#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width. specification for formatting, 0 if no width found
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
/*If the char is '*', read the width from the variable arguments (va_list)*/
		else if (format[curr_i] == '*')
		{
			curr_i++; /*Move to the next character after '*'*/
			width = va_arg(list, int);
			break;/*Exit the loop since width is obtained*/
		}
		else
			break;
	}
/*Update the pointer 'i' to point to the last checked position in the format string*/
	*i = curr_i - 1;

	return (width);
}

