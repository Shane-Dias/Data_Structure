#include <stdio.h>

typedef struct Stack
{
    int top;
    int a[50];
} stack;

int isoperand(char op)
{
    if (op >= '0' && op <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *p, int val)
{
    if (p->top == 50 - 1)
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

int main()
{
    stack s;
    s.top = -1;
    char postfix[50];
    printf("Enter the postfix expression:\n");
    gets(postfix);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
        {
            push(&s, postfix[i] - '0'); // important:coverting character into its int equivalent
        }
        else
        {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (postfix[i])
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            case '%':
                push(&s, op1 % op2);
                break;

            default:
                printf("Invalid operator used");
                return -1;
                break;
            }
        }
    }
    printf("The result is:%d", pop(&s));
}