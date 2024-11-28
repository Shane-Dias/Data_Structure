#include <stdio.h>

#define MAX 5
typedef struct Stack
{
    int top;
    int a[MAX];
} stack;

int isfull(stack *p)
{
    if (p->top == MAX - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(stack *p, int val)
{
    if (isfull(p))
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
    if (isempty(p))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int val = p->a[p->top];
        p->top--;
        printf("Popped element is %d\n", val);
        return val;
    }
}

void display(stack *p)
{
    if (isempty(p))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Displaying Stack\n");
        for (int i = p->top; i >= 0; i--)
        {
            printf("%d\n", p->a[p->top]);
        }
    }
}

int peek(stack *p)
{
    if (isempty(p))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Top most element is %d\n", p->a[p->top]);
        return p->a[p->top];
    }
}

int main()
{
    stack s;
    s.top = -1;
    int ch, val;
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: // push
            printf("Enter the value to be pushed:\n");
            scanf("%d", &val);
            push(&s, val);
            break;
        case 2: // pop
            val = pop(&s);
            break;
        case 3: // display
            display(&s);
            break;
        case 4: // peek
            val = peek(&s);
            break;
        case 5: // is full
            val = isfull(&s);
            if (val)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 6: // is empty
            val = isempty(&s);
            if (val)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        default:
            printf("Exiting");
            return 0;
        }
    }
}