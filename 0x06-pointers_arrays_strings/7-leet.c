#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to be encoded
 *
 * Return: encoded string
 */

char *leet(char *str)
{
	int i, l;
	char c[] = "aAeEoOtTlL";
	char n[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (l = 0; l < 10; l++)
		{
			if (str[i] == c[l])
				str[i] = n[i];
		}
	}
	return (str);
}
