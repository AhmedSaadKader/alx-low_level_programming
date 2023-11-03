#include "main.h"
#include <stdlib.h>

/**
 * mul - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: result
 */

unsigned int mul(unsigned int num1, unsigned int num2)
{
	unsigned int result;

	result = num1 * num2;
	return (result);
}

/**
 * printError - print error using putchar
 */

void printError()
{
	char *errorMessage;
	int i;

	errorMessage = "Error\n";
	for(i = 0; errorMessage[i] != '\0'; i++)
	  _putchar(errorMessage[i]);
}

/**
 * main - Entry point
 *
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	int a, b;
	char x;
	
	if (argc != 3)
	{
		printError();
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	x = (char)(mul(a, b));
	_putchar(x);
	_putchar('\n');
	
	return (0);
}
