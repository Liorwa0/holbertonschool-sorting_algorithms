#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @left: The first node to swap
 * @right: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
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
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
