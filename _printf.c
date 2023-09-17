#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: string
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0; /* Number of characters printed */

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				write(1, &c, 1);
				char_count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s != NULL)
				{
					while (*s)
					{
						write(1, s, 1);
						s++;
						char_count++;
					}
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				char_count++;
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}

		format++;
	}

	va_end(args);
	return (char_count);
}

