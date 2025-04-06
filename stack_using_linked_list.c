#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode()
{
    return (struct node*)malloc(sizeof(struct node));
}
void push(struct node **top,int data)
{
    struct node *ptr = getnode();
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
}
int pop(struct node **top)
{
    if(*top == NULL)
        return 0;
    else
    {
        int value = (*top)->data;
        struct node *temp = *top;
        
        *top = (*top)->next;
        free(temp);
        return value;
    }
}
int peektop(struct node **top)
{
    if(*top == NULL)
        return 0;
    else
    {
        return (*top)->data;
    }
}
void display(struct node **top)
{
    if(*top == NULL)
        printf("CAUTION : UNDER FLOW !");
    else
    {
        struct node *temp = *top;
        while((temp)!=NULL)
        {
            printf("%d ",(temp)->data);
            temp = (temp)->next;
        }
    }
}
int main()
{
    struct node *top = NULL;
    int ch,data;
    while(ch!=5)
    {
        printf("\n*************************************");
        printf("\n*       STACK OPERATION             *");
        printf("\n* 1. PUSH                           *");
        printf("\n* 2. POP                            *");
        printf("\n* 3. PEEKTOP                        *");
        printf("\n* 4. DISPLAY                        *");
        printf("\n* 5. EXIT                           *");
        printf("\n*************************************");
        printf("\nENTER THE OPTION : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("ENTER THE VALUE : ");
                scanf("%d",&data);
                push(&top,data);
                break;
            case 2:               
                data = pop(&top);
                if(data)
                    printf("%d",data);
                else
                    printf("CAUTION - UNDER FLOW !");
                break;
            case 3:
                data = peektop(&top);
                if(data)
                    printf("%d",peektop(&top));
                else
                    printf("CAUTION - UNDER FLOW !");
                break;
            case 4:
                display(&top);
                break;
            case 5:
                printf("THANK YOU ......");
                break;
            default:
                printf("PLEASE ENTER A VALID CHOICE ");
                break;
        }
    }
}