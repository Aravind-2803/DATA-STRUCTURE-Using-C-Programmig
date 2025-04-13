#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displayList(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteNode(struct Node** head, int value)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void searchValue(struct Node* head, int value)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found in the list.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", value);
}
int main()
{
    struct Node* head = NULL;
    int choice, value;
    do
    {
        printf("1. Insert\n2. Display\n3. Delete\n4. Search  \n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &value);
            searchValue(head, value);
            break;
        case 5:
            printf("THANK YOU...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);
    return 0;
}