#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h> /* For sprintf */

#define BUFF_SIZE 1024

/**
 * print_buffer - Prints buffer contents.
 * @buffer: Array of characters.
 * @buff_ind: Index for the next character, resets to 0.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

/**
 * _printf - Custom printf function.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int i, char_count = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			char_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (format[i] == 'c')
			{
				int c = va_arg(list, int);
				buffer[buff_ind++] = c;
				char_count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(list, char *);
				if (s)
				{
					while (*s)
					{
						buffer[buff_ind++] = *s++;
						char_count++;
					}
				}
			}
			else if (format[i] == 'd' || format[i] == 'u')
			{
				char num_str[20];
				int num = va_arg(list, int);
				sprintf(num_str, (format[i] == 'd') ? "%d" : "%u", num);
				int j;
				for (j = 0; num_str[j]; j++)
				{
					buffer[buff_ind++] = num_str[j];
					char_count++;
				}
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (char_count);
}

