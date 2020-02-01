#include "sort.h"

void swap(listint_t *temp1, listint_t *temp2, listint_t **head)
{
    if (temp1->prev != NULL)
    {
        temp1->prev->next = temp2;
        temp2->prev =temp1->prev;
        temp1->next = temp2->next;
        temp1->prev = temp2;
        temp2->next = temp1;
        *head = *head;
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

void insertion_sort_list(listint_t **list)
{
    listint_t *temp1 = *list;
    listint_t *temp2 = (*list)->next;
    listint_t *temp3 = NULL;
    int c = 0;

    while(temp2 != NULL)
    {
        while(temp2->n < temp1->n)
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
