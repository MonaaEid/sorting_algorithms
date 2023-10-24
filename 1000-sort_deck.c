#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - compares two cards based on their kind and value
 * @node: first card to be compared
 * Return: negative value if card1 is less than card2, positive value if card1
 * is greater than card2, 0 if they are equal
 */
int compare_cards(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
	"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}
	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}
	return (kind_val);
}

/**
 * sort_deck - sorts a deck of cards in ascending
 * order using the qsort function
 * @deck: pointer to the head of the deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = deck_list_len(*deck);
	if (!deck || !*deck || len < 2)
		return;
	curr = *deck;
	while (curr)
	{
		if (curr->prev && compare_cards(curr) < compare_cards(curr->prev))
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;
			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			curr = *deck;
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: zero or more than Zero
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * deck_list_len - function that returns length of list.
 * @list: head of list
 *
 * Return: length of list
 */
size_t deck_list_len(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
