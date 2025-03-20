#include<stdio.h>
#include<ctype.h>
#define MAX 100
int eval(char*exp,char*stack,int *top);
int push(int val,char*stack,int *top);
int pop(char*stack,int *top);
int main()
   {
      char exp[MAX];
      char stack[MAX];
      int top = -1;
      printf("Enter the Expression To Evaluate : ");
      scanf("%c",exp);
      eval(exp,stack,&top);
   }
int eval(char*exp,char*stack, int *top)
   {
        for(int i=0;exp[i]!='\0';i++)
        {
          if(isdigit(exp[i]))
              push(exp[i],stack,&(*top));
          else
              {
                int val;
                int val1=pop(stack,&(*top));
                int val2=pop(stack,&(*top));
              switch(exp[i])
                {
                  case '+':
                    val = val1+val2;
                    push(val,stack,&(*top));
                  case '-':
                    val = val2-val1;
                    push(val,stack,&(*top));
                  case '*':
                    val = val2*val1;
                    push(val,stack,&(*top));
                  case '/':
                    val = val2/val1;
                    push(val,stack,&(*top));
                  default:
                    printf("invalid");
                }
               }
              }
     return pop(stack,&(*top));
   }
int push(int val,char *stack,int *top) 

   {
     if(*top>=MAX-1)
        printf("overflow");
     stack[++(*top)]=val;
   }
int pop(char*stack, int *top)
   {
     if((*top)<0)
        printf("underflow");
     else
     	printf("%d",stack[*top]);
     	return stack[*top--];
   }
