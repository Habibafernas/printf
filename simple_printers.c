#include "main.h"

/**
 * print_from_to - prints  range of char addresses
 * @start: the starting address
 * @stop: the stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int m = 0;

	while (start <= stop)
	{
		if (start != except)
			m += _putchar(*start);
		start++;
	}
	return (m);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: the number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int l, m = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; l--, str--)
			m += _putchar(*str);
	}
	return (m);
}

/**
 * print_rot13 - prints the string in rot13
 * @ap: string
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, j;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	j = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			j = a[i] - 65;
			count += _putchar(arr[j]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
