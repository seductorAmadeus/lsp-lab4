#include <stdio.h>
#include <stdlib.h>

typedef struct llist_t
{
    int value;
    struct llist_t *next;
} llist_t;

long list_sum(llist_t *list);

llist_t *list_add_front(int number, llist_t **head);

llist_t *list_create(int number);

int list_length(llist_t *list);

void list_add_back(int number, llist_t *llist);

int list_get(int i);

void list_free(llist_t *llist);

llist_t *list_node_at(llist_t llist, int index);

int main()
{
    int scanValue;
    llist_t *list = NULL;
    while (scanf("%d", &scanValue) != EOF)
    {
        if (NULL == list)
        {
            list = list_create(scanValue);
        } else
        {
            list = list_add_front(scanValue, &list);
        }
    }
    printf("%ld\n", list_sum(list));
    printf("length of list = %d\n", list_length(list));
    return 0;
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