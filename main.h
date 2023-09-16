#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/* Macro to define the buffer size*/
#define BUFF_SIZE 1024

/* Macros for flag characters*/
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4
#define FLAG_ZERO 8
#define FLAG_NEG 16

/*Macros for length modifiers*/
#define LENGTH_SHORT 1
#define LENGTH_LONG 2

/**
 * structbuffer_s - defines a buffer structure
 * @buffer: a pointer to a charcter array
 * @start: a pointer to the start of the buffer
 * @len: the length of the string stored in the buffer
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
}buffer_t;

/*Main Custom Printf Function*/
int _printf(const char *format, ...);

/*Prototypes for handling various format specifiers*/
int convert_char(va_list args);
int convert_str(va_list args);
int convert_int(va_list args);
int convert_percent(va_list args);
int convert_binary(va_list args);
int convert_unsigned(va_list args);
int convert_octal(va_list args);
int convert_hex(va_list args);
int convert_HEX(va_list args);
int convert_specialStr(va_list args);
int convert_pointer(va_list args);
int convert_reverse(va_list args);
int convert_ROT13(va_list args);

/*Funcction prototypes for handling flags,lengths,etc.*/
unsigned char handle_flags(const char *flags_str, char *index);
unsigned char handle_length(const char *length_modifier, char *index);
int handle_width(va_list args,const char *width_modifier, char *index);
int handle_precision(va_list args, const char *precision_modifier, char *index);

#endif /*MAIN_H*/


