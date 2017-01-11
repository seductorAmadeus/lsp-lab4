#include <stdio.h>
#include <stdlib.h>

typedef struct llist_t
{
    int value;
    struct llist_t *next;
} llist_t;

long list_sum(llist_t *list);

llist_t *list_add_front(int, llist_t **);

llist_t *list_create(int);

int list_length(llist_t *);

int list_get(int, llist_t *);

void list_add_back(int, llist_t *);

void list_free(llist_t *);

llist_t *list_node_at(llist_t *, int);

int main()
{
    int scanValue, variantNumber = 16, foundValue;
    llist_t *list = NULL;
    while (scanf("%d", &scanValue) != EOF)
    {
        if (NULL == list)
        {
            list = list_create(scanValue);
        }
        else
        {
            list = list_add_front(scanValue, &list);
        }
    }
    printf("sum of elements in the list: %ld\n", list_sum(list));
    foundValue = list_get(variantNumber, list);
    if (NULL != foundValue)
    {
        printf("list_get(%d) = %d\n", variantNumber, foundValue);
    }
    else
    {
        printf("value is missing, because the list is not long enough:\n list_length = %d\n", list_length(list));
    }
    list_free(list);
    return 0;
}

void list_add_back(int number, llist_t *list)
{
    llist_t *newList;
    list = list_node_at(list, list_length(list) - 1);
    newList = malloc(sizeof(llist_t));
    newList->value = number;
    newList->next = NULL;
    list->next = newList;
}

llist_t *list_node_at(llist_t *list, int index)
{
    int i;
    for (i = 0; (i < index) && (list->next != NULL); i++)
    {
        list = list->next;
    }
    if (i == index)
    {
        return list;
    }
    else
    {
        return NULL;
    }
}

int list_get(int index, llist_t *list)
{
    if (index > list_length(list))
    {
        return NULL;
    }
    else if ((list = list_node_at(list, index)) != NULL)
    {
        return list->value;
    }
    else
    {
        return NULL;
    }
}

long list_sum(llist_t *list)
{
    long sum = 0;
    while (NULL != list)
    {
        sum += list->value;
        list = list->next;
    }
    return sum;
}

llist_t *list_add_front(int number, llist_t **head)
{
    llist_t *tmp = malloc(sizeof(llist_t));
    tmp->value = number;
    tmp->next = *head;
    *head = tmp;
    return *head;
}

llist_t *list_create(int number)
{
    llist_t *head = (llist_t *) malloc(sizeof(llist_t));
    head->value = number;
    head->next = NULL;
    return head;
}

int list_length(llist_t *list)
{
    int list_length = 0;
    while (NULL != list)
    {
        list_length++;
        list = list->next;
    }
    return list_length;
}

void list_free(llist_t *list)
{
    llist_t *next;
    if (NULL == list) return;
    for (; list->next; list = next)
    {
        next = list->next;
        free(list);
    }
    free(list);
}