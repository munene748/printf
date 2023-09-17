#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: string
 * Return: printed chars
 */
int _printf(const char *format, ...)
{

	va_list arg;
	int i = 0;

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

		 switch (format[i])
		 {

		case 'c':
		{
		 int c = va_arg(arg, int);
                 write(1, &c, 1);
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
                        }
                    }
                    break;
                 }

		case '%':
		write(1, &format[i], 1);
                break;

		default:
                write(1, &format[i], 1);
                break;
		 }
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(arg);

	return (i);
}
