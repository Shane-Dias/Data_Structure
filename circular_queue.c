#include <stdio.h>
#define max 5

typedef struct circular_queue
{
    int rear;
    int front;
    int a[max];
} queue;

int isfull(queue *p)
{
    if ((p->front == 0 && p->rear == max - 1) || (p->front == p->rear + 1))
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
    if (p->front == -1 && p->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *p, int v)
{
    if (isfull(p))
    {
        printf("Queue is full\n");
    }
    else if (p->front == -1 && p->rear == -1)
    {
        p->front = 0;
        p->rear = 0;
        p->a[p->rear] = v;
    }
    else if (p->rear == max - 1 && p->front != 0)
    {
        p->rear = 0;
        p->a[p->rear] = v;
    }
    else
    {
        p->rear++;
        p->a[p->rear] = v;
    }
}

int dequeue(queue *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int val=p->a[p->front];
    if (p->rear == p->front)
    {
        p->rear = -1;
        p->front = -1;
        return val;
    }
    else if (p->front == max - 1)
    {
        p->front = 0;
        return val;
    }
    else
    {
        p->front++;
        return val;
    }
}

void display(queue *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    if (p->rear >= p->front)
    {
        for (int k = p->front; k <= p->rear; k++)
        {
            printf("%d \n", p->a[k]);
        }
    }
    else
    {
        for (int k = p->front; k < max; k++)
        {
            printf("%d \n", p->a[k]);
        }
        for (int k = 0; k <= p->rear; k++)
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
    queue q = {.rear = -1, .front = -1};
    int val, ch;

    while (1)
    {
        printf("Enter 1 for enqueue \n 2 for dequeue \n 3 for display \n 4 get rear \n 5 get front \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to insert:");
            scanf("%d", &val);
            enqueue(&q, val);
            break;

        case 2:
            val = dequeue(&q);
            if (val != -1)
            {
                printf("Deleted element is %d \n", val);
            }
            break;

        case 3:
            display(&q);
            break;

        case 4:
            val = getrear(&q);
            if (val != -1)
            {
                printf("Element at rear is %d \n", val);
            }
            break;

        case 5:
            val = getfront(&q);
            if (val != -1)
            {
                printf("Element at front is %d \n", val);
            }
            break;

        default:
            printf("Exiting loop\n");
            return 0;
            break;
        }
    }
}
