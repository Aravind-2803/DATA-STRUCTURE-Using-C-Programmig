
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int is_operand(char c) 
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c) 
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return 0;
}

void infix_to_postfix(char *infix, char *postfix) 
{
    int i, j = 0;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        if (is_operand(infix[i])) 
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') 
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')') 
        {
            while (stack[top] != '(') 
            {
                postfix[j++] = stack[top--];
            }
            top--;
        } 
        else 
        {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) 
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) 
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int evaluate_postfix(char *postfix) 
{
    int stack[MAX_SIZE];
    int top = -1;
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++) 
    {
        if (isdigit(postfix[i])) 
        {
            stack[++top] = postfix[i] - '0';
        }
        else 
        {
            operand2 = stack[top--];
            operand1 = stack[top--];

            switch (postfix[i]) 
            {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
    }
    return stack[top];
}

int main() 
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s",infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    printf("Result: %d\n", evaluate_postfix(postfix));

    return 0;
}
