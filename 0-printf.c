#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - functions as printf
 * @format: format string
 * @...: variable arguments to fill placeholders
 *
 * Return: (int) number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, byte_count, j, c;
	va_list ap;
	const char *tmpstr;
	
	va_start(ap, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			byte_count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
				byte_count++;
			}
			else if (format[i] == 's')
			{
				tmpstr = va_arg(ap, char *);

				for (j = 0; tmpstr[j] != 0; j++)
				{
					write(1, tmpstr + j, 1);
					byte_count++;
				}
			}
			else if (format[i] == '%')
				write(1, format + i, 1);
			else
			{
				va_end(ap);
				return (-1);
			}
				
		}
	}

	va_end(ap);

	return (byte_count);
}
