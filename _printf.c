#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, print = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			printed_chars += print;
		}
	}

<<<<<<< HEAD
    int i;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            /* Add the character to the buffer */
            if (output_buffer.len < BUFFER_SIZE - 1)
            {
                output_buffer.buffer[output_buffer.len] = format[i];
                output_buffer.len++;
            }
            else
            {
                /* Buffer is full, write it to stdout and reset it */
                output_buffer.buffer[output_buffer.len] = '\0';
                write(1, output_buffer.buffer, output_buffer.len);
                output_buffer.len = 0;
            }
=======
	print_buffer(buffer, &buff_ind);
>>>>>>> ed4b70d5690053069a0861c669b59fe0280923a2

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
