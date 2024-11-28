/* Name : Shane Dias  Roll no:10179 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

int isEmpty()
{
    return top == NULL;
}

int isFull()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}

void push(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Pushed %d to the stack\n", value);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Elements of the stack are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if stack is empty\n");
        printf("6. Check if stack is full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element: %d\n", pop());
            break;
        case 3:
            printf("Topmost element: %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Stack is %s\n", isEmpty() ? "empty" : "not empty");
            break;
        case 6:
            printf("Stack is %s\n", isFull() ? "full" : "not full");
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}

/*
OUTPUT:
Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 1
Enter value to push: 10
Pushed 10 to the stack

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 2
Popped element: 10

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 1
Enter value to push: 10
Pushed 10 to the stack

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 1
Enter value to push: 20
Pushed 20 to the stack

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 1
Enter value to push: 30
Pushed 30 to the stack

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 3
Topmost element: 30

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 5
Stack is not empty

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 6
Stack is not full

Menu:
1. Push
2. Pop
3. Peek
4. Display
5. Check if stack is empty
6. Check if stack is full
7. Exit
Enter your choice: 7
Exiting...
*/