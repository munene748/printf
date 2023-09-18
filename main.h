#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros for buffer size */
#define BUFFER_SIZE 1024

/* Macros for flag characters */
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

/* Macros for length modifiers */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - Defines a buffer structure.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
    char *buffer;
    char *start;
    unsigned int len;
} buffer_t;

/* Main Custom Printf Function */
int _printf(const char *format, ...);

/* Converters */
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

/* Handlers */
unsigned char handle_flags(const char *flags_str, char *index);
unsigned char handle_length(const char *length_modifier, char *index);
int handle_width(va_list args, const char *width_modifier, char *index);
int handle_precision(va_list args, const char *precision_modifier, char *index);

#endif /* MAIN_H */

