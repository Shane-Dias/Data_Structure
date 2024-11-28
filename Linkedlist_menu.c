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

delete_beg()
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
        temp = start;
        start = start->next;
        free(temp);
    }
    return 0;
}

/* OUTPUT:
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
List is empty
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
3
Enter the position:1
Enter the info of node:20
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
20->10->NULL
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
20->NULL
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
Enter the info of the node:30
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
Enter the info of the node:10
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
10->20->30->NULL
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
20->30->NULL
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