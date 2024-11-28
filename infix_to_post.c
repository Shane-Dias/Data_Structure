#include <stdio.h>

typedef struct Stack
{
    int top;
    char a[50];
} stack;

int isoperand(char op)
{
    if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *p, char val)
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

char pop(stack *p)
{
    if (p->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char val = p->a[p->top];
        p->top--;
        return val;
    }
}

char peek(stack *p)
{
    if (p->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return p->a[p->top];
    }
}

int precedance(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '/' || ch == '*')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else if (ch == '(')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    stack s;
    s.top = -1;
    char infix[50], postfix[50];
    int j = 0;
    printf("Enter infix experssion\n");
    gets(infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(') // if open bracket found push in stack
        {
            push(&s, infix[i]);
        }
        else if (isoperand(infix[i])) // if operand found store it in postfix array
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == ')') // if closing bracket found then pop all operators from stack until opening bracket not found
        {
            do
            {
                postfix[j++] = pop(&s);
            } while (peek(&s) != '(');
            pop(&s);   //to pop the opening bracket
        }
        else // if operator is found
        {
            while (s.top != -1 && precedance(infix[i]) <= precedance(peek(&s)))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (s.top != -1)
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    printf("Postfix expression is:%s", postfix);

    return 0;
}