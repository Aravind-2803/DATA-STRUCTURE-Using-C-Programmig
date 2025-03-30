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

void infix_to_prefix(char *infix, char *prefix) 
{
    int i, j = 0;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = strlen(infix) - 1; i >= 0; i--) 
    {
        if (is_operand(infix[i])) 
            prefix[j++] = infix[i];
        else if (infix[i] == ')') 
            stack[++top] = infix[i];
        else if (infix[i] == '(') 
        {
            while (stack[top] != ')') 
            {
                prefix[j++] = stack[top--];
            }
            top--;
        }
        else 
        {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) 
            {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) 
    {
        prefix[j++] = stack[top--];
    }
    prefix[j] = '\0';

    int start = 0, end = strlen(prefix) - 1;
    while (start < end) 
    {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}
int evaluate_prefix(char *prefix) 
{
    int stack[MAX_SIZE];
    int top = -1;
    int i, operand1, operand2;

    for (i = strlen(prefix) - 1; i >= 0; i--) 
    {
        if (isdigit(prefix[i])) 
        {
            stack[++top] = prefix[i] - '0';
        }
        else 
        {
            operand1 = stack[top--];
            operand2 = stack[top--];

            switch (prefix[i]) 
            {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand2 - operand1;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand2 / operand1;
                    break;
            }
        }
    }
    return stack[top];
}

int main() 
{
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s",infix);
    infix_to_prefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    printf("Result: %d\n", evaluate_prefix(prefix));

    return 0;
}
