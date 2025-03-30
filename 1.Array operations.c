#include<stdio.h>
#define Max_Size 100
void insert(int arr[],int *size)
{
    int pos,data;
    printf("Enter the Position :");
    scanf("%d",&pos);
    printf("Enter The Data To Be Inserted : ");
    scanf("%d",&data);
    for(int i=*size;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    (*size)++;
    arr[pos]=data;
    printf("Array Elements : ");
    for(int i=0;i<*size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void delete(int arr[],int *size)
{
    int num,i=0;
    printf("Enter The Element To Be Deleted :");
    scanf("%d",&num);
    for(i=0;i<*size;i++)
    {
        if(arr[i]==num)
        {
            break;
        }
    }
    if(i<*size)
    {
        for(int j=i;j<*size-1;j++)
        {
            arr[j]=arr[j+1];
        }
        (*size)--;
        printf("Elements deleted Sucessfully \n ");
    }
    else
        printf("Elements Not Found In An Array \n");
    printf("Array Elements ");
    for(int i=0;i<*size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void traverse(int arr[],int size)
{
    printf("Array Elements ");
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void search (int arr[],int size)
{
    int num=0,i=0;
    printf("Enter The Element to Be Searched ");
    scanf("%d",&num);
    for(i=0;i<size;i++)
    {
        if (arr[i]==num)
            break;
    }
    if(i<size)
        printf("Element Found At The Index : %d \n",i);
    else
        printf("Element Not Found In An Array \n");
    printf("Array Elements");
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[Max_Size],size=0,choice=0;
    printf("Enter The Number Of Elements In The Array (max %d ) :  ",Max_Size);
    scanf("%d",&size);
    if(size>Max_Size)
    {
        printf("Array Size Exceeds The Limit \n");
        return 1;
    }
    printf("Enter The Elements Of the Array :  ");
    for(int i=0;i<size;i++)
    {
        printf("arr[%d]  :  ",i);
        scanf("%d",&arr[i]);
    }
    while(1)
    {
        printf("Array Operations Menu \n");
        printf("------------------------\n");
        printf("1.Insertion \n");
        printf("2.Deletion  \n");
        printf("3.traverse  \n");
        printf("4.Searching \n");
        printf("5.Exit       \n");
        printf("------------------------\n");
        printf("Enter Your Choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("******************************\n");
                insert(arr,&size);
                printf("*****************************\n");
                break;
            
            case 2:
                printf("******************************\n");
                delete(arr,&size);
                printf("*****************************\n");
                break;
            case 3:
                printf("******************************\n");
                traverse(arr,size);
                printf("*****************************\n");
                break;
            case 4:
                printf("******************************\n");
                search(arr,size);
                printf("*****************************\n");
                break;
            case 5:
                printf("THANK YOU ..... !  \n");
                return 0;
            default:
                printf("INVALID CHOICE ! \n");
        }
    }
    return 0;
}
