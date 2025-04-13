#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}
void insert(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
    }
     else 
    {
        struct Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}
void delete(struct Node** head, int data) 
{
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = *head;
    do 
    {
        if (current->data == data) 
        {
            if (current->next == current) 
            {
                free(current);
                *head = NULL;
            }
             else 
             {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == *head)
                 {
                    *head = current->next; 
                }
                free(current);
            }
            printf("Node with data %d deleted.\n", data);
            return;
        }
        current = current->next;
    } while (current != *head);
    printf("Node with data %d not found.\n", data);
}
void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do 
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
void search(struct Node* head, int data)
 {
    if (head == NULL)
     {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    do 
    {
        if (current->data == data)
         {
            printf("Node with data %d found.\n", data);
            return;
        }
        current = current->next;
    } while (current != head);
    printf("Node with data %d not found.\n", data);
}
int main() 
{
    struct Node* head = NULL;
    int choice, data;
    while (1) 
    {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5:
                printf("Thank You .....\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break ;
        }
    }
    return 0;
}