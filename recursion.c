#include<stdio.h>
int fact(int n)
{
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}
int sum(int n) 
{	
	if (n == 0)
		return n; 
	else
		return (n + sum(n-1));	
}
int fibonacci(int n) 
{
    if (n <= 1)
        return n;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
int power(int b, int e) 
{
    if (e == 0)
        return 1;
    else
        return (b * power(b, e - 1));
}
int isPrime(int n) 
{
    if (n <= 1)
        return 0;
    if (n % 2 == 0)
        return n == 2;
    for (int p = 3; p * p <= n; p += 2) {
         if (isPrime(p) && n % p == 0)
             return 0;
    }
    return 1;
}
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            return (gcd(a - b, b));
        else
            return (gcd(a, b - a));
    }
    return a;
}
int main()
{
    int choice=0,num=0;
    printf("MENU USING RECURSIVE FUNCTION \n");
    while(1)
    {
        printf("-----------------------------------------\n");
        printf("| 1.FACTORIAL                           |\n");
        printf("| 2.SUM OF N TERMS                      |\n");
        printf("| 3.FIBONACCI SERIES                    |\n");
        printf("| 4.POWER OF A NUMBER                   |\n");
        printf("| 5.PRIME OR NOT                        |\n");
        printf("| 6.GCD OF TWO NUMBERS                  |\n");
        printf("| 7.EXIT                                |\n");
        printf("-----------------------------------------\n");
        printf("ENTER YOUR CHOICE : " );
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("ENTER THE NUMBER TO FIND FACTORIAL : ");
                scanf("%d",&num);
                printf("----> FACTORIAL OF %d IS %d \n",num,fact(num));
                break;
            case 2:
                int number,result;
	            printf("ENTER A POSITIVE INTEGER : ");
	            scanf("%d", &number);
	            printf("----> SUM  = %d \n", sum(number));
                break;
            case 3:
                int n = 0;
                printf("ENTER THE NUMBER OF FIBONACCI TERMS :  ");
                scanf("%d",&n);
                printf("----> FIBONACCI SEQUENCE : ");
                for (int i = 0; i < n; i++)
                    printf("%d, ", fibonacci(i));
                printf("\n");     
                break;
            case 4:
                int base=0,exponent=0;
                printf("ENTER THE BASE : ");
                scanf("%d",&base);
                printf("ENTER THE EXPONENT :");
                scanf("%d",&exponent);
                printf("----> The POWER OF BASE %d AND EXPONENT %d IS %d \n",base,exponent,power(base,exponent));
                break;
            case 5:
                int p = 0;
                printf("ENTER THE NUMBER TO FIND PRIME OR NOT :");
                scanf("%d",&p);
                if (isPrime(p))
                    printf("----> IT IS A PRIME NUMBER \n");
                else
                    printf("----> IT IS NOT A PRIME NUMBER \n");
                break;
            case 6:
                int a, b, results;
                printf("ENTER THE TWO NUMBERS TO FIND THEIR GCD : ");
                scanf("%d%d", &a, &b);
                results = gcd(a, b);
                printf("----> The GCD OF %d AND %d IS %d.\n", a, b, results);
                break;
            case 7:
                printf("PROGRAM ENDS .............");
                return 0;
            default:
                printf("INVALID CHOICE \n");
        }
    }
    return 0;
}



