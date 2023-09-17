#include <limits.h>
#include <stdio.h>
#include "main.h"
<<<<<<< HEAD
=======

/**
 * main - Entry point
 *
 * Return: Always 0
 */

>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
#include <stdint.h>

<<<<<<< HEAD
=======

>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
<<<<<<< HEAD
    char *addr_str;
=======
    void *addr;
>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
<<<<<<< HEAD
=======
    addr = (void *)0x7ffe637541f0;

>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5

    addr_str = "0x7ffe637541f0";

<<<<<<< HEAD
=======
    /* Cast uintptr_t to void* */
    (void)(uintptr_t)0x7ffe6375;
>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
<<<<<<< HEAD
    _printf("Address:[%s]\n", addr_str);
    printf("Address:[%s]\n", addr_str);
=======
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
<<<<<<< HEAD
=======

>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
<<<<<<< HEAD

=======


    return (0);
}
>>>>>>> 0cbc678c2b0ec828dd3c015264fa9ec9b4be6cc5
