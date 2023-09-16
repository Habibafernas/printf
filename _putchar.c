#include "main.h"
 /**
  * _putchar - copies c to stdout
  * @c : character to print
  * Return : rerurns 1
  * On error , returns -1
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
