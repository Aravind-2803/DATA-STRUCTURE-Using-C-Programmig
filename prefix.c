#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isclose(char c)
{
if(c == ')' || c == '}' || c == ']' )
{
return true;
}
else
{
return false;
}
}
bool isopen(char c)
{
if(c == '(' || c == '{' || c == '[' )

    return true;

else

    return false;

}

bool isfull(char s[],int *top,int max)
{
if(*top == max-1)
    return false;
else
    return true;
}

bool isempty(char s[],int *top)
{
if(*top == -1)
    return false;
else
    return true;
}

void push(char s[],int *top,int max,int x)
{
if(isfull(s,top,max))
{
(*top)++;
s[*top] = x;
}

}

char pop(char s[],int *top,int max)
{
if(isempty(s,top))
{
char temp = s[*top];
(*top)--;
return temp;
}
}

char peektop(char s[],int *top)
{
if(isempty(s,top))
{
return s[*top];
}
}



int ins(char e)
{
if(e == '$')
{
return 4;
}
else if (e == '*' || e == '/')
{
return 3;
}
else if (e == '+' || e == '-')
{
return 2;
}
else if (e == ')')
{
return 0;
}
}

int ico(char e)
{
if(e == '$')
{
return 5;
}
else if (e == '*' || e == '/')
{
return 3;
}
else if (e == '+' || e == '-')
{
return 2;
}
else if (e == ')')
{
return 5;
}
else if (e == '(')
{
return 1;
}
}

bool pre(char f, char d)
{
if(ins(f) > ico(d))
{
return true;
}
else
{
return false;
}
}

void res(char s[],char r[])
{
char sta[100];
int k = 0;
int top = -1;
char sym;
int max = 99;
for(int i = strlen(s)-1 ; i >= 0 ; i--)
{
if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
{
r[k] = s[i];
k++;
}
else
{
while(isempty(sta,&top) && !(isclose(peektop(sta,&top))) && pre(peektop(sta,&top),s[i]))
{
sym = pop(sta,&top,max);
r[k] = sym;
k++;
}

if(!(isopen(s[i])))
{
push(sta,&top,max,s[i]);
}
else
{
sym = pop(sta,&top,max);
}
}
}
while(isempty(sta,&top))
{
sym = pop(sta,&top,max);
r[k] = sym;
k++;
}
}

int main()
{
char s[100];
printf("enter the string");
scanf("%s",s);
char r[100];
res(s,r);
int k = strlen(r);
for(int i = k-1 ; i>=0 ; i--)
{
printf("%c",r[i]);
}


}
