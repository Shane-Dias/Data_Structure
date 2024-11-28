#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL; 
    }
    newnode->info = data; // Set the info part of the node
    newnode->next = NULL; // Initialize the next pointer to NULL
    return newnode;       // Return the pointer to the new node
}

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->info);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = getnode(34);
    struct node *second = getnode(67);
    struct node *third = getnode(122);

    // Link the nodes
    head->next = second;
    second->next = third;

    traversal(head);

    // Free the memory allocated for each node
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
