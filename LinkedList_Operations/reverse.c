#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} node;

node *start = NULL;

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
        else if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            node *ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
}

void reverse()
{
    node *p = NULL;
    node *q = start;
    node *r;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    start = p;
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
    traverse(start);
    reverse();
    printf("Linkedlist after reverse:");
    traverse(start);
}

/*
OUTPUT:
Enter the number of nodes:5
Enter the info of node 1:10
Enter the info of node 2:20
Enter the info of node 3:30
Enter the info of node 4:40
Enter the info of node 5:50
Original Linkedlist: 10->20->30->40->50->NULL
Linkedlist after reverse:50->40->30->20->10->NULL
*/