#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int vertex;
    struct Node* next;
};
struct AdjList 
{
    struct Node* head;
};
struct Graph 
{
    int numVertices;
    struct AdjList* array;
};
struct Node* createNode(int v) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int numVertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    for (int i = 0; i < numVertices; ++i) 
    {
        graph->array[i].head = NULL;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) 
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
void DFSUtil(struct Graph* graph, int v, int visited[])
{
    visited[v] = 1;
    printf("%d ", v);
    struct Node* current = graph->array[v].head;
    while (current) 
    {
        if (!visited[current->vertex]) 
        {
            DFSUtil(graph, current->vertex, visited);
        }
        current = current->next;
    }
}
void DFS(struct Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) 
    {
        visited[i] = 0;
    }
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}
void BFS(struct Graph* graph, int startVertex) 
{
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) 
    {
        visited[i] = 0;
    }
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    while (front < rear) 
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        struct Node* current = graph->array[currentVertex].head;
        while (current) 
        {
            if (!visited[current->vertex]) 
            {
                visited[current->vertex] = 1;
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}
void displayGraph(struct Graph* graph) 
{
    printf("Adjacency List of the graph:\n");
    for (int i = 0; i < graph->numVertices; ++i) 
    {
        printf("Vertex %d: ", i);
        struct Node* current = graph->array[i].head;
        while (current) 
        {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}
int main() 
{
    int numVertices, choice, src, dest, startVertex;
    struct Graph* graph = NULL;
    while(1) 
    {
        printf("\nGraph Creation and Traversal Menu:\n");
        printf("1. Create Graph\n");
        printf("2. Add Edge\n");
        printf("3. Display Graph\n");
        printf("4. Depth First Search (DFS)\n");
        printf("5. Breadth First Search (BFS)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &numVertices);
                if (numVertices > 0) 
                {
                    if (graph != NULL) 
                    {
                        printf("Warning: Existing graph will be overwritten.\n");
                    }
                    graph = createGraph(numVertices);
                    printf("Graph with %d vertices created.\n", numVertices);
                } 
                else 
                {
                    printf("Number of vertices must be positive.\n");
                }
                break;
            case 2:
                if (graph == NULL) 
                {
                    printf("Please create a graph first (option 1).\n");
                    break;
                }
                printf("Enter source vertex (0 to %d): ", graph->numVertices - 1);
                scanf("%d", &src);
                printf("Enter destination vertex (0 to %d): ", graph->numVertices - 1);
                scanf("%d", &dest);
                if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) 
                {
                    addEdge(graph, src, dest);
                    printf("Edge (%d, %d) added.\n", src, dest);
                } 
                else 
                {
                    printf("Invalid vertex input.\n");
                }
                break;
            case 3:
                if (graph == NULL) 
                {
                    printf("Please create a graph first (option 1).\n");
                    break;
                }
                displayGraph(graph);
                break;
            case 4:
                if (graph == NULL) 
                {
                    printf("Please create a graph first (option 1).\n");
                    break;
                }
                printf("Enter the starting vertex for DFS (0 to %d): ", graph->numVertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < graph->numVertices) 
                {
                    DFS(graph, startVertex);
                } 
                else 
                {
                    printf("Invalid starting vertex.\n");
                }
                break;
            case 5:
                if (graph == NULL) 
                {
                    printf("Please create a graph first (option 1).\n");
                    break;
                }
                printf("Enter the starting vertex for BFS (0 to %d): ", graph->numVertices - 1);
                scanf("%d", &startVertex);
                if (startVertex >= 0 && startVertex < graph->numVertices) 
                {
                    BFS(graph, startVertex);
                } 
                else 
                {
                    printf("Invalid starting vertex.\n");
                }
                break;
            case 6:
                printf("THANK YOU......\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
