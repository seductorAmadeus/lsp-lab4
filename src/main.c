#include <stdio.h>
#include <stdlib.h>

typedef struct llist_t
{
    int value;
    struct llist_t *next;
} llist_t;

llist_t *list_create(int number);

llist_t *list_add_front(int number, llist_t *llist);

void list_add_back(int number, llist_t *llist);

int list_get(int i);

void list_free(llist_t *llist);

int list_lenght(llist_t *llist);

llist_t *list_node_at(llist_t llist, int index);

long list_sum(llist_t *llist);

int main()
{
    int scanValue;
    llist_t *llist = NULL;
    while (scanf("%d", &scanValue) != EOF)
    {
        if (llist == NULL)
        {
            llist = list_create(scanValue);
        } else
        {
            llist = list_add_front(scanValue, llist);
        }
    }
    printf("%ld", list_sum(llist));

    return 0;
}

long list_sum(llist_t *llist)
{
    long sum = 0;

    while (NULL != llist)
    {
        sum += llist->value;
        llist = llist->next;
    }

    return sum;
}

llist_t *list_create(int number)
{
    return list_add_front(number, NULL);
}

llist_t *list_add_front(int number, llist_t *llist)
{
    llist_t *next;
    next = malloc(sizeof(llist_t));
    next->value = number;
    next->next = llist;
    return next;
}