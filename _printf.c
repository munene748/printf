#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0;
	int printed_chars = 0;

	if (format == NULL)
	return (-1);


	va_start(arg, format);

	while (format[i])
	{

	if (format[i] == '%')
	{
	i++;
	       	if (format[i] == '\0')
                 break;

		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;


			switch (format[i])
			{
				case 'c':
				{
					int c = va_arg(arg, int);
					write(1, &c, 1);
					printed_chars++;
					break;
				}

				case 's':
				{
					char *s1 = va_arg(arg, char *);
					if (s1 != NULL)
					{
						while (*s1)
						{
							write(1, s1, 1);
							s1++;
							printed_chars++;
						}
					}
					break;
				}

				case '%':
					write(1, &format[i], 1);
					printed_chars++;
					break;

				default:
					write(1, &format[i], 1);
					printed_chars++;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}

	va_end(arg);


	return (i);

	return (printed_chars);
}
