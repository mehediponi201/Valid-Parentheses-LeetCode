#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isValid(char* s)
{
    char stack[10000];
    int top = -1;
    for(int i=0; s[i]!='\0'; i++)
    {
        char c = s[i];
        if(c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else
        {
            if(top == -1)
            {
                return false;
            }
            char topchar = stack[top--];
            if(c == ')' && topchar != '(' ||
                    c == ']' && topchar != '[' ||
                    c == '}' && topchar != '{' )
            {
                return false;
            }
        }
    }
    return top == -1;
}
int main()
{
    char str[10000];
    printf("Enter the string:");
    scanf("%s",str);

    if(isValid(str))
    {
        printf("true");
    }
    else
        printf("false");
}
