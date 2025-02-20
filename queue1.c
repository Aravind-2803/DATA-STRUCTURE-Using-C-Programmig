#include<stdio.h>
#include<stdbool.h>

bool isfull(int q[], int r,int max)
{
    if(r == max-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty(int q[],int f)
{
    if(f == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int q[],int *f,int *r,int max,int x)
{
    if(isfull(q,*r,max))
    {
        printf("queue is full");
    }
    else if(*r == -1)
    {
        *r=0;
        *f=0;
        q[*r] = x;
        (*r)++;
    }
    else
    {
        q[*r] = x;
        (*r)++;
    }
}

int dequeue(int q[],int *f,int *r)
{
    int a;
    if(isempty(q,*f))
    {
        printf("stack is empty");
    }
    else 
    {   
        if(*r == *f){
        a = q[*f]; 
        *r = -1;
        *f = -1;
        return a;
    }
    else
    {
        a = q[*f];
        (*f)--;
        return a;
    }
}
void peekfront(int q[],int f)
{
    if(isempty(q,f))
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d",q[f]);
    }
}
int main()
{
    int front = -1;
    int rear =-1;
    int q[10];
    int max =10;
    int choise = 0; 
    while(choise != 5)
    {

        choise = 0;
        printf("enter your choice\n 1.Push \n 2.Pop \n 3.Peek Top \n 4.Display \n 5.Exit\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
        printf("enter the data");
            do
            {
                data = getchar();
            }
            while (data == '\0' || data == '\n');    
            push(s,&top,max,data);
            printf("successfully pushed\n");
            break;
        case 2:
            data = pop(s,&top,max);
            if(data != '\0')
            {
                printf("the poped element is %c\n",data);
            }
            if(!isempty(s,&top))
            {
                printf("stack is empty\n");
            }
            break;
        case 3:
            printf("%d\n",peektop(s,&top));
            break;
        case 4:
            for(int i = 0;i <strlen(s);i++)
            {
                printf("%c",s[i]);
            }
            break;
        case 5:
            printf("...TERMINATED...\n");
            break;
        default:
            printf("enter the valid choise");
            break;
        }
        printf("\n");     
    }

}
