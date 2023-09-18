#include "main.h"

unsigned int store_leading_spaces(buffer_t *buffer, unsigned int chars_printed,
		unsigned char formatting_flags, int width_modifier);
unsigned int store_string_spaces(buffer_t *buffer,
		unsigned char formatting_flags, int width_modifier, int precision_modifier, int string_length);
unsigned int store_trailing_spaces(buffer_t *buffer, unsigned int chars_stored,
		unsigned char formatting_flags, int width_modifier);

/**
 * store_leading_spaces - Stores leading spaces in a buffer with width modifier in mind.
 * @buffer: holds an array of characters.
 * @chars_printed: Characters number already added to the buffer for a particular specifier.
 * @formatting_flags: Modifiers for formatting.
 * @width_modifier: The width for formatting.
 *
 * Return: The count of bytes added to the buffer.
 */
unsigned int store_leading_spaces(buffer_t *buffer, unsigned int chars_printed,
		unsigned char formatting_flags, int width_modifier)
{
	unsigned int bytes_stored = 0;
	char space_char = ' ';

	if (NEG_FLAG == 0)
	{
		for (width_modifier -= chars_printed; width_modifier > 0; width_modifier--)
			bytes_stored += _memcpy(buffer, &space_char, 1);
	}

	return (bytes_stored);
}

/**
 * store_string_spaces - Adds preceding spaces to a buffer,
 * while having in mind width and precision modifiers
 * @buffer: A buffer_t struct holding an array of characters.
 * @formatting_flags: Modifiers for formatting.
 * @width_modifier: Formatting width
 * @precision_modifier: Formatting precision.
 * @string_length: String length
 *
 * Return: The count of bytes added to the buffer.
 */
unsigned int store_string_spaces(buffer_t *buffer,
		unsigned char formatting_flags, int width_modifier,
		int precision_modifier, int string_length)
{
	unsigned int bytes_stored = 0;
	char space_char = ' ';

	if (NEG_FLAG == 0)
	{
		width_modifier -= (precision_modifier == -1) ? string_length : precision_modifier;
		for (; width_modifier > 0; width_modifier--)
			bytes_stored += _memcpy(buffer, &space_char, 1);
	}

	return (bytes_stored);
}

/**
 * store_trailing_spaces - Stores trailing spaces in the buffer for the '-' flag.
 * @buffer: A buffer_t struct holding an array of characters.
 * @chars_stored: Bytes already added to the buffer for a particular specifier.
 * @formatting_flags: Modifiers for formatting.
 * @width_modifier: The width for formatting.
 *
 * Return: The count of bytes added to the buffer.
 */
unsigned int store_trailing_spaces(buffer_t *buffer, unsigned int chars_stored,
		unsigned char formatting_flags, int width_modifier)
{
	unsigned int bytes_stored = 0;
	char space_char = ' ';

	if (NEG_FLAG == 1)
	{
		for (width_modifier -= chars_stored; width_modifier > 0; width_modifier--)
			bytes_stored += _memcpy(buffer, &space_char, 1);
	}

	return (bytes_stored);
}
