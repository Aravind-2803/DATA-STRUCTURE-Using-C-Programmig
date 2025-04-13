#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int priority;
    struct Node* next;
};
struct Node* createNode(int data, int priority)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
void insert(struct Node** head, int data, int priority)
{
    struct Node* newNode = createNode(data, priority);
    struct Node* current;
    if (*head == NULL || (*head)->priority < priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void deleteHighestPriority(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d with priority: %d\n", temp->data, temp->priority);
    free(temp);
}
void peek(struct Node* head)
{
    if (head == NULL)
    {
        printf("Priority Queue is empty.\n");
    }
    else
    {
        printf("Element with highest priority: %d with priority: %d\n", head->data, head->priority);
    }
}
void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Priority Queue:\n");
    while (current != NULL)
    {
        printf("Data: %d, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}
int main()
{
    struct Node* pq = NULL;
    int choice, data, priority;
    while(1)
    {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete Highest Priority\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            insert(&pq, data, priority);
            break;
        case 2:
            deleteHighestPriority(&pq);
            break;
        case 3:
            peek(pq);
            break;
        case 4:
            display(pq);
            break;
        case 5:
            printf("Thank You...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } 
    return 0;
}