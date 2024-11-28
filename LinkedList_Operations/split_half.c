#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

node *start1 = NULL;
node *start2 = NULL;

node *getnode(int val)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        return NULL;
    }
    else
    {
        newnode->info = val;
        newnode->next = NULL;
        return newnode;
    }
}

void create_LL(int count)
{
    for (int i = 0; i < count; i++)
    {
        int val;
        printf("Enter the info of node %d:", i + 1);
        scanf("%d", &val);
        node *newnode = getnode(val);
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
        }
        else if (start1 == NULL)
        {
            start1 = newnode;
        }
        else
        {
            node *ptr = start1;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
}

void split_half(int n)
{
    if (start1 == NULL)
    {
        return;
    }
    node *temp, *ptr1, *ptr2;
    ptr1 = start1;
    int i = 0;
    while (i != (n / 2) - 1)
    {
        ptr1 = ptr1->next;
        i++;
    }
    start2 = ptr1->next;
    ptr1->next = NULL;
}

void traverse(node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *ptr = start;
        while (ptr != NULL)
        {
            printf("%d->", ptr->info, ptr);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    create_LL(n);
    printf("Original Linkedlist: ");
    traverse(start1);
    split_half(n);
    printf("Linkedlist after split:\n");
    printf("First half: ");
    traverse(start1);
    printf("Second half: ");
    traverse(start2);
}

/*
OUTPUT:

CASE 1: ODD NUMBER OF NODES
  Enter the number of nodes:5
  Enter the info of node 1:10
  Enter the info of node 2:20
  Enter the info of node 3:30
  Enter the info of node 4:40
  Enter the info of node 5:50
  Original Linkedlist: 10->20->30->40->50->NULL
  Linkedlist after split:
  First half: 10->20->NULL
  Second half: 30->40->50->NULL

CASE 2: Even NUMBER OF NODES
  Enter the number of nodes:4
  Enter the info of node 1:10
  Enter the info of node 2:20
  Enter the info of node 3:30
  Enter the info of node 4:40
  Original Linkedlist: 10->20->30->40->NULL
  Linkedlist after split:
  First half: 10->20->NULL
  Second half: 30->40->NULL
*/