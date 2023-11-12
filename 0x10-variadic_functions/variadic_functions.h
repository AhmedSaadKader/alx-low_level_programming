#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

int sum_them_all(const unsigned int n, ...);
int _putchar(char c);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct format_options - list of format options available
 * @abb: abbreviation of type
 * @type: type corresponding to abbreviation
 */

typedef struct format_options
{
char *abb;
char (*type_check)(va_list args);
} f_o;

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_str(va_list args);

#endif /* VARIADIC_FUNCTIONS */