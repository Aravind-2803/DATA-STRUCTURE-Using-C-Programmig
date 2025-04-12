#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreateNode(int data) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

void AddBegin(struct Node** head, int ele) {
    struct Node* nn = CreateNode(ele);
    if (*head == NULL) {
        *head = nn;
    } else {
        nn->next = *head;
        (*head)->prev = nn;
        *head = nn;
    }
    printf("Added: %d\n", ele);
}

void AddEnd(struct Node** head, int ele) {
    struct Node* nn = CreateNode(ele);
    if (*head == NULL) {
        *head = nn;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = nn;
    nn->prev = temp;
    printf("Added: %d\n", ele);
}

void AddPosition(struct Node** head, int ele, int loc) {
    if (*head == NULL || loc == 1) {
        AddBegin(head, ele);
        return;
    }
    struct Node* nn = CreateNode(ele);
    struct Node* temp = *head;
    int i = 1;
    while (i < loc - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    nn->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = nn;
    temp->next = nn;
    nn->prev = temp;
    printf("Added: %d\n", ele);
}

void DeleteBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
    printf("Deleted from beginning.\n");
}

void DeleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

void DeletePosition(struct Node** head, int loc) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    int i = 1;
    while (i < loc && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted from position %d.\n", loc);
}

void Display(struct Node** head) {
    struct Node* temp = *head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("|%d| <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int pos, choice = 1, data;
    while (choice != 8) {
        printf("\n|--------------------------|\n");
        printf("|        MAIN MENU         |\n");
        printf("| 1) Insert at begin       |\n");
        printf("| 2) Insert at end         |\n");
        printf("| 3) Insert at position    |\n");
        printf("| 4) Delete at begin       |\n");
        printf("| 5) Delete at end         |\n");
        printf("| 6) Delete at position    |\n");
        printf("| 7) Traverse              |\n");
        printf("| 8) Exit                  |\n");
        printf("|--------------------------|\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to add at the beginning: ");
                scanf("%d", &data);
                AddBegin(&head, data);
                break;
            case 2:
                printf("Enter data to add at the end: ");
                scanf("%d", &data);
                AddEnd(&head, data);
                break;
            case 3:
                printf("Enter data to add at a position: ");
                scanf("%d", &data);
                printf("Enter position to add data: ");
                scanf("%d", &pos);
                AddPosition(&head, data, pos);
                break;
            case 4:
                DeleteBegin(&head);
                break;
            case 5:
                DeleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete data: ");
                scanf("%d", &pos);
                DeletePosition(&head, pos);
                break;
            case 7:
                Display(&head);
                break;
            case 8:
                printf("Thank you....\n");
                break;
            default:
                printf("!!! Invalid choice !!!\n");
                break;
        }
    }
    return 0;
}
