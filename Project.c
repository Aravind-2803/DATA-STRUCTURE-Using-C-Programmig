#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct 
{
    char name[50];
    int priority;
} Task;
Task pq[MAX];
int size = 0;
typedef struct Node 
{
    Task task;
    struct Node* next;
} Node;
Node* completedTasks = NULL;
void insertTask() 
{
    Task t;
    printf("Enter task name: ");
    scanf(" %[^\n]", t.name);
    printf("Enter task priority (1 = High, 2 = Medium, 3 = Low): ");
    scanf("%d", &t.priority);
    int i = size++;
    while (i > 0 && pq[i - 1].priority > t.priority)
    {
        pq[i] = pq[i - 1];
        i--;
    }
    pq[i] = t;
    printf("Task added successfully!\n");
}
void displayTasks() 
{
    if (size == 0) 
    {
        printf("No scheduled tasks.\n");
        return;
    }
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d. %s [Priority: %d]\n", i + 1, pq[i].name, pq[i].priority);
    }
}
void displayPendingTasks() 
{
    if (size == 0) 
    {
        printf("No pending tasks.\n");
        return;
    }
    printf("\nPending Tasks:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d. %s [Priority: %d]\n", i + 1, pq[i].name, pq[i].priority);
    }
}
void completeTask() 
{
    if (size == 0) 
    {
        printf("No tasks to complete.\n");
        return;
    }
    Task done = pq[0];
    for (int i = 1; i < size; i++) 
    {
        pq[i - 1] = pq[i];
    }
    size--;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = done;
    newNode->next = completedTasks;
    completedTasks = newNode;
    printf("Task '%s' marked as completed.\n", done.name);
}
void displayCompleted() 
{
    if (completedTasks == NULL) 
    {
        printf("No completed tasks.\n");
        return;
    }
    printf("\nCompleted Tasks:\n");
    Node* temp = completedTasks;
    int count = 1;
    while (temp) 
    {
        printf("%d. %s [Priority: %d]\n", count++, temp->task.name, temp->task.priority);
        temp = temp->next;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Task Scheduler ---\n1. Add Task\n2. Show Scheduled Tasks\n3. Complete Task\n4. Show Completed Tasks\n5. Show Pending Tasks\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
    {
    case 1:
        insertTask();
            break;
        case 2:
            displayTasks();
            break;
        case 3:
            completeTask();
            break;
        case 4:
            displayCompleted();
            break;
        case 5:
            displayPendingTasks();
            break;
        case 6:
            printf("Thank You..\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}