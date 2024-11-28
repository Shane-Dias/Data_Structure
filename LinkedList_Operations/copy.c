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

void copy_LL(node *start)
{
    node *ptr1 = start1;
    node *ptr2 = NULL;
    if (start == NULL)
    {
        return;
    }
    start2 = getnode(ptr1->info);
    ptr2 = start2;
    if (start2 == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    ptr1 = ptr1->next;
    while (ptr1 != NULL)
    {
        ptr2->next = getnode(ptr1->info);
        if (ptr2->next == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
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
            printf("%d(%p)->", ptr->info, ptr);
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
    printf("LinkedList 1: ");
    traverse(start1);
    printf("Copying LinkedList 1 to LinkedList 2...\n");
    copy_LL(start1);
    printf("LinkedList 2: ");
    traverse(start2);
}

/*
OUTPUT ALONG WITH THE ADDRESS OF EACH NODE:
Enter the number of nodes:4 
Enter the info of node 1:10
Enter the info of node 2:20
Enter the info of node 3:30
Enter the info of node 4:40
LinkedList 1: 10(00B62F38)->20(00B62F48)->30(00B62F58)->40(00B62F68)->NULL
Copying LinkedList 1 to LinkedList 2...
LinkedList 2: 10(00B60C60)->20(00B60C70)->30(00B60C80)->40(00B60C90)->NULL
*/