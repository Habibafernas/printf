#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int _strlen(char *s);

#endif
