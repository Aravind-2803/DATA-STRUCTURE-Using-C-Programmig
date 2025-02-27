#include<stdio.h>
#define MAX 10
void insert(int queue[],int *front,int *rear)
{
    int num;
    printf("enter the num to be inserted :");
    scanf("%d",&num);
    
    if(*rear==MAX-1)
        printf("overflow \n");
        
    else {if(*front==-1 && *rear==-1)
        *front = *rear=0;
    else
    (*rear)++;
    }
    queue[*rear]=num;
    printf("the num %d is inserted at the position %d \n ",queue[*rear],*rear);
}

void delete(int queue[],int *front, int *rear)
{
    int num;
    if(*front==-1)
        printf("underflow \n");
    else
    {
        printf("Deleted number : %d \n",queue[*front]);
        if (*front== *rear)
            *front = *rear=-1;
        else
        (*front)++;
    }
}

void  display(int queue[], int front, int rear)
{
  int i;
  if(rear==-1 || front==-1)
    printf("empty queue \n");
  else
  {
    printf("\n The queue is ");
    for(i=front;i<=rear;i++)
    printf("\t %d",queue[i]);
  }
}

int main()
{
  int option,num;
  int queue[MAX],rear=-1,front=-1;

  while(1)
  {
  printf("\n-----------------------------------------");
  printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");

   printf("Enter your option :  ");
   scanf("%d",&option);

   switch(option)
   {
    case 1:
    insert(queue, &front, &rear);
    break;

    case 2:
    delete(queue, &front, &rear);
    break;

    case 3:
    display(queue, front, rear);
    break;
    
    case 4:
    printf("THANK YOU................\n");
    return 0;
    
    default:
        printf("invalid  so try again..........\n");
   }

  }
  return 0;
  }
