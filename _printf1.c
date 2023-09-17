#include "main.h"
#include <unistd.h>
/**
 *  _printf - produces output according to a format
 *  @format: string
 *  Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	va_start(arg,format);

	int printed_chars = 0;
	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'd' || format[i + 1] == 'i')
		{
		int a = va_arg(args, int);
		printed_chars++;
		i++;
		write(1, &a, 1);
	}
	else 
	{
		write(1, format[i], 1);
		printed_chars++;
	}
	}
	va_end(args);
	return (printed_chars);
}
