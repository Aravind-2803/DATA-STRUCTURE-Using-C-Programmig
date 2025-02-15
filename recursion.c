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
	
	if (n != 0)
		return n + sum(n-1); 
	else
		return n;
	
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
    printf("5.EXIT\n");
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
	          result = sum(number);
	          printf("   *   SUM  = %d \n", result);
                  break;
      case 3:
                  break;
      case 4:
                  break;
      case 5:
                  return 0;
      default:
                  printf("Invalid Choice \n");
    }
  }

}
