#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

int isEmpty()
{
    return front == NULL;
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

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL || rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued %d to the queue\n", value);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return -1;
    }
    struct node *temp = front;
    int dequeued = temp->data;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return dequeued;
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue elements: ");
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
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
                printf("Dequeued element: %d\n", value);
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Queue is %s\n", isEmpty() ? "empty" : "not empty");
            break;
        case 5:
            printf("Queue is %s\n", isFull() ? "full" : "not full");
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


/*
OUTPUT:
Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 1
Enter value to enqueue: 10
Enqueued 10 to the queue

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 1
Enter value to enqueue: 20
Enqueued 20 to the queue

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 1
Enter value to enqueue: 30
Enqueued 30 to the queue

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 3
Queue elements: 10 20 30 

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 2
Dequeued element: 10

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 2
Dequeued element: 20

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 2
Dequeued element: 30

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 4
Queue is empty

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 5
Queue is not full

Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Check if Queue is Empty
5. Check if Queue is Full
6. Exit
Enter your choice: 6
Exiting...


=== Code Execution Successful ===
*/