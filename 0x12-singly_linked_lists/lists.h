#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>
int _putchar(char c);

/**
 * struct list_t - a structure of a linked list
 * @str: the data held by every node
 * @len: length of string
 * @next: pointer to the next node in the list
*/
typedef struct list_t
{
char *str;
int len;
struct list_t *next;
} list_t;

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void print_first(void)__attribute__((constructor));

#endif /* _LIST_H */
