#include <stdio.h>
#define max 5

typedef struct double_ended_queue
{
    int rear;
    int front;
    int a[max];
} deque;

int isfull(deque *p)
{
    if ((p->front == 0 && p->rear == max - 1) || (p->front == p->rear + 1))
    {
        return 1;
    }
    return 0;
}

int isempty(deque *p)
{
    if (p->front == -1)
    {
        return 1;
    }
    return 0;
}

void insertrear(deque *p, int v)
{
    if (isfull(p))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (isempty(p))
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
}

void insertfront(deque *p, int v)
{
    if (isfull(p))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (isempty(p))
        {
            p->front = 0;
            p->rear = 0;
        }
        else if (p->front == 0)
        {
            p->front = max - 1;
        }
        else
        {
            p->front--;
        }
        p->a[p->front] = v;
    }
}

int deleterear(deque *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int store = p->a[p->rear];
    if (p->front == p->rear)
    {
        p->front = -1;
        p->rear = -1;
    }
    else if (p->rear == 0)
    {
        p->rear = max - 1;
    }
    else
    {
        p->rear--;
    }
    return store;
}

int deletefront(deque *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int store = p->a[p->front];
    if (p->front == p->rear)
    {
        p->front = -1;
        p->rear = -1;
    }
    else if (p->front == max - 1)
    {
        p->front = 0;
    }
    else
    {
        p->front++;
    }
    return store;
}

void display(deque *p)
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

int getrear(deque *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return p->a[p->rear];
}

int getfront(deque *p)
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
    deque q = {.rear = -1, .front = -1};
    int val, ch;

    while (1)
    {
        printf("Enter 1 for insert rear \n 2 for insert front \n 3 for delete rear \n 4 for delete front \n 5 for display \n 6 get rear \n 7 get front \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to insert at rear:");
            scanf("%d", &val);
            insertrear(&q, val);
            break;

        case 2:
            printf("Enter value to insert at front:");
            scanf("%d", &val);
            insertfront(&q, val);
            break;

        case 3:
            val = deleterear(&q);
            if (val != -1)
            {
                printf("Deleted element from rear is %d \n", val);
            }
            break;

        case 4:
            val = deletefront(&q);
            if (val != -1)
            {
                printf("Deleted element from front is %d \n", val);
            }
            break;

        case 5:
            display(&q);
            break;

        case 6:
            val = getrear(&q);
            if (val != -1)
            {
                printf("Element at rear is %d \n", val);
            }
            break;

        case 7:
            val = getfront(&q);
            if (val != -1)
            {
                printf("Element at front is %d \n", val);
            }
            break;

        default:
            printf("Exiting loop\n");
            return 0;
        }
    }
}
