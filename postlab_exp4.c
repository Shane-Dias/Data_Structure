//Write a Program to implement Queue data structure using two stacks 
#include <stdio.h>

#define MAX 5

typedef struct Stack
{
    int top;
    int a[MAX];
} stack;

void push(stack *p, int val)
{
    if (p->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        p->top++;
        p->a[p->top] = val;
    }
}

int pop(stack *p)
{
    if (p->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int val = p->a[p->top];
        p->top--;
        return val;
    }
}

int isempty(stack *p)
{
    return (p->top == -1);
}

typedef struct Queue
{
    stack s1, s2;
} queue;

void enqueue(queue *q, int val)
{
    push(&q->s1, val);
    printf("Enqueued element: %d\n", val);
}

int dequeue(queue *q)
{
    int val;

    if (isempty(&q->s1) && isempty(&q->s2))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    if (isempty(&q->s2))
    {
        while (!isempty(&q->s1))
        {
            val = pop(&q->s1);
            push(&q->s2, val);
        }
    }

    val = pop(&q->s2);
    printf("Dequeued element: %d\n", val);
    return val;
}

int main()
{
    queue q;
    q.s1.top = -1;
    q.s2.top = -1;

    int ch, val;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            enqueue(&q, val);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

/*
OUTPUT:
1. Enqueue
2. Dequeue
3. Exit
Enter your choice: 1
Enter the value to enqueue: 10
Enqueued element: 10

1. Enqueue
2. Dequeue
3. Exit
Enter your choice: 2
Dequeued element: 10

1. Enqueue
2. Dequeue
3. Exit
Enter your choice: 2
Queue Underflow

1. Enqueue
2. Dequeue
3. Exit
Enter your choice: 3
Exiting...
 */
