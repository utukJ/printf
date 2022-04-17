#include <stdarg.h>
#include <unistd.h>

void _putchar(char);

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
			write(1, format + i, 1);
			byte_count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				write(1, format + i, 1);
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
			else 
			{
				write(1, format + i, 1);
			}
		}
	}

	va_end(ap);

	return (byte_count);
}
