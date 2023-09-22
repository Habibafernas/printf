#include "main.h"
/**
 *buffer - Save a character in a buffer
 *@c : Character
 *
 * Return: 1
 **/
int buffer(char c)
{
	static char buffering[1024];
	static int p;

	if (c == -1 || p == 1024)
	{
		write(1, buffering, p);
		p = 0;
	}
	if (c != -1)
	{
		buffering[p++] = c;
	}
	return (1);
}
