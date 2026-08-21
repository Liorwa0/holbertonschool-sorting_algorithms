#include "deck.h"

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: Difference between strings
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * get_card_value - Get numeric value of a card for sorting
 * @card: Pointer to the card
 * Return: Value from 0 to 12
 */
int get_card_value(const card_t *card)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
			   "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(card->value, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * sort_deck - Sorts a deck of cards from Ace to King and Spades to Diamonds
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next_node;
	int swapped;
	card_t *temp_card;

	if (!deck || !*deck || !(*deck)->next)
		return;

	do {
		swapped = 0;
		current = *deck;
		while (current->next)
		{
			next_node = current->next;
			if (current->card->kind > next_node->card->kind ||
			    (current->card->kind == next_node->card->kind &&
			     get_card_value(current->card) > get_card_value(next_node->card)))
			{
				temp_card = (card_t *)current->card;
				(void)temp_card;
				/* Swap cards pointers directly */
				current->card = next_node->card;
				next_node->card = temp_card;
				swapped = 1;
			}
			current = next_node;
		}
	} while (swapped);
}
