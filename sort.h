#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void swap_me(int *x, int *y);
int lomuto_algo(int *array, size_t size, int left, int right);
void lomuto_recursive_sort(int *array, size_t size, int left, int right);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

void swap_node_next(listint_t **head, listint_t **tail, listint_t **shuttle);
void swap_node_prev(listint_t **head, listint_t **tail, listint_t **shuttle);
void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);
int get_max_val(int *array, int size);

void merge_me(int *array, int *left, int size_left, int *right, int size_right);
void merge_sort(int *array, size_t size);



#endif
