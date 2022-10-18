#include <unistd.h>

/**
 * _putchar - prints single character
 * @c: character to print
 * Return: always 0
 */

int _putchar(char c)
{
	write(1, c, sizeof(char));
	return (1);
}
