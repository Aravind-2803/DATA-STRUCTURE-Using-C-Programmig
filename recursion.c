#include<stdio.h>

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
int sum(int n) 
{
	
	if (n == 0)
		return n; 
	else
		return n + sum(n-1);
	
}

int fibonacci(int n) 
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}


int power(int b, int e) 
{
    if (e == 0)
        return 1;
    else
        return (b * power(b, e - 1));
}


int main()
{
    int choice=0,num=0;
    printf("MENU USING RECURSIVE FUNCTION \n");
    while(1)
    {
        printf("-----------------------------------------\n");
        printf("1.Factorial  \n");
        printf("2.Sum of N Terms \n");
        printf("3.Fibonacci\n");
        printf("4.Power of a Number \n");
        printf("5.Rverse A String \n");
        printf("6.EXIT\n");
        printf("-----------------------------------------\n");
        printf("Enter Your Choice : " );
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter The Number For Factorial : ");
                scanf("%d",&num);
                printf("  *   Factorial of %d is %d \n",num,fact(num));
                break;
            case 2:
                int number,result;
	            printf("Enter a positive integer: ");
	            scanf("%d", &number);
	            printf("   *   SUM  = %d \n", sum(number));
                break;
            case 3:
                 int n = 0;
                 printf("Enter The Number Of Fibonacci Terms \n");
                 scanf("%d",&n);
                 printf("Fibonacci Sequence: ");
                 for (int i = 0; i < n; i++)
                     printf("%d, ", fibonacci(i));
                printf("\n");     
                break;
            case 4:
                int base=0,exponent=0;
                printf("Enter the base : ");
                scanf("%d",&base);
                printf("Enter The Exponent :");
                scanf("%d",&exponent);
                printf("The Power Of Base %d And Exponent %d Is %d \n",base,exponent,power(base,exponent));
                break;
            case 5:
                break;
            case 6:
                printf("THANK YOU.....");
                return 0;
            default:
                printf("Invalid Choice \n");
        }
    }
    return 0;
}
