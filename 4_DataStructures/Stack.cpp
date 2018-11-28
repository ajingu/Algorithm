#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = 0;
int S[200];
const int MAX = 200;

void push(int x)
{
    top++;
    S[top] = x;
}

int pop()
{
    top--;
    return S[top+1];
}

int main()
{
    int a, b;
    char ch[100];

    while(scanf("%s", ch) != EOF)
    {
        switch(ch[0])
        {
            case '+':
                a = pop();
                b = pop();
                push(b+a);
                break;
            case '-':
                a = pop();
                b = pop();
                push(b-a);
                break;
            case '*':
                a = pop();
                b = pop();
                push(b*a);
                break;
            default:
                push(atoi(ch));
                break;
        }
    }

    printf("%d\n", pop());

    return 0;
}