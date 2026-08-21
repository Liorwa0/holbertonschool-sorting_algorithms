#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @n1: First node to swap
 * @n2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list = n2;
	if (n2->next)
		n2->next->prev = n1;
	n2->prev = n1->prev;
	n1->next = n2->next;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		curr = curr->prev;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
		curr = curr->next;
	}
}
