#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Graph structure
typedef struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1; // Assuming an undirected graph
    } else {
        printf("Invalid vertex input.\n");
    }
}

// Function for Depth First Search (DFS) traversal
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function for Breadth First Search (BFS) traversal
void BFS(Graph* graph, int startVertex, int visited[]) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph graph;
    int numVertices, choice, src, dest, startVertex;

    printf("Enter the number of vertices in the graph (up to %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    if (numVertices <= 0 || numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    initGraph(&graph, numVertices);

    do {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. DFS Traversal\n");
        printf("3. BFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                addEdge(&graph, src, dest);
                break;
            case 2:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                int visitedDFS[MAX_VERTICES] = {0};
                printf("DFS Traversal: ");
                DFS(&graph, startVertex, visitedDFS);
                printf("\n");
                break;
            case 3:
                 printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                int visitedBFS[MAX_VERTICES] = {0};
                printf("BFS Traversal: ");
                BFS(&graph, startVertex, visitedBFS);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
