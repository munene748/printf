#include "main.h"

void finalize_printing(va_list args, buffer_t *buffer);
int process_format_string(const char *format_str, va_list args, buffer_t *buffer);
int _printf(const char *format_str, ...);

/**
 * finalize_printing - Concludes the operations for _printf.
 * Makes sure buffer is flushed and cleanedup.
 * @args: A va_list of arguments passed to _printf.
 * @buffer: A buffer_t structure containing the character buffer.
 */
void finalize_printing(va_list args, buffer_t *buffer)
{
	va_end(args);
	write(1, buffer->start, buffer->len);
	free_buffer(buffer);
}

/**
 * process_format_string - Iterates through given format string,
 * and processes directives as well as buffering outputs.
 * @format_str: String with format specifiers to process and print.
 * @buffer: A buffer_t structure.It contains the character buffer.
 * @args: va_list of arguments paired with the format specifiers.
 *
 * Return: The total count of characters buffered.
 */
int process_format_string(const char *format_str,
va_list args, buffer_t *buffer)
{
	int index, width, precision, total_buffered = 0;
	char specifier_offset;
	unsigned char formatting_flags, specifier_length;
	unsigned int (*format_function)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (index = 0; *(format_str + index); index++)
	{
		specifier_length = 0;
		if (*(format_str + index) == '%')
		{
			specifier_offset = 0;
			formatting_flags = parse_flags(format_str + index + 1, &specifier_offset);
			width = parse_width(args, format_str + index + specifier_offset + 1, &specifier_offset);
			precision = parse_precision(args, format_str + index + specifier_offset + 1, &specifier_offset);
			specifier_length = parse_length(format_str + index + specifier_offset + 1, &specifier_offset);

			format_function = identify_format_function(format_str + index + specifier_offset + 1);
			if (format_function != NULL)
			{
				index += specifier_offset + 1;
				total_buffered += format_function(args, buffer, formatting_flags, width, precision, specifier_length);
				continue;
			}
			else if (*(format_str + index + specifier_offset + 1) == '\0')
			{
				total_buffered = -1;
				break;
			}
		}
		total_buffered += _memcpy(buffer, (format_str + index), 1);
		index += (specifier_length != 0) ? 1 : 0;
	}
	finalize_printing(args, buffer);
	return (total_buffered);
}

/**
 * _printf - Outputs a formatted string by interpreting
 * and processing format specifiers.
 * @format_str: String with potential format specifiers to process and print.
 *
 * Return: The count of characters effectively printed.
 */
int _printf(const char *format_str, ...)
{
	buffer_t *output_buffer;
	va_list args;
	int final_count;

	if (format_str == NULL)
		return (-1);

	output_buffer = initialize_buffer();
	if (output_buffer == NULL)
		return (-1);

	va_start(args, format_str);

	final_count = process_format_string(format_str, args, output_buffer);

	return (final_count);
}
