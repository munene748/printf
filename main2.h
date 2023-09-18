#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - Defines a buffer structure.
 * @buffer: A pointer to a character array.
 * @start: Where buffer startts.
 * @len: String lenth stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - Defines a converter's structure.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);
} converter_t;

/* Main Custom Printf Function */
int _printf(const char *format, ...);


unsigned int convert_char(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_str(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_int(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_percent(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_binary(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_unsigned(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_octal(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_hex(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_HEX(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_specialStr(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_pointer(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_reverse(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);
unsigned int convert_ROT13(va_list args, buffer_t *output,
unsigned char flags, int width, int precision, unsigned char length);


unsigned char handle_flags(const char *flags_str, char *index);
unsigned char handle_length(const char *length_modifier, char *index);
int handle_width(va_list args, const char *width_modifier, char *index);
int handle_precision(va_list args, const char *precision_modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
unsigned char, int, int, unsigned char);


unsigned int print_width(buffer_t *output, unsigned int printed_count,
unsigned char flags, int width);
unsigned int print_string_width(buffer_t *output, unsigned char flags,
int width, int precision, int string_size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed_count,
unsigned char flags, int width);


buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_signedBase(buffer_t *output, long int number, char *base,
unsigned char flags, int width, int precision);
unsigned int convert_unsignedBase(buffer_t *output,
unsigned long int number, char *base, unsigned char flags, int width, int precision);

#endif
