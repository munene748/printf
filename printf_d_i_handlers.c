#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/* handle_di.c
 * handle_d_i - Handle conversion specifiers 'd' and 'i'.
 * @args: A va_list containing the argument.
 * Return: Number of characters printed.
 */
int handle_d_i(va_list args)
{
    int num = va_arg(args, int);
    int char_count = 0;

    /* Use printf to format and print the integer */
    char_count = printf("%d", num);

    return char_count;
}

