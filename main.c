#include <limits.h>
#include <stdio.h>
<<<<<<< HEAD
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
=======
#include <stdint.h>
#include "main.h"

>>>>>>> cb558f8d46a4e59bb78f14c74a54933434c146d7
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
<<<<<<< HEAD
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
=======

    /* Remove the unused variable addr */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;

    /* Cast uintptr_t to void* */
    (void)(uintptr_t)0x7ffe6375;

>>>>>>> cb558f8d46a4e59bb78f14c74a54933434c146d7
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
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
=======
    
>>>>>>> cb558f8d46a4e59bb78f14c74a54933434c146d7
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
<<<<<<< HEAD
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
=======

    return (0);
}

>>>>>>> cb558f8d46a4e59bb78f14c74a54933434c146d7
