#include "main.h"

unsigned int convert_signed_int(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type);
unsigned int convert_binary(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type);
unsigned int convert_unsigned(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type);
unsigned int convert_octal(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type);

/**
 * convert_signed_int - Converts the provided argument into a signed integer
 *                      and writes the converted result into a buffer.
 * @args: Argument list pointing to the integer to be converted.
 * @buffer: Struct containing a buffer to store the converted value.
 * @format_flags: Formatting flags for the conversion.
 * @width: The width for the formatted output.
 * @precision: Precision for the conversion.
 * @length_type: Specifies the length (e.g., short, long) of the argument.
 *
 * Return: The number of bytes written into the buffer.
 */
unsigned int convert_signed_int(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type)
{
	long int number, temp_num;
	unsigned int bytes_written = 0, digit_count = 0;
	char padding_char, space_char = ' ', negative_sign = '-', plus_sign = '+';

	if (length_type == LONG)
		number = va_arg(args, long int);
	else
		number = va_arg(args, int);

	if (length_type == SHORT)
		number = (short)number;

	// Formatting for space character
	if (SPACE_FLAG == 1 && number >= 0)
		bytes_written += _memcpy(buffer, &space_char, 1);

	// Calculate number width for formatting
	if (precision <= 0 && NEG_FLAG == 0)
	{
		if (number == LONG_MIN)
			digit_count += 19;
		else
		{
			for (temp_num = (number < 0) ? -number : number; temp_num > 0; temp_num /= 10)
				digit_count++;
		}

		// Adjust digit count based on various conditions
		digit_count += (number == 0) ? 1 : 0;
		digit_count += (number < 0) ? 1 : 0;
		digit_count += (PLUS_FLAG == 1 && number >= 0) ? 1 : 0;
		digit_count += (SPACE_FLAG == 1 && number >= 0) ? 1 : 0;

		// Apply specific formatting flags
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && number >= 0)
			bytes_written += _memcpy(buffer, &plus_sign, 1);
		if (ZERO_FLAG == 1 && number < 0)
			bytes_written += _memcpy(buffer, &negative_sign, 1);

		padding_char = (ZERO_FLAG == 1) ? '0' : ' ';
		for (width -= digit_count; width > 0; width--)
			bytes_written += _memcpy(buffer, &padding_char, 1);
	}

	// Handle negative numbers and positive numbers with specific flags
	if (ZERO_FLAG == 0 && number < 0)
		bytes_written += _memcpy(buffer, &negative_sign, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && number >= 0))
		bytes_written += _memcpy(buffer, &plus_sign, 1);

	// Convert the number to its base representation and write to buffer
	if (!(number == 0 && precision == 0))
		bytes_written += convert_sbase(buffer, number, "0123456789", format_flags, 0, precision);

	bytes_written += print_neg_width(buffer, bytes_written, format_flags, width);

	return (bytes_written);
}
/**
 * convert_binary - Converts an unsigned integer argument to its binary representation
 *                  and writes the converted result into a buffer.
 * @args: Argument list pointing to the number to be converted.
 * @format_flags: Formatting flags for the conversion.
 * @width: The width for the formatted output.
 * @precision: Precision for the conversion.
 * @length_type: Specifies the length (e.g., short, long) of the argument.
 * @buffer: Struct containing a buffer to store the converted value.
 *
 * Return: The number of bytes written into the buffer.
 */
unsigned int convert_binary(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type)
{
	unsigned int number;

	number = va_arg(args, unsigned int);

	// The length_type is not used in this function, so it's been commented out
	// (void)length_type;

	return (convert_ubase(buffer, number, "01", format_flags, width, precision));
}

/**
 * convert_octal - Converts an unsigned integer to its octal representation
 *                 and writes the converted result into a buffer.
 * @args: Argument list pointing to the number to be converted.
 * @format_flags: Formatting flags for the conversion.
 * @width: The width for the formatted output.
 * @precision: Precision for the conversion.
 * @length_type: Specifies the length (e.g., short, long) of the argument.
 * @buffer: Struct containing a buffer to store the converted value.
 *
 * Return: The number of bytes written into the buffer.
 */
unsigned int convert_octal(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type)
{
	unsigned long int number;
	unsigned int bytes_written = 0;
	char octal_lead = '0';

	if (length_type == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);

	if (length_type == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		bytes_written += _memcpy(buffer, &octal_lead, 1);

	if (!(number == 0 && precision == 0))
		bytes_written += convert_ubase(buffer, number, "01234567", format_flags, width, precision);

	bytes_written += print_neg_width(buffer, bytes_written, format_flags, width);

	return (bytes_written);
}

/**
 * convert_unsigned_decimal - Converts an unsigned integer argument to its decimal representation
 *                            and writes the result into a buffer.
 * @args: Argument list pointing to the number to be converted.
 * @format_flags: Formatting flags for the conversion.
 * @width: The width for the formatted output.
 * @precision: Precision for the conversion.
 * @length_type: Specifies the length (e.g., short, long) of the argument.
 * @buffer: Struct containing a buffer to store the converted value.
 *
 * Return: The number of bytes written into the buffer.
 */
unsigned int convert_unsigned_decimal(va_list args, buffer_t *buffer,
		unsigned char format_flags, int width, int precision, unsigned char length_type)
{
	unsigned long int number;
	unsigned int bytes_written = 0;

	if (length_type == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);

	if (length_type == SHORT)
		number = (unsigned short)number;

	if (!(number == 0 && precision == 0))
		bytes_written += convert_ubase(buffer, number, "0123456789",
				format_flags, width, precision);

	bytes_written += print_neg_width(buffer, bytes_written, format_flags, width);

	return (bytes_written);
}
