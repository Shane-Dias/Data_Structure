#include <stdio.h>

#define MAX 5
typedef struct linear_queue
{
    int rear, front;
    int a[MAX];
} queue;

int isfull(queue *p)
{
    if (p->front == 0 && p->rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(queue *p)
{
    if ((p->front == -1 && p->rear == -1) || p->front > p->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *p, int val)
{
    if (isfull(p))
    {
        printf("Queue Overflow\n");
    }
    else if (p->front == -1 && p->rear == -1)
    {
        p->front = 0;
        p->rear = 0;
        p->a[p->rear] = val;
    }
    else
    {
        p->rear++;
        p->a[p->rear] = val;
    }
}

int dequeue(queue *p)
{
    if (isempty(p))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int popped = p->a[p->front];
        p->front++;
        return popped;
    }
}

void display(queue *p)
{
    int k;
    if (isempty(p))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (k = p->front; k <= p->rear; k++)
        {
            printf("%d \n", p->a[k]);
        }
    }
}

int getrear(queue *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return p->a[p->rear];
}

int getfront(queue *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return p->a[p->front];
}

int main()
{
    queue q;
    q.front = -1;
    q.rear = -1;
    int ch, val;
    while (1)
    {
        printf("Enter 1 for enqueue \n 2 for dequeue \n 3 for display \n 4 get front \n 5 get rear \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be enqueued:\n");
            scanf("%d", &val);
            enqueue(&q, val);
            break;
        case 2:
            val = dequeue(&q);
            if (val != -1)
            {
                printf("Element removed was:%d\n", val);
            }
            break;
        case 3:
            printf("Displaying Queue:\n");
            display(&q);
            break;
        case 4:
            val = getfront(&q);
            if (val != -1)
            {
                printf("Front element is:%d\n", val);
            }
            break;
        case 5:
            val = getrear(&q);
            if (val != -1)
            {
                printf("Rear element is:%d\n", val);
            }
            break;
        default:
            printf("Exiting...");
            return 0;
            break;
        }
    }
}