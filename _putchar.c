#include "main.h"

 /**
  * _putchar - writes the character c to stdout
  * @c : Character to print
  * Return : Returns 1
  * On error , returns -1
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
