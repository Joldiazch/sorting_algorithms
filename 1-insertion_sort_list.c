#include "sort.h"
/**
 * swap - Function that swaps nodes
 * @temp1: Node 1
 * @temp2: Node 2
 * @head: head of the list
 * Return: No return
 */
void swap(listint_t *temp1, listint_t *temp2, listint_t **head)
{
	if (temp2->next == NULL && temp1->prev != NULL)
	{
		temp1->prev->next = temp2;
		temp2->prev = temp1->prev;
		temp1->next = temp2->next;
		temp1->prev = temp2;
		temp2->next = temp1;
	}
	else if (temp1->prev != NULL)
	{
		temp1->prev->next = temp2;
		temp2->next->prev = temp1;
		temp2->prev = temp1->prev;
		temp1->next = temp2->next;
		temp1->prev = temp2;
		temp2->next = temp1;
		*head = *head;
	}
	else if (temp2->next == NULL && temp1->prev == NULL)
	{
		temp2->prev = NULL;
		temp2->next = temp1;
		temp1->prev = temp2;
		temp1->next = NULL;
		*head = temp2;
	}
	else
	{
		temp2->prev = NULL;
		temp2->next->prev = temp1;
		temp1->prev = temp2;
		temp1->next = temp2->next;
		temp2->next = temp1;
		*head = temp2;
	}
}
/**
 * insertion_sort_list - Sorting algorithim by insertion
 * @list: List to be sorted
 * Return: No return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1 = *list;
	listint_t *temp2 = (*list)->next;
	listint_t *temp3 = NULL;
	int c = 0;

	if (list == NULL || *list == NULL)
		return;

	while (temp2 != NULL)
	{
		while (temp2->n < temp1->n)
		{
			swap(temp1, temp2, list);
			if (c == 0)
			{
				temp3 = temp1;
				c = 1;
			}
			temp1 = temp2->prev;
			print_list(*list);
			if (temp2->prev == NULL)
			{
				temp2 = temp3;
				temp1 = temp2->prev;
				c = 0;
				break;
			}
		}
		temp1 = temp2;
		temp2 = temp1->next;
		c = 0;
	}
}
