#include "main.h"

unsigned int convert_to_lowercase_hex(va_list args, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision,
		unsigned char length_modifier);
unsigned int convert_to_uppercase_hex(va_list args, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision,
		unsigned char length_modifier);

/**
 * convert_to_lowercase_hex - Converts an unsigned integer argument to hexadecimal
 * using lowercase abcdef then buffers the result.
 * @args: A va_list pointing to the argument to be converted.
 * @buffer_output: A buffer_t structure containing a character array.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @length_modifier: Length modifier for type of integer (long, short).
 *
 * Return: Buffered characters count
 */
unsigned int convert_to_lowercase_hex(va_list args, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision,
		unsigned char length_modifier)
{
	unsigned long int number;
	unsigned int buffered_count = 0;
	char *prefix = "0x";

	if (length_modifier == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);
	if (length_modifier == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		buffered_count += _memcpy(buffer_output, prefix, 2);

	if (!(number == 0 && precision == 0))
		buffered_count += convert_ubase(buffer_output, number, "0123456789abcdef",
				format_flags, width, precision);

	buffered_count += print_neg_width(buffer_output,
	buffered_count, format_flags, width);

	return (buffered_count);
}

/**
 * convert_to_uppercase_hex - Converts an unsigned integer argument to hexadecimal
 * using uppercase ABCDEF ,then buffers the result.
 * @args: A va_list pointing to the argument to be converted.
 * @buffer_output: A buffer_t structure containing a character array.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @length_modifier: Length modifier for type of integer (long, short).
 *
 * Return: Buffered characters count.
 */
unsigned int convert_to_uppercase_hex(va_list args, buffer_t *buffer_output,
		unsigned char format_flags, int width, int precision,
		unsigned char length_modifier)
{
	unsigned long int number;
	unsigned int buffered_count = 0;
	char *prefix = "0X";

	if (length_modifier == LONG)
		number = va_arg(args, unsigned long);
	else
		number = va_arg(args, unsigned int);
	if (length_modifier == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		buffered_count += _memcpy(buffer_output, prefix, 2);

	if (!(number == 0 && precision == 0))
		buffered_count += convert_ubase(buffer_output, number, "0123456789ABCDEF",
				format_flags, width, precision);

	buffered_count += print_neg_width(buffer_output,
	buffered_count, format_flags, width);

	return (buffered_count);
}
