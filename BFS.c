#include <stdio.h>
#define max 5
#include <stdlib.h>

typedef struct queue
{
    int a[max], front, rear;
} queue;

void enque(queue *p, int n)
{
    if (p->rear == max - 1)
    {
        printf("overflow\n");
        return;
    }
    else if (p->front == -1)
        p->front++;
    p->a[++p->rear] = n;
}

int deque(queue *p)
{
    int val;
    if (p->front == -1)
    {
        printf("underflow\n");
        return -1;
    }
    else if (p->front == p->rear)
    {
        val = p->a[p->front];
        p->front = p->rear = -1;
        return val;
    }
    else
    {

        val = p->a[p->front++];
        return val;
    }
}

int isempty(queue *p)
{
    if (p->front == -1)
        return 1;
    else
        return 0;
}

void BFS(int Graph[][5], int v, int source)
{
    queue q1;

    q1.front = -1, q1.rear = -1;

    int i, visited[v], s;
    for (i = 0; i < v; i++)
        visited[i] = 0;
    visited[source] = 1;
    enque(&q1, source);
    while (!isempty(&q1))
    {
        s = deque(&q1);
        printf("%d ", s);
        for (i = 0; i < v; i++)
        {
            if (Graph[s][i] == 1 && visited[i] == 0)
            {
                enque(&q1, i);
                printf(" value enq:%d ", i);
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
    BFS(Graph, v, source);

    return 0;
}

/*
enter number of vertices and edges
4 4
enter source and destination node
0 1
enter source and destination node
0 2
enter source and destination node
1 2
enter source and destination node
2 3
Adjacency matrix is
0  1  1  0
0  0  1  0
0  0  0  1
0  0  0  0
enter the source node to begin traversal from?0
0  value enq:1  value enq:2 1 2
*/