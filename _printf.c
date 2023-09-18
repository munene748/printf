#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Custom printf function with buffer.
 * @format: A format string.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
    va_list args; /* A variable-length argument list. */
    buffer_t output_buffer; /* Define a buffer structure. */
    int printed_chars = 0;

    va_start(args, format);

    /* Initialize the buffer with an array of characters */
    output_buffer.buffer = malloc(BUFFER_SIZE);
    if (output_buffer.buffer == NULL)
    {
        va_end(args);
        return (-1); /* Error handling for buffer allocation failure */
    }

    output_buffer.start = output_buffer.buffer;
    output_buffer.len = 0;

    int i; /* Declare 'i' at the beginning of the function */
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            /* Add the character to the buffer */
            if (output_buffer.len < BUFFER_SIZE - 1)
            {
                output_buffer.buffer[output_buffer.len] = format[i];
                output_buffer.len++;
            }
            else
            {
                /* Buffer is full, write it to stdout and reset it */
                output_buffer.buffer[output_buffer.len] = '\0';
                write(1, output_buffer.buffer, output_buffer.len);
                output_buffer.len = 0;
            }

            printed_chars++;
        }
        else
        {
            i++; /* Move to the next character after '%' */
            if (format[i] == '\0')
                break;

            /* Handle format specifiers using your custom functions */
            switch (format[i])
            {
                case 'c':
                    printed_chars += convert_char(args, &output_buffer, 0, 0, 0, 0);
                    break;

                case 's':
                    printed_chars += convert_str(args, &output_buffer, 0, 0, 0, 0);
                    break;

                case '%':
                    /* Add the '%' character to the buffer */
                    if (output_buffer.len < BUFFER_SIZE - 1)
                    {
                        output_buffer.buffer[output_buffer.len] = '%';
                        output_buffer.len++;
                    }
                    else
                    {
                        /* Buffer is full, write it to stdout and reset it */
                        output_buffer.buffer[output_buffer.len] = '\0';
                        write(1, output_buffer.buffer, output_buffer.len);
                        output_buffer.len = 0;
                    }

                    printed_chars++;
                    break;

                /* Add more cases for other format specifiers as needed */

                default:
                    /* Print the '%' character itself and the unknown specifier */
                    if (output_buffer.len < BUFFER_SIZE - 2)
                    {
                        output_buffer.buffer[output_buffer.len] = '%';
                        output_buffer.buffer[output_buffer.len + 1] = format[i];
                        output_buffer.len += 2;
                    }
                    else
                    {
                        /* Buffer is full, write it to stdout and reset it */
                        output_buffer.buffer[output_buffer.len] = '\0';
                        write(1, output_buffer.buffer, output_buffer.len);
                        output_buffer.len = 0;
                    }

                    printed_chars += 2;
            }
        }
    }

    /* Write any remaining content in the buffer to stdout */
    if (output_buffer.len > 0)
    {
        output_buffer.buffer[output_buffer.len] = '\0';
        write(1, output_buffer.buffer, output_buffer.len);
    }

    free(output_buffer.buffer);
    va_end(args);

    return (printed_chars);
}

