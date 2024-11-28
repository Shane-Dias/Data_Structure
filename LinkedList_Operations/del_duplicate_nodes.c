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

void insert_beg(int val)
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
        newnode->next = start;
        start = newnode;
        printf("Node added at begining successfully\n");
    }
}

void insert_specf(int position, int val)
{
    if (position == 1)
    {
        insert_beg(val);
    }
    else
    {
        node *newnode = getnode(val);
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        node *ptr = start;
        node *preptr = NULL;

        for (int i = 1; i < position && ptr != NULL; i++)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL && position != 1)
        {
            printf("Position does not exist.\n");
            free(newnode);
        }
        else
        {
            newnode->next = ptr;
            preptr->next = newnode;
            printf("Node added at position %d successfully\n", position);
        }
    }
}

void del_duplicates()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *fixed_ptr = start;

    while (fixed_ptr != NULL)
    {
        node *ptr = fixed_ptr;

        while (ptr->next != NULL)
        {
            if (ptr->next->info == fixed_ptr->info)
            {
                node *dup_node = ptr->next;
                ptr->next = dup_node->next;
                free(dup_node);
            }
            else
            {
                ptr = ptr->next;
            }
        }

        fixed_ptr = fixed_ptr->next;
    }

    printf("Duplicate nodes removed\n");
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
    int exit = 1, ch, val, position;
    while (exit)
    {
        printf("Enter your choice:\n");
        printf("1. Add a new node\n");
        printf("2. Delete duplicate nodes\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // add node
            printf("Enter the position:");
            scanf("%d", &position);
            printf("Enter the info of node:");
            scanf("%d", &val);
            insert_specf(position, val);
            break;
        case 2: // delete duplicate
            del_duplicates();
            break;
        case 3: // traversing(display)
            traverse();
            break;
        case 4: // delete end
            printf("Exiting...");
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

/*
OUTPUT:
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
1
Enter the position:1 
Enter the info of node:40
Node added successfully
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
1
Enter the position:1
Enter the info of node:20
Node added at begining successfully
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
1
Enter the position:1
Enter the info of node:30
Node added at begining successfully
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
1
Enter the position:1
Enter the info of node:20
Node added at begining successfully
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
1
Enter the position:1
Enter the info of node:30
Node added at begining successfully
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
3
30->20->30->20->40->NULL
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
2
Duplicate nodes removed
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
3
30->20->40->NULL
Enter your choice:
1. Add a new node
2. Delete duplicate nodes
3. Traverse
4. Exit
4
Exiting...
*/