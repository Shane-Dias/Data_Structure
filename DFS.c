#include <stdio.h>
#define max 5
#include <stdlib.h>
struct stack1
{
    int top;
    int a[10];
};

void push(struct stack1 *p, int n)
{
    p->top++;
    p->a[p->top] = n;
}

int pop(struct stack1 *p)
{
    int x;

    x = p->a[p->top--];
    return x;
}

int isempty(struct stack1 *p)
{
    if (p->top == -1)
        return 1;
    else
        return 0;
}

void DFS(int Graph[][5], int v, int source)
{
    struct stack1 s;
    s.top = -1;
    int i, visited[v], x;
    for (i = 0; i < v; i++)
        visited[i] = 0;
    visited[source] = 1;
    push(&s, source);
    while (!isempty(&s))
    {
        x = pop(&s);
        printf("%d ", x);
        for (i = 0; i < v; i++)
        {
            if (Graph[x][i] == 1 && visited[i] == 0)
            {
                push(&s, i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int v, e, i, j, s, d, source;
    printf("enter number of vertices and edges\n");
    scanf("%d %d", &v, &e);
    int Graph[v][v];
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            Graph[i][j] = 0;

    for (i = 0; i <= e - 1; i++)
    {
        printf("enter source and destination node\n");
        scanf("%d%d", &s, &d);
        Graph[s][d] = 1;
    }
    printf("Adjacency matrix is\n");

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            printf("%d  ", Graph[i][j]);

        printf("\n");
    }

    printf("enter the source node to begin traversal from?");
    scanf("%d", &source);
    DFS(Graph, v, source);

    return 0;
}
/*
output
enter number of vertices and edges
3 2
enter source and destination node
0 1
enter source and destination node
1 2
Adjacency matrix is
0  1  0
0  0  1
0  0  0
enter the source node to begin traversal from?0
0 1
*/