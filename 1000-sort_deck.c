#include "deck.h"

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Difference between the first unmatched characters
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_card_value - Returns the numerical value of a card
 * @card: Pointer to the card
 *
 * Return: The integer value of the card (1 to 13)
 */
int get_card_value(const card_t *card)
{
	if (_strcmp(card->value, "Ace") == 0)
		return (1);
	if (_strcmp(card->value, "10") == 0)
		return (10);
	if (_strcmp(card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->value, "Queen") == 0)
		return (12);
	if (_strcmp(card->value, "King") == 0)
		return (13);
	return (card->value[0] - '0');
}

/**
 * card_cmp - Comparison function for qsort
 * @a: Pointer to the first node pointer
 * @b: Pointer to the second node pointer
 *
 * Return: Positive if a > b, negative if a < b, 0 if equal
 */
int card_cmp(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	int val_a, val_b;

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	val_a = get_card_value(node_a->card);
	val_b = get_card_value(node_b->card);

	return (val_a - val_b);
}

/**
 * sort_deck - Sorts a deck of 52 cards
 * @deck: Double pointer to the head of the doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *arr[52];
	deck_node_t *curr;
	int i;

	if (!deck || !*deck)
		return;

	curr = *deck;
	for (i = 0; i < 52 && curr; i++)
	{
		arr[i] = curr;
		curr = curr->next;
	}

	qsort(arr, 52, sizeof(deck_node_t *), card_cmp);

	for (i = 0; i < 52; i++)
	{
		arr[i]->prev = (i == 0) ? NULL : arr[i - 1];
		arr[i]->next = (i == 51) ? NULL : arr[i + 1];
	}

	*deck = arr[0];
}
