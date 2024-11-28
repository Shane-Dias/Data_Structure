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

void delete_beg();
void delete_end();

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

void delete_specf(int position)
{
    if (position == 1)
    {
        delete_beg();
    }
    else
    {
        node *ptr = start;
        node *preptr = NULL;

        for (int i = 1; i < position && ptr != NULL; i++)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("Position does not exist.\n");
        }
        else if (ptr->next == NULL)
        {
            delete_end();
        }
        else
        {
            preptr->next = ptr->next;
            free(ptr);
            printf("Node deleted successfully\n");
        }
    }
}

void delete_end()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("Node deleted successfully\n");
    }

    else
    {
        node *preptr = NULL;
        node *ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        preptr->next = NULL;
        printf("Node deleted successfully\n");
    }
}

void delete_beg()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("Node deleted successfully\n");
    }

    else
    {
        node *ptr = start;
        start = ptr->next;
        free(ptr);
        printf("Node deleted successfully\n");
    }
}

int nodes_count()
{
    if (start == NULL)
    {
        return 0;
    }
    int count = 0;
    node *ptr = start;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
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
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Count number of nodes\n");
        printf("4. Display Linkedlist\n");
        printf("5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // insert end
            printf("Enter the info of the node:");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 2: // delete at specific position
            printf("Enter the position:");
            scanf("%d", &position);
            delete_specf(position);
            break;
        case 3: // count number of nodes
            val = nodes_count();
            printf("The linkedlist has %d nodes\n", val);
            break;
        case 4: // traversing(display)
            traverse();
            break;
        case 5: // exit program
            printf("Exiting...");
            exit = 0;
            break;

        default:
            printf("Invalid choice, please try again");
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
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
3
The linkedlist has 0 nodes
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
1
Enter the info of the node:10
Node added successfully
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
1
Enter the info of the node:20
Node added at end successfully
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
1
Enter the info of the node:30
Node added at end successfully
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
4
10->20->30->NULL
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
3
The linkedlist has 3 nodes
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
2
Enter the position:1
Node deleted successfully
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
2
Enter the position:2
Node deleted successfully
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
4
20->NULL
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
3
The linkedlist has 1 nodes
Enter your choice:
1. Insert a node
2. Delete a node
3. Count number of nodes
4. Display Linkedlist
5. Exit
5
Exiting...
*/