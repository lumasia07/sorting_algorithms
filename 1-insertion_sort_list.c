#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: Double pointer to doubly linked list
 * Return; Always 0 on success
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp_2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = (*list)->next;

	while (tmp != NULL)
	{
		tmp_2 = tmp->prev;

		while (tmp_2 != NULL && tmp_2->n > tmp->n)
		{
			if (tmp_2->prev != NULL)
			{
				tmp_2->prev->next = tmp;
			}
			else
			{
				*list = tmp;
			}
			tmp->prev = tmp_2->prev;
			tmp_2->prev = tmp;
			tmp_2->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = tmp_2;

			tmp->next = tmp_2;
			tmp_2 = tmp->prev;
			print_list(*list);
		}
		tmp = tmp->next;
	}
}
