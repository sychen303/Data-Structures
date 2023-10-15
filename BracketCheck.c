#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 100

char stack[ms];
int top = -1;

void push(char a)
{
    top++;
    stack[top] == a;
}

void pop()
{
    char s;
    s = stack[top];
    top--;
}

int isempty(){
    if(top == -1)
        return 1;    
}

int main()
{
    char s[100];
    gets(s);
    int l;
    l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (((s[i] == '(') || (s[i] == '{')) || (s[i] == '['))
        {
            push(s[i]);
        }
        if (s[i] == ')')
        {
            if (stack[top] == '(')
            {
                pop();
            }
            else{
                push(s[i]);
            }
        }
        if (s[i] == ']')
        {
            if (stack[top] == '[')
            {
                pop();
            }
            else{
                push(s[i]);
            }
        }
        if (s[i] == '}')
        {
            if (stack[top] == '{')
            {
                pop();
            }
            else{
                push(s[i]);
            }
        }
    }
    if (isempty())
    {
        printf("Balanced");
    }
    else {
        printf("Unbalanced");
    }
}