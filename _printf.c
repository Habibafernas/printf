#include "main.h"
/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0;
	char *u, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (u = (char *)format; *u; u++)
	{
		init_params(&params, ap);
		if (*u != '%')
		{
			sum += _putchar(*u);
			continue;
		}
		start = u;
		u++;
		while (get_flag(u, &params))
		{
			u++;
		}
		u = get_width(u, &params, ap);
		u = get_precision(u, &params, ap);
		if (get_modifier(u, &params))
			u++;
		if (!get_specifier(u))
			sum += print_from_to(start, u,
				params.l_modifier || params.h_modifier ? u - 1 : 0);
		else
			sum += get_print_func(u, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
