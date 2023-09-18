#include "main.h"

unsigned char identify_flags(const char *potential_flag, char *format_index);
unsigned char identify_length(const char *length_modifier, char *format_index);
int identify_width(va_list args, const char *width_modifier, char *format_index);
int identify_precision(va_list args, const char *precision_modifier, char *format_index);
unsigned int (*identify_specifiers(const char *specifier))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char);

/**
 * identify_flags - Matches potential flags with their corresponding values.
 * @potential_flag: A pointer to a string that could contain flags.
 * @format_index: An index counter for the original format string.
 *
 * Return: If flag characters are identified - returns the corresponding value.
 *         Otherwise, returns 0.
 */
unsigned char identify_flags(const char *potential_flag, char *format_index)
{
	int flag_iterator, array_iterator;
	unsigned char return_flag_value = 0;
	flag_t defined_flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (flag_iterator = 0; potential_flag[flag_iterator]; flag_iterator++)
	{
		for (array_iterator = 0; defined_flags[array_iterator].flag != 0; array_iterator++)
		{
			if (potential_flag[flag_iterator] == defined_flags[array_iterator].flag)
			{
				(*format_index)++;
				if (return_flag_value == 0)
					return_flag_value = defined_flags[array_iterator].value;
				else
					return_flag_value |= defined_flags[array_iterator].value;
				break;
			}
		}
		if (defined_flags[array_iterator].value == 0)
			break;
	}

	return (return_flag_value);
}

/**
 * identify_length_modifier - Matches potential length modifiers to their
 * respective values.
 * @modifier: A pointer to a potential length modifier in the format string.
 * @format_index: An index counter for the original format string.
 *
 * Return: If a length modifier is identified, returns its corresponding value.
 *         Otherwise, returns 0.
 */
unsigned char identify_length_modifier(const char *modifier, char *format_index)
{
	if (*modifier == 'h')
	{
		(*format_index)++;
		return (SHORT);
	}
	else if (*modifier == 'l')
	{
		(*format_index)++;
		return (LONG);
	}

	return (0);
}

/**
 * identify_width_modifier - Matches potential width modifiers with their
 * respective values.
 * @args: A va_list of input arguments.
 * @modifier: A pointer to the string that could contain a width modifier.
 * @format_index: An index counter for the original format string.
 *
 * Return: If a width modifier is identified, returns its value.
 *         Otherwise, returns 0.
 */
int identify_width_modifier(va_list args, const char *modifier, char *format_index)
{
	int width_value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*format_index)++;

		if (*modifier == '*')
		{
			width_value = va_arg(args, int);
			if (width_value <= 0)
				return (0);
			return (width_value);
		}

		width_value *= 10;
		width_value += (*modifier - '0');
		modifier++;
	}

	return (width_value);
}

/**
 * identify_precision_modifier - Identifies and matches a
 * potential precision modifier
 * with its corresponding value.
 * @args: A va_list containing the arguments for the format string.
 * @modifier_str: A pointer to the potential position of a
 * precision modifier in the format string.
 * @format_index: An index counter for the original format string.
 *
 * Return: If a precision modifier is identified, it returns its value.
 *         If the precision modifier is empty, zero, or negative, it returns 0.
 *         Otherwise, returns -1 indicating no precision modifier was found.
 */
int identify_precision_modifier(va_list args,
const char *modifier_str, char *format_index)
{
	int precision_value = 0;

	/*Check if the current character isn't a precision specifier ('.') */
	if (*modifier_str != '.')
		return (-1);

	/* Move to the next character after the precision specifier */
	modifier_str++;
	(*format_index)++;

	/* Check if the precision is neither a digit between 1-9 nor '*' */
	if ((*modifier_str <= '0' || *modifier_str > '9') &&
	     *modifier_str != '*')
	{
		if (*modifier_str == '0')
			(*format_index)++;
		return (0);
	}

	while ((*modifier_str >= '0' && *modifier_str <= '9') ||
	       (*modifier_str == '*'))
	{
		(*format_index)++;

		if (*modifier_str == '*')
		{
			precision_value = va_arg(args, int);
			if (precision_value <= 0)
				return (0);
			return (precision_value);
		}

		precision_value *= 10;
		precision_value += (*modifier_str - '0');
		modifier_str++;
	}

	return (precision_value);
}

/**
 * match_conversion_function - Matches a potential conversion
 * specifier in the format string
 * its corresponding conversion function.
 * @specifier_str: A pointer to the position of a
 * potential conversion specifier in the format string.
 *
 * Return: If a conversion function is matched,
 * it returns a pointer to the respective function.
 *         Otherwise, returns NULL.
 */
unsigned int (*match_conversion_function(const char
*specifier_str))(va_list, buffer_t *,
		unsigned char, int, int, unsigned char)
{
	int i;

	converter_t available_converters[] = {
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percent},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}
	};

	/*Loop through the available converters to find
	*a match with the provided specifier */
	for (i = 0; available_converters[i].func; i++)
	{
		if (available_converters[i].specifier == *specifier_str)
			return (available_converters[i].func);
	}

	return (NULL); /* When no matching conversion function was found */
}
