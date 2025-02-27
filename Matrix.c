#include<stdio.h>
#include<stdlib.h>

void oneallocate(int m,int n,int **ptr1)
{
    for(int i=0;i<m;i++)
    {
        ptr1[i] = (int *) malloc(sizeof(int) * n);
    }   
}
void twoallocate(int m,int n,int **ptr1,int **ptr2)
{
    for(int i=0;i<m;i++)
    {
        ptr1[i] = (int *) malloc(sizeof(int) * n);
        ptr2[i] = (int *) malloc(sizeof(int) * n);
    }
}
void add(int m, int n,int **ptr1,int **ptr2)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0 ;j<n; j++)
        {
            printf("%d\t", ptr1[i][j] + ptr2[i][j]);
        }
        printf("\n");
    }
}
void sub(int m, int n,int **ptr1,int **ptr2)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0 ;j<n; j++)
        {
            printf("%d\t", ptr1[i][j] - ptr2[i][j]);
        }
        printf("\n");
    }
}
void mul(int m, int n,int m1,int n1,int **ptr1,int **ptr2)
{
    int **result = malloc(sizeof(int *) * n1);
    oneallocate(m1,n,result);
    int sum;
    
        for(int i=0;i<m;i++)
        {
           for(int j=0 ;j<m1; j++)
           {    
                sum = 0;
                for(int k=0 ; k<n ; k++)
                {
                    sum += ptr1[i][k] * ptr2[k][j];
                }
                result[i][j] = sum;
                printf("%d   ",result[i][j]);
            }
            printf("\n");
        }
}
void transpose(int m,int n,int **ptr1)
{
  for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              printf("%d\t",ptr1[i][j]);
          }
          printf("\n");
      }
    printf("-----------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",ptr1[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    
    int row,col,row1,col1,choice;
    while(1)
    {
        choice =0;
        printf("-----------------------------------------\n");
        printf(" 1.ADDITION \n 2.SUBRACTION \n 3.TRANSPOSE \n 4.MULTIPLICATION \n 5.EXIT \n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        
        int **ptr1; 
        int **ptr2;
            

        switch(choice)
        {
            case 1:
                printf("Enter the value of row     : ");
                scanf("%d",&row);
                printf("Enter the value of column  : ");
                scanf("%d",&col);
                ptr1 = malloc(sizeof(int *) * row);
                ptr2 = malloc(sizeof(int *) * row);
                twoallocate(row,col,ptr1,ptr2);
                printf("Enter the elements of matrix A : ");
                for(int i=0;i<row;i++)
                {
                    for(int j=0 ;j<col; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("Enter the elements of matrix B : ");
                for(int i=0;i<row;i++)
                {
                    for(int j=0 ;j<col; j++)
                    {
                        scanf("%d",&ptr2[i][j]);
                    }
                }
                printf("-----------------------------------------\n");
                add(row,col,ptr1,ptr2);
                break;
            case 2:
                printf("Enter the value of row      : ");
                scanf("%d",&row);
                printf("Enter the value of column    : ");
                scanf("%d",&col);
                ptr1 = malloc(sizeof(int *) * row);
                ptr2 = malloc(sizeof(int *) * row);
                twoallocate(row,col,ptr1,ptr2);
                printf("Enter the elements of matrix A  : ");
                for(int i=0;i<row;i++)
                {
                    for(int j=0 ;j<col; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("Enter the elements of matrix B  : ");
                for(int i=0;i<row;i++)
                {
                    for(int j=0 ;j<col; j++)
                    {
                        scanf("%d",&ptr2[i][j]);
                    }
                }
                printf("-----------------------------------------\n");
                sub(row,col,ptr1,ptr2);
                break;
            case 3:
                printf("Enter the value of row : ");
                scanf("%d",&row);
                printf("Enter the value of col  : ");
                scanf("%d",&col);
                ptr1 = malloc(sizeof(int *) * row);
                oneallocate(row,col,ptr1);
                printf("Enter the elements of matrix A  : ");
                for(int i=0;i<row;i++)
                {
                    for(int j=0 ;j<col; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("-----------------------------------------\n");
                transpose(row,col,ptr1);
                break;
            case 4:
                printf("Enter the value of first row      : ");
                scanf("%d",&row); 
                printf("Enter the value of first  column   :");
                scanf("%d",&col);
                printf("Enter the value of second row  :");
                scanf("%d",&row1);
                printf("Enter the value of second column  : ");
                scanf("%d",&col1);
                ptr1 = malloc(sizeof(int *) * col);
                ptr2 = malloc(sizeof(int *) * col1);
                oneallocate(row,col,ptr1);
                oneallocate(row1,col1,ptr2);
                
                if(col != row1)
                {
                    printf("Try Again\n");
                    break;
                    
                }
                else
                {
                    printf("Enter the elements of matrix A  ");
                    for(int i=0;i<row;i++)
                    {
                        for(int j=0 ;j<col; j++)
                        {
                            scanf("%d",&ptr1[i][j]);
                        }
                    }
                    printf("Enter the elements of matrix B  ");
                    for(int i=0;i<row1;i++)
                    {
                        for(int j=0 ;j<col1; j++)
                        {
                            scanf("%d",&ptr2[i][j]);
                        }
                    }
                    printf("-----------------------------------------\n");
                    mul(row,col,row1,col1,ptr1,ptr2);
                }
                break;
            case 5:
                printf("THANK YOU.............");
                return 0;
            default:
                printf("Invalid Choice");
                break;
        }
    }
}
