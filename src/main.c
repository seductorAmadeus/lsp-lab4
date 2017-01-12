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

void merge(llist_t *, llist_t *, llist_t **);

void mergeSort(llist_t **);

void split(llist_t *, llist_t **, llist_t **);

void print_list(llist_t **);

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

    /* task: merge sort; */
    mergeSort(&list);
    printf("list was sorted!\n");
    print_list(&list);

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

void mergeSort(llist_t **head)
{
    llist_t *low = NULL;
    llist_t *high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL))
    {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}

void print_list(llist_t **head)
{
    if (((*head)->next == NULL) || (*head == NULL))
    {
        return;
    }
    while ((*head) != NULL)
    {
        printf("%d\n", (*head)->value);
        *head = (*head)->next;
    }
    printf("\n");
}

void merge(llist_t *a, llist_t *b, llist_t **c)
{
    llist_t tmp;
    *c = NULL;
    if (a == NULL)
    {
        *c = b;
        return;
    }
    if (b == NULL)
    {
        *c = a;
        return;
    }
    if (a->value < b->value)
    {
        *c = a;
        a = a->next;
    }
    else
    {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b)
    {
        if (a->value < b->value)
        {
            (*c)->next = a;
            a = a->next;
        }
        else
        {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a)
    {
        while (a)
        {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b)
    {
        while (b)
        {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

void split(llist_t *src, llist_t **low, llist_t **high)
{
    llist_t *fast = NULL;
    llist_t *slow = NULL;
    if (src == NULL || src->next == NULL)
    {
        (*low) = src;
        (*high) = NULL;
        return;
    }
    slow = src;
    fast = src->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
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