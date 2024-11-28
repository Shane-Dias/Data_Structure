#include <stdio.h>

#define MAX 5

typedef struct priority_queue
{
    int front, rear;
    int priority[MAX]; // Array to store the priorities
    int a[MAX];        // Array to store the elements
} pq;

int isfull(pq *p)
{
    if (p->rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isempty(pq *p)
{
    if (p->front == -1 || p->front > p->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(pq *p, int val, int prio)
{
    if (isfull(p))
    {
        printf("Priority Queue Overflow\n");
    }
    else
    {
        if (isempty(p))
        {
            p->front = 0;
            p->rear = 0;
            p->a[p->rear] = val;
            p->priority[p->rear] = prio;
        }
        else
        {
            int i = p->rear;
            // Find the correct position to insert the new element based on priority
            while (i >= p->front && p->priority[i] < prio)
            {
                p->a[i + 1] = p->a[i];
                p->priority[i + 1] = p->priority[i];
                i--;
            }
            p->a[i + 1] = val;
            p->priority[i + 1] = prio;
            p->rear++;
        }
    }
}

int dequeue(pq *p)
{
    if (isempty(p))
    {
        printf("Priority Queue Underflow\n");
        return -1;
    }
    else
    {
        int removed = p->a[p->front];
        p->front++;
        return removed;
    }
}

void display(pq *p)
{
    if (isempty(p))
    {
        printf("Priority Queue is empty\n");
    }
    else
    {
        printf("Priority Queue contents:\n");
        for (int i = p->front; i <= p->rear; i++)
        {
            printf("Element: %d, Priority: %d\n", p->a[i], p->priority[i]);
        }
    }
}

int getfront(pq *p)
{
    if (isempty(p))
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return p->a[p->front];
}

int getrear(pq *p)
{
    if (isempty(p))
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return p->a[p->rear];
}

int main()
{
    pq pq1;
    pq1.front = pq1.rear = -1;
    int choice, val, prio;

    while (1)
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Get Front\n");
        printf("5. Get Rear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &val);
            printf("Enter the priority: ");
            scanf("%d", &prio);
            enqueue(&pq1, val, prio);
            break;
        case 2:
            val = dequeue(&pq1);
            if (val != -1)
            {
                printf("Dequeued element: %d\n", val);
            }
            break;
        case 3:
            display(&pq1);
            break;
        case 4:
            val = getfront(&pq1);
            if (val != -1)
            {
                printf("Front element: %d\n", val);
            }
            break;
        case 5:
            val = getrear(&pq1);
            if (val != -1)
            {
                printf("Rear element: %d\n", val);
            }
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
