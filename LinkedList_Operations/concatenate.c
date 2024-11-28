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

void create_LL(int count, node **start)
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
        else if (*start == NULL)
        {
            *start = newnode;
        }
        else
        {
            node *ptr = *start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
}

node *concatenate(node *start1, node *start2)
{
    if (start1 == NULL)
    {
        return start2;
    }
    if (start2 == NULL)
    {
        return start1;
    }
    node *ptr =start1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = start2;
    return start1;
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
    printf("Enter the number of nodes of first Linkedlist:");
    scanf("%d", &n);
    create_LL(n , &start1);
    printf("Enter the number of nodes of second Linkedlist:");
    scanf("%d", &n);
    create_LL(n , &start2);
    printf("LinkedList 1: ");
    traverse(start1);
    printf("LinkedList 2: ");
    traverse(start2);
    printf("Concatenated LinkedList: ");
    node *concat = concatenate(start1 , start2);
    traverse(concat);
}

/*
OUTPUT:
Enter the number of nodes of first Linkedlist:3
Enter the info of node 1:10
Enter the info of node 2:20
Enter the info of node 3:30
Enter the number of nodes of second Linkedlist:2
Enter the info of node 1:40
Enter the info of node 2:50
LinkedList 1: 10->20->30->NULL
LinkedList 2: 40->50->NULL
Concatenated LinkedList: 10->20->30->40->50->NULL
*/