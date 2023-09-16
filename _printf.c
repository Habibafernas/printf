#include <main.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing the characters and specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to be written.
 *
 * Return: Upon success, returns the character written.
 * On error, returns -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _puts - Writes a string to the standard output (stdout).
 * @str: The string to be written.
 *
 * Return: The number of characters written.
 */
int _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
