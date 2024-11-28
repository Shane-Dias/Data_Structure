#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

node *getnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        return NULL;
    }
    newnode->info = val;
    newnode->next = NULL;
    return newnode;
}

void is_circularLL(node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    node *ptr = start;
    while (ptr->next != NULL && ptr->next != start)
    {
        ptr = ptr->next;
    }

    if (ptr->next == start)
    {
        printf("The list is circular.\n");
    }
    else
    {
        printf("The list is not circular.\n");
    }
}

int main()
{
    node *start = getnode(10);
    start->next = getnode(20);
    start->next->next = getnode(30);
    is_circularLL(start);
    return 0;
}
/*
   OUTPUT:The list is not circular.
*/