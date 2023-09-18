#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	// Blank line after declarations to address the warning on line 35
	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
		{
			switch (format[i + 1])
			{
				case 'c':
					count += write(1, &(char){va_arg(args, int)}, 1);
					i++;
					break;
				case 's':
				{
					char *str = va_arg(args, char *);
					while (str && *str)
					{
						count += write(1, str++, 1);
					}
				}
				i++;
				break;
				case '%':
					count += write(1, &format[i], 1);
					i++;
					break;
			}
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}

	va_end(args);
	return (count);
}
