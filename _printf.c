#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - printf collaborative project
 *
 * @format: format specifiers
 *
 * @...: elipsis for variadic variables
 *
 * Return: length os characters printed
 */

int _printf(const char *format, ...)
{
	int strlen = 0, i = 0, u;
	char percent, ch;
	char *string;

	va_list list;

	va_start(list, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					{
						ch = va_arg(list, int);
						write(1, &ch, sizeof(ch));
						i++, strlen += sizeof(ch);
						break;
					}
				case 's':
					{
						string = va_arg(list, char *);
						for (u = 0; string[u] != '\0'; u++)
							;
						write(1, string, u);
						i++, strlen += u;
						break;
					}
				case '%':
					{
						percent = '%';
						write(1, &percent, sizeof(percent));
						i++, strlen += sizeof(percent);
						break;
					}
			}
		}
		else
		{
			write(1, format + i, sizeof(char));
			strlen++;
		}
		i++;
	}
	va_end(list);
	return (strlen);
}
