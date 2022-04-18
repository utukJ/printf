#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - functions as printf
 * @format: format string
 * @...: variable arguments to fill placeholders
 *
 * Return: (int) number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, byte_count, j;
	va_list ap;
	const char *tmpstr;
	
	byte_count = 0;
	
	va_start(ap, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			byte_count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				_putchar(va_arg(ap, int));
				byte_count++;
			}
			else if (format[i] == 's')
			{
				tmpstr = va_arg(ap, char *);
				if (tmpstr == NULL)
					tmpstr = "(null)";

				for (j = 0; tmpstr[j] != 0; j++)
				{
					_putchar(tmpstr[j]);
					byte_count++;
				}
			}
			else if (format[i] == '%')
			{
			 	_putchar(format[i]);
				byte_count++;
			}

			else
			{
				_putchar(format[i]);
				byte_count++;
			}
				
		}
	}

	va_end(ap);

	return (byte_count);
}
