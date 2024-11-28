#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *getnode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL; 
    }
    newnode->info = data; // Set the info part of the node
    newnode->next = NULL; // Initialize the next pointer to NULL
    return newnode;       // Return the pointer to the new node
}

void traversal(struct node *ptr) {
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->info);
        ptr = ptr->next;
    }
}

struct node* insertBegin(struct node *start, int data) {
    struct node *newnode = getnode(data);
    if (newnode == NULL) {
        return start;
    }
    newnode->next = start;
    return newnode;
}

struct node* insertEnd(struct node *start, int data) {
    struct node *newnode = getnode(data);
    if (newnode == NULL) {
        return start;
    }

    if (start == NULL) {
        return newnode;
    }

    struct node *ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    return start;
}

struct node* insertBeforeNode(struct node *start, int target, int data) {
    struct node *newnode = getnode(data);
    if (newnode == NULL) {
        return start;
    }

    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    if (start->info == target) {
        newnode->next = start;
        return newnode;
    }

    struct node *temp = start;
    while (temp->next != NULL && temp->next->info != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Target node not found.\n");
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return start;
}

struct node* insertAfterNode(struct node *start, int target, int data) {
    struct node *newnode = getnode(data);
    if (newnode == NULL) {
        return start;
    }

    struct node *temp = start;
    while (temp != NULL && temp->info != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target node not found.\n");
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return start;
}

int main() {
    struct node *start = NULL;
    int choice, subChoice, data, target;

    do {
        printf("\nMenu:\n");
        printf("1. Create New Node\n");
        printf("2. Display Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nSub-Menu:\n");
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert Before Node\n");
                printf("4. Insert After Node\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                printf("Enter data to insert: ");
                scanf("%d", &data);

                switch (subChoice) {
                    case 1:
                        start = insertBegin(start, data);
                        break;
                    case 2:
                        start = insertEnd(start, data);
                        break;
                    case 3:
                        printf("Enter the target node's info to insert before: ");
                        scanf("%d", &target);
                        start = insertBeforeNode(start, target, data);
                        break;
                    case 4:
                        printf("Enter the target node's info to insert after: ");
                        scanf("%d", &target);
                        start = insertAfterNode(start, target, data);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 2:
                printf("\nLinked List:\n");
                traversal(start);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Free the memory allocated for each node
    struct node *temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }

    return 0;
}
