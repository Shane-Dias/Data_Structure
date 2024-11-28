#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node* getnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void middle_element(node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *ptr1 = start;
    node *ptr2 = start;
    while (ptr2 != NULL && ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    printf("The middle element is: %d\n", ptr1->data);
}

int main()
{
    node *start = getnode(1);
    start->next = getnode(2);
    start->next->next = getnode(3);
    start->next->next->next = getnode(4);
    start->next->next->next->next = getnode(5);
    start->next->next->next->next->next = getnode(6);

    middle_element(start);
    return 0;
}

/*
  OUTPUT: The middle element is: 4
*/