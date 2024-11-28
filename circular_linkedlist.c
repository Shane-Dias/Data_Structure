#include <stdio.h>
#include <stdlib.h>

typedef struct circular
{
    int info;
    struct circular *next;
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
        newnode->next = newnode;
        printf("Node added successfully\n");
    }
    else
    {
        node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newnode->next = start;
        start = newnode;
        ptr->next = start;
        printf("Node added at begining successfully\n");
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
        newnode->next = start;
        printf("Node added successfully\n");
    }
    else
    {
        node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
        printf("Node added at end successfully\n");
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

        for (int i = 1; i < position && ptr->next != start; i++)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr == start && position != 1)
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

void delete_end()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
        printf("Node deleted successfully\n");
    }

    else
    {
        node *preptr = NULL;
        node *ptr = start;
        while (ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("Node deleted successfully\n");
    }
}

void delete_beg()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
        printf("Node deleted successfully\n");
    }

    else
    {
        node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        node *ptr1 = start;
        start = ptr1->next;
        ptr->next = start;
        free(ptr1);
        printf("Node deleted successfully\n");
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

void traverse()
{
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *ptr = start;
        do
        {
            printf("%d->", ptr->info);
            ptr = ptr->next;
        } while (ptr != start);
        printf("START\n");
    }
}

int main()
{
    int exit = 1, ch, val, position;
    while (exit)
    {
        printf("Enter your choice:\n");
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete end\n");
        printf("5. Delete begin\n");
        printf("6. Delete at specific position\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // insert beg
            printf("Enter the info of the node:");
            scanf("%d", &val);
            insert_beg(val);
            break;
        case 2: // insert end
            printf("Enter the info of the node:");
            scanf("%d", &val);
            insert_end(val);
            break;
        case 3: // at specific position
            printf("Enter the position:");
            scanf("%d", &position);
            printf("Enter the info of node:");
            scanf("%d", &val);
            insert_specf(position, val);
            break;
        case 4: // delete end
            delete_end();
            break;
        case 5: // delete begining
            delete_beg();
            break;
        case 6: // delete at specific position
            printf("Enter the position:");
            scanf("%d", &position);
            delete_specf(position);
            break;
        case 7: // traversing(display)
            traverse();
            break;
        case 8: // exit program
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
        node *temp = start;
        node *ptr = start;
        if (start->next == start)
        {
            free(start);
            break;
        }
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        start = start->next;
        ptr->next = start;
        free(temp);
    }
    return 0;
}

/*
   OUTPUT:
   Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
1
Enter the info of the node:10
Node added successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
2
Enter the info of the node:20
Node added at end successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
1
Enter the info of the node:5
Node added at begining successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
7
5->10->20->START
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
4
Node deleted successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
7
5->10->START
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
3
Enter the position:2
Enter the info of node:100
Node added at position 2 successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
5
Node deleted successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
7
100->10->START
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
6
Enter the position:1
Node deleted successfully
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
7
10->START
Enter your choice:
1. Insert at begin
2. Insert at end
3. Insert at specific position
4. Delete end
5. Delete begin
6. Delete at specific position
7. Traverse
8. Exit
8
Exiting...
*/