
#include <stdio.h>

struct stack
{
    char a[50];
    int top;
};

void push(struct stack *p, char val)
{
    if (p->top == 50 - 1)
        printf("Overflow\n");
    else
    {
        p->top++;
        p->a[p->top] = val;
    }
}

char pop(struct stack *p)
{
    if (p->top == -1)
    {
        printf("Underflow\n");
        return '\0';
    }
    else
    {
        char val = p->a[p->top];
        p->top--;
        return val;
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    char exp[50];
    int i;
    char x;
    printf("Enter expression: ");
    gets(exp);
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(&s, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            x = pop(&s);
            if ((x == '(' && exp[i] == ')') || (x == '{' && exp[i] == '}') || (x == '[' && exp[i] == ']'))
            {
                continue;
            }
            else
            {
                printf("Invalid expression");
                return 0;
            }
        }
        else
        {
            continue;
        }
        
    }
    if (s.top == -1)
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;
}