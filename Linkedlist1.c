#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr!=NULL)   
    {
        printf("Element:%d Address:%p\n",ptr->info,ptr);
        ptr=ptr->next;
    }
    
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->info = 34;
    head->next = second;

    second->info = 67;
    second->next = third;

    third->info = 122;
    third->next = NULL;
    traversal(head);

    struct node *temp;
    while (head != NULL)
    {
        temp = head;  // Store the current node in temp
        head = head->next;  // Move to the next node
        free(temp);  // Free the memory of the current node
    }
    return 0;
}