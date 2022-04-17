#include <stdarg.h>
#include <stdio.h>

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
	  
	va_start(ap, format);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			byte_count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				putchar(va_arg(ap, int));
				byte_count++;
			}
			else if (format[i] == 's')
			{
				tmpstr = va_arg(ap, char *);

				for (j = 0; tmpstr[j] != 0; j++)
				{
					putchar(tmpstr[j]);
					byte_count++;
				}
			}
			else 
			{
				putchar(format[i]);
			}
		}
	}

	va_end(ap);

	return (byte_count);
}
