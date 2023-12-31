#include "main.h"

/**
 * print_hex - prints hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int s = 0;
	char *v;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	v = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--v = 'x';
		*--v = '0';
	}
	params->unsign = 1;
	return (s += print_number(v, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int s = 0;
	char *v;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	v = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--v = 'X';
		*--v = '0';
	}
	params->unsign = 1;
	return (s += print_number(v, params));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int k = va_arg(ap, unsigned int);
	char *str = convert(k, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && k)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *v;
	int s = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	v = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--v = '0';
	params->unsign = 1;
	return (s += print_number(v, params));
}
