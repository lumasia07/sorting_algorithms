#include "sort.h"

/**
 * swap_node_next - Swap a node in list with a node ahead
 * @head: Pointer to head node in list
 * @tail: Pointer to tail node in list
 * @shuttle: Pointer to current node
 */
void swap_node_next(listint_t **head, listint_t **tail, listint_t **shuttle)
{
	listint_t *hold = (*shuttle)->next;

	if ((*shuttle)->prev != NULL)
		(*shuttle)->prev->next = hold;
	else
		*head = hold;
	hold->prev = (*shuttle)->prev;
	(*shuttle)->next = hold->next;

	if (hold->next != NULL)
		hold->next->prev = *shuttle;
	else
		*tail = *shuttle;
	(*shuttle)->prev = hold;
	hold->next = *shuttle;
	*shuttle = hold;
}

/**
 * swap_node_prev - Swap a node in list with a node behind
 * @head: Pointer to head node in list
 * @tail: Pointer to tail node in list
 * @shuttle: Pointer to current node
 */
void swap_node_prev(listint_t **head, listint_t **tail, listint_t **shuttle)
{
	listint_t *hold = (*shuttle)->prev;

	if ((*shuttle)->prev != NULL)
		(*shuttle)->next->prev = hold;
	else
		*tail = hold;
	hold->next = (*shuttle)->next;
	(*shuttle)->prev = hold->prev;

	if (hold->prev != NULL)
		hold->prev->next = *shuttle;
	else
		*head = *shuttle;
	(*shuttle)->next = hold;
	hold->prev = *shuttle;
	*shuttle = hold;
}

/**
 * cocktail_sort_list - Sorts a list in ascending order
 * @list: Double pointer to doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *last, *shuttle;

	bool sorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (last = *list; last->next != NULL;)
		last = last->next;

	while (sorted == false)
	{
		sorted = true;
		for (shuttle = *list; shuttle != last; shuttle = shuttle->next)
		{
			if (shuttle->n > shuttle->next->n)
			{
				swap_node_next(list, &last, &shuttle);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
		for (shuttle = shuttle->prev; shuttle != *list; shuttle = shuttle->prev)
		{
			if (shuttle->n < shuttle->prev->n)
			{
				swap_node_prev(list, &last, &shuttle);
				print_list((const listint_t *)*list);
				sorted = false;
			}
		}
	}
}
