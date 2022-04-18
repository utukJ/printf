#include <unistd.h>

/**
 * _putchar - prints a char to stdout
 * @c: char to be printed
 * 
 * Return: nothing
 */
void _putchar(char c)
{
    write(1, &c, 1);   
}