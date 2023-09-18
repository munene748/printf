#include "main.h"

unsigned int convert_signed_base(buffer_t *buffer, long int number,
char *conversion_base,
		unsigned char format_flags, int width, int precision);
unsigned int convert_unsigned_base(buffer_t *buffer,
unsigned long int number, char *conversion_base,
		unsigned char format_flags, int width, int precision);

/**
 * convert_signed_base - Converts a signed long integer to a specified base,
 * then buffers the result.
 * @buffer: A buffer_t structure containing a character array.
 * @number: The signed long integer to be converted.
 * @conversion_base: A string representation of the base for conversion.
 * @format_flags: Formatting flags used for the conversion.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 *
 * Return: The count of characters buffered.
 */
unsigned int convert_signed_base(buffer_t *buffer, long int number,
char *conversion_base,
		unsigned char format_flags, int width, int precision)
{
	int base_length;
	char digit, padding_char = '0';
	unsigned int buffered_count = 1;

	for (base_length = 0; *(conversion_base + base_length);)
		base_length++;

	if (number >= base_length || number <= -base_length)
		buffered_count += convert_signed_base(buffer, number /
		base_length, conversion_base,
				format_flags, width - 1, precision - 1);
	else
	{
		for (; precision > 1; precision--, width--) /* Address precision */
			buffered_count += _memcpy(buffer, &padding_char, 1);

		if (NEG_FLAG == 0) /* Address width */
		{
			padding_char = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; width > 1; width--)
				buffered_count += _memcpy(buffer, &padding_char, 1);
		}
	}

	digit = conversion_base[(number < 0 ? -1 : 1) * (number % base_length)];
	_memcpy(buffer, &digit, 1);

	return (buffered_count);
}

/**
 * convert_unsigned_base - Converts an unsigned long integer to a certain base
 * then buffers the result.
 * @buffer: A buffer_t structure
 * @number: unsigned long integer to be converted.
 * @conversion_base: string representation of the base for conversion.
 * @format_flags: Formatting flags. They are used for conversion.
 * @width: Width specification
 * @precision: Precision specification
 *
 * Return: The count of characters buffered.
 */
unsigned int convert_unsigned_base(buffer_t *buffer,
unsigned long int number, char *conversion_base,
		unsigned char format_flags, int width, int precision)
{
	unsigned int base_length, buffered_count = 1;
	char digit, padding_char = '0', *address_prefix = "0x";

	for (base_length = 0; *(conversion_base + base_length);)
		base_length++;

	if (number >= base_length)
		buffered_count += convert_unsigned_base(buffer,
		number / base_length, conversion_base,
				format_flags, width - 1, precision - 1);
	else
	{
		if (((format_flags >> 5) & 1) == 1) /* Addressing pointer representation */
		{
			width -= 2;
			precision -= 2;
		}
		for (; precision > 1; precision--, width--) /* Address precision */
			buffered_count += _memcpy(buffer, &padding_char, 1);

		if (NEG_FLAG == 0) /* Address width */
		{
			padding_char = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; width > 1; width--)
				buffered_count += _memcpy(buffer, &padding_char, 1);
		}
		if (((format_flags >> 5) & 1) == 1)
			buffered_count += _memcpy(buffer, address_prefix, 2);
	}

	digit = conversion_base[(number % base_length)];
	_memcpy(buffer, &digit, 1);

	return (buffered_count);
}
