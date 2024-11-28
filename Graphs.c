#include<stdio.h>
#include<stdlib.h>
#define MAX 5 

void addedge(int arr[MAX][MAX], int u, int v){
    arr[u][v] = 1;
    arr[v][u] = 1;
}

void deleteedge(int arr[MAX][MAX], int u, int v){
    arr[u][v] = 0;
    arr[v][u] = 0;
}

int searchedge(int arr[MAX][MAX], int u, int v){
    return arr[u][v];
}

void DFSUtil(int graph[MAX][MAX], int visited[MAX], int source){
    visited[source] = 1;
    printf("%d ", source);
    for(int i = 0; i < MAX; i++){
        if(graph[source][i] == 1 && !visited[i]){
            DFSUtil(graph, visited, i);
        }
    }
}

void BFS(int graph[MAX][MAX]){
    int source, visited[MAX] = {0};
    int queue[MAX], rear = 0, front = 0;
    printf("Enter the source node: ");
    scanf("%d", &source);

    visited[source] = 1;
    queue[rear++] = source;

    while(front < rear){
        int current = queue[front++];
        printf("%d ", current);

        for(int i = 0; i < MAX; i++){
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int graph[MAX][MAX]){
    int source, visited[MAX] = {0};
    printf("Enter the source node: ");
    scanf("%d", &source);

    DFSUtil(graph, visited, source);
    printf("\n");
}

int main(){
    int arr[MAX][MAX] = {0};
    while(1){
        int choice, u, v;
        printf("\n1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Breadth First Search\n");
        printf("5. Depth First Search\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the nodes (Eg. 1 -> 2): ");
                scanf("%d %d", &u, &v);
                addedge(arr, u, v);
                printf("Edge has been added!\n");
                break;

            case 2:
                printf("Enter the nodes (Eg. 1 -> 2): ");
                scanf("%d %d", &u, &v);
                deleteedge(arr, u, v);
                printf("Edge has been deleted!\n");
                break;

            case 3:
                printf("Enter the nodes (Eg. 1 -> 2): ");
                scanf("%d %d", &u, &v);
                if(searchedge(arr, u, v))
                    printf("Edge exists.\n");
                else
                    printf("Edge doesn't exist.\n");
                break;

            case 4:
                BFS(arr);
                break;

            case 5:
                DFS(arr);
                break;

            case 6:
                exit(0);

            default:
                printf("Please enter a valid input!\n");
                break;
        }
    }
    return 0;
}
