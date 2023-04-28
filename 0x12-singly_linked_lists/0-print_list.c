#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the list_t list that should be printed
 *
 * Return: the number of printed nodes
 */
size_t print_list(const list_t *h)
{
	size_t numnodes = 0;
	for (; h != NULL; h = h->next, numnodes++) {
        if (!h->str) {
            printf("[0] (nil)\n");
        } else {
            printf("[%u] %s\n", h->len, h->str);
        }
    }
    return numnodes;
}
