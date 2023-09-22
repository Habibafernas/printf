#include "main.h"
/**
 * get_precision - gets  precision form the format string
 * @p : the format string
 * @params : the parameters struct
 * @ap : the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int t = 0;

	if (*p != '.')
	{
		return (p);
	}
	p++;
	if (*p == '*')
	{
		t = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		{
			t = t * 10 + (*p++ - '0');
		}
	}
	params->precision = t;
	return (p);
}
