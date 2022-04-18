#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - functions as printf
 * @format: format string
 *
 * Return: (int) number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, byte_count;
	va_list ap;
	
	byte_count = 0;
	
	va_start(ap, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
			byte_count += _putchar(format[i]);
		
		else
		{
			do {
				i++;
			} while (format[i] == ' ');

			if (format[i] == 'c')
				byte_count += _putchar(va_arg(ap, int));

			else if (format[i] == 's')
				byte_count += print_string(va_arg(ap, char *));
				
			else if (format[i] == '%')
				byte_count += _putchar('%');

			else if (format[i] == 0)
				return (-1);

			else
			{
				_putchar('%');
			 	_putchar(format[i]);
				byte_count += 2;
			}
		}
	}

	va_end(ap);

	return (byte_count);
}
