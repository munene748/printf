#include "main.h"

unsigned int convert_char(va_list arguments, buffer_t *buffer_output,
		unsigned char format_flags, int width,
		int precision, unsigned char length);
unsigned int buffer_percent_sign(va_list arguments,
buffer_t *buffer_output,
		unsigned char format_flags, int width,
		int precision, unsigned char length);
unsigned int convert_address(va_list arguments, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision, unsigned char length);

/**
 * convert_char - Converts an argument to an unsigned char and buffers it.
 * @arguments: A va_list pointing to the argument to be converted.
 * @buffer_output: A buffer_t structure containing a character array.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting (not used for char).
 * @length: Length specification for formatting (not used for char).
 *
 * Return: The count of characters buffered.
 */
unsigned int convert_char(va_list arguments, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision, unsigned char length)
{
	char character;
	unsigned int buffered_count = 0;

	(void)precision;
	(void)length;

	character = va_arg(arguments, int);

	buffered_count += print_width(buffer_output, buffered_count,
	format_flags, width);
	buffered_count += _memcpy(buffer_output, &character, 1);
	buffered_count += print_neg_width(buffer_output, buffered_count,
	format_flags, width);

	return (buffered_count);
}

/**
 * buffer_percent_sign - Buffers a '%' sign into the buffer_output.
 * @arguments: A va_list pointing to the argument to be converted.
 * @buffer_output: A buffer_t structure containing a character array.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting (not used for %).
 * @length: Length specification for formatting (not used for %).
 *
 * Return: The count of characters buffered (always 1).
 */
unsigned int buffer_percent_sign(va_list arguments, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision, unsigned char length)
{
	char percent_symbol = '%';
	unsigned int buffered_count = 0;

	(void)arguments;
	(void)precision;
	(void)length;

	buffered_count += print_width(buffer_output, buffered_count,
	format_flags, width);
	buffered_count += _memcpy(buffer_output, &percent_symbol, 1);
	buffered_count += print_neg_width(buffer_output, buffered_count,
	format_flags, width);

	return (buffered_count);
}

/**
 * convert_address - Converts a pointer's address to its hexadecimal rep,
 *  then buffers it.
 * @arguments: A va_list pointing to the argument to be converted.
 * @buffer_output: A buffer_t structure containing a character array.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification
 * @precision: Precision specification
 * @length: Length specification for formattin only.
 *
 * Return: The count of characters buffered.
 */
unsigned int convert_address(va_list arguments, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision, unsigned char length)
{
	char *null_string = "(nil)";
	unsigned long int address_value;
	unsigned int buffered_count = 0;

	(void)length;

	address_value = va_arg(arguments, unsigned long int);
	if (address_value == '\0')
		return (_memcpy(buffer_output, null_string, 5));

	format_flags |= 32;
	buffered_count += convert_unsigned_base(buffer_output,
	address_value, "0123456789abcdef",
			format_flags, width, precision);
	buffered_count += print_neg_width(buffer_output, buffered_count,
	format_flags, width);

	return (buffered_count);
}
