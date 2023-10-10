#include "_putchar.c"

/**
 *main - Entry point
 *
 *Return: Always 0
 *
 */

int main(void)
{
	char *str = "_putchar\n";

	while (*str != '\0')
	  {
	    _putchar(*str);
	    str++;
	  }
  
	return (0);
}  
