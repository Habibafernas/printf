#include "main.h"
#include <stdarg.h>
/**
 * _printf - Produces output according to a format.
 * @format: Format string containing the characters and specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int cprint = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	cprint = process_format(format, args);
	va_end(args);

	return (cprint);
}

/**
 * process_format - Processes format specifiers in the format string.
 * @format: Format string containing the characters and specifiers.
 * @args: va_list containing the arguments for format specifiers.
 *
 * Return: The number of characters printed.
 */
int process_format(const char *format, va_list args)
{
	int cprint = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			int chars_printed = process_specifier(*format, args);
			if (chars_printed == -1)
				return (-1);

			cprint += chars_printed;
			format++;
		}
		else
		{
			_putchar(*format);
			cprint++;
			format++;
		}
	}

	return (cprint);
}

/**
 * process_specifier - Processes a format specifier and prints its value.
 * @specifier: The format specifier character.
 * @args: va_list containing the arguments for format specifiers.
 *
 * Return: The number of characters printed for this specifier.
 */
int process_specifier(char specifier, va_list args)
{
	int cprint = 0;

	switch (specifier)
	{
		case 'c':
			cprint += print_char(va_arg(args, int));
			break;
		case 's':
			cprint += print_string(va_arg(args, char *));
			break;
		case 'i':
		case 'd':
			cprint += print_int(va_arg(args, int));
			break;
		/* Add more format specifiers as needed */
		default:
			_putchar('%');
			_putchar(specifier);
			cprint += 2;
			break;
	}

	return (cprint);
}
