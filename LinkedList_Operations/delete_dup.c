/* Remove duplicates from a sorted linked list */

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
    node *newnode = (node *)malloc(sizeof(node));
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

void insert_end(int val)
{
    node *newnode = getnode(val);
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else if (start == NULL)
    {
        start = newnode;
        printf("Node added successfully\n");
    }
    else
    {
        node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        printf("Node added at end successfully\n");
    }
}

void del_duplicates()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *current = start;
    while (current != NULL && current->next != NULL)
    {
        if (current->info == current->next->info)
        {
            node *duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }
    printf("Duplicate nodes deleted successfully\n");
}

void traverse()
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
            printf("%d->", ptr->info);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int exit = 1, ch, val;
    while (exit)
    {
        printf("Enter your choice:\n");
        printf("1. Add a new node\n");
        printf("2. Delete duplicate nodes\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // add node
            printf("Enter the info of node: ");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 2: // delete duplicate
            del_duplicates();
            break;
        case 3: // traversing(display)
            traverse();
            break;
        case 4: // exit
            printf("Exiting...\n");
            exit = 0;
            break;
        default:
            printf("Invalid choice, please try again\n");
            break;
        }
    }

    node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    return 0;
}
