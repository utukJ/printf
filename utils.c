#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _putchar - prints a char to stdout
 * @c: char to be printed
 * 
 * Return: 1 for success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));   
}

/**
 * print_string - prints a string to stdout
 * @str: yields next argument(string) to be printed
 * 
 * Return: int count of number of bytes printed
 */
int print_string(const char *str)
{
    int i, count;

    count = 0;

    if (str == NULL)
        str = "(null)";
    
    for (i = 0; str[i]; i++)
    {
        count += _putchar(str[i]);
    }
    
    return (count);
}