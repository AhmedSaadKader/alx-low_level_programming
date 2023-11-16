#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>
int _putchar(char c);

/**
 * struct list_t - a structure of a linked list
 * @data: the data held by every node
 * @len: length of string
 * @next: pointer to the next node in the list
*/
typedef struct list_t
{
char* str;
int len;
struct list_t *next;
} list_t;

size_t print_list(const list_t *h);

#endif /* _LIST_H */