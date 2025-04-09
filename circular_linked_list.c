#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* getnode() 
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    return ptr;
}
void creation(int x, struct node **head, struct node **tail) 
{
    struct node *p;
    p = getnode();
    p->data = x;
    p->next = NULL;
    if (*head == NULL) 
        *head = *tail = p;
    else 
    {
        (*tail)->next = p;
        *tail = p;
    }
    (*tail)->next = *head;
}
void traverse(struct node *head) 
{
    struct node *temp;
    if (head == NULL)
        printf("LIST IS EMPTY\n");
    else {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}
void insert_beg(int ele, struct node **head, struct node **tail) 
{
    struct node *p;
    p = getnode();
    p->data = ele;
    p->next = *head;
    *head = p;
    (*tail)->next = *head; 
}
void insert_end(int ele, struct node **head, struct node **tail) 
{
    struct node *p = getnode();
    p->data = ele;
    p->next = *head;
    (*tail)->next = p;
    *tail = p; 
}
void insert_loc(int ele, int loc, struct node **head, struct node **tail) 
{
    struct node *temp = *head;
    struct node *p = getnode();
    p->data = ele;
    int i = 1;
    if (loc == 1) 
    {
        insert_beg(ele, head, tail);
        return;
    }
    while (i < loc - 1 && temp != NULL) 
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) 
    {
        printf("POSITION IS OUT OF RANGE !\n");
        return;
    }
    p->next = temp->next;
    temp->next = p;
}
void delete_beg(struct node **head, struct node **tail) 
{
    if (*head == NULL)
        printf("LIST IS EMPTY\n");
    else 
    {
        struct node *temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head; 
        free(temp);
    }
}
void delete_end(struct node **head, struct node **tail) 
{
    if (*head == NULL)
        printf("List is empty\n");
    else 
    {
        struct node *temp = *head;
        while (temp->next != *tail) 
        {
            temp = temp->next;
        }
        free(*tail);
        *tail = temp;
        (*tail)->next = *head;
    }
}
void delete_loc(int loc, struct node **head, struct node **tail) 
{
    if (*head == NULL)
        printf("LIST IS EMPTY\n");
    else {
        struct node *temp = *head;
        struct node *p;
        int i = 1;
        if (loc == 1) 
        {
            *head = (*head)->next;
            free(temp);
            (*tail)->next = *head; 
            return;
        }
        while (i < loc - 1 && temp != NULL) 
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL || temp->next == NULL) 
        {
            printf("POSITION OUT OF RANGE !\n");
            return;
        }
        p = temp->next;
        temp->next = p->next;
        if (p == *tail) 
        {
            *tail = temp;
        }
        free(p);
    }
}
void search(int ele, struct node *head) 
{
    struct node *temp = head;
    int found = 0;
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    do 
    {
        if (temp->data == ele) 
        {
            printf("ELEMENT %d FOUND IN THE LIST \n", ele);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (!found) 
    {
        printf("ELEMENT %d NOT FOUND IN THE LIST\n", ele);
    }
}
int main() 
{
    int n, data, ele, pos, op;
    printf("\nENTER THE NUMBER OF NODES TO CREATE : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        printf("\nENTER THE DATA : ");
        scanf("%d", &data);
        creation(data, &head, &tail);
    }
    printf("*************************************\n");
    printf("*       CIRCULAR LINKED LIST        *\n");
    printf("* 1. INSERT AT BEGINNING            *\n");
    printf("* 2. INSERT AT END                  *\n");
    printf("* 3. INSERT AT LOCATION             *\n");
    printf("* 4. DELETE AT BEGINNING            *\n");
    printf("* 5. DELETE AT END                  *\n");
    printf("* 6. DELETE AT LOCATION             *\n");
    printf("* 7. TRAVERSE                       *\n");
    printf("* 8. SEARCH                         *\n");
    printf("* 9. EXIT                           *\n");
    printf("*************************************\n");
    do 
    {
        printf("\nENTER THE OPERATION TO PERFORM: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("\nENTER THE DATA : ");
                scanf("%d", &ele);
                insert_beg(ele, &head, &tail);
                break;
            case 2:
                printf("\nENTER THE DATA : ");
                scanf("%d", &ele);
                insert_end(ele, &head, &tail);
                break;
            case 3:
                printf("\nENTER THE DATA AND POSITION : ");
                scanf("%d%d", &ele, &pos);
                insert_loc(ele, pos, &head, &tail);
                break;
            case 4:
                delete_beg(&head, &tail);
                break;
            case 5:
                delete_end(&head, &tail);
                break;
            case 6:
                printf("\nENTER THE POSITION : ");
                scanf("%d", &pos);
                delete_loc(pos, &head, &tail);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("\nENTER THE ELEMENT TO SEARCH : ");
                scanf("%d", &ele);
                search(ele, head);
                break;
            case 9:
                printf("Thank You.....\n");
                return 0;
            default:
                printf("PLEASE ENTER A VALID OPTION !\n");
        }
    } while (1);
    return 0;
} 
    