#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
typedef struct 
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    
} Graph;
void initGraph(Graph *graph, int numVertices) 
{
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) 
    {
        for (int j = 0; j < numVertices; j++) 
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph *graph, int startVertex, int endVertex) 
{
    if (startVertex >= 0 && startVertex < graph->numVertices &&
        endVertex >= 0 && endVertex < graph->numVertices) 
        {
        graph->adjMatrix[startVertex][endVertex] = 1;
        graph->adjMatrix[endVertex][startVertex] = 1;
        printf("Edge added between vertex %d and vertex %d.\n", startVertex, endVertex);
    }
    else 
    {
        printf("Invalid vertex numbers.\n");
    }
}
void DFS(Graph *graph, int startVertex, bool visited[]) 
{
    visited[startVertex] = true;
    printf("%d ", startVertex);
    for (int i = 0; i < graph->numVertices; i++) 
    {
        if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) 
        {
            DFS(graph, i, visited);
        }
    }
}
void BFS(Graph *graph, int startVertex) 
{
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    bool visited[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) 
    {
        visited[i] = false;
    }
    visited[startVertex] = true;
    queue[rear++] = startVertex;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    while (front < rear) 
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < graph->numVertices; i++) 
        {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) 
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
int main() 
{
    int numVertices, startVertex, endVertex, choice;
    Graph graph;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    if (numVertices <= 0 || numVertices > MAX_VERTICES) 
    {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }
    initGraph(&graph, numVertices);
    while (1) 
    {
        printf("\nGraph Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Breadth-First Search (BFS)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the start vertex (0 to %d): ", numVertices - 1);
                scanf("%d", &startVertex);
                printf("Enter the end vertex (0 to %d): ", numVertices - 1);
                scanf("%d", &endVertex);
                addEdge(&graph, startVertex, endVertex);
                break;
            case 2:
                printf("Enter the starting vertex for DFS (0 to %d): ", numVertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < numVertices) {
                    bool visited[MAX_VERTICES];
                    for(int i=0; i<numVertices; i++){
                        visited[i] = false;
                    }
                    printf("DFS Traversal starting from vertex %d: ", startVertex);
                    DFS(&graph, startVertex, visited);
                    printf("\n");
                }
                else 
                {
                    printf("Invalid starting vertex for DFS.\n");
                }
                break;
            case 3:
                printf("Enter the starting vertex for BFS (0 to %d): ", numVertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < numVertices) 
                {
                    BFS(&graph, startVertex);
                }
                else 
                {
                    printf("Invalid starting vertex for BFS.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

