#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char items[MAX];
    int top;
} stack;

void create(stack *s)
{
    s->top = -1;
}

void push(stack *s, char c)
{
    s->top++;
    s->items[s->top] = c;
}

void pop(stack *s)
{
    s->top--;
}

int main()
{
    char str[100];
    stack s;
    bool flag = true;
    int i;
    char error, expected;

    create(&s);

    printf("Enter string: ");
    fgets(str, 100, stdin);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(&s, str[i]);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (s.top == -1)
            {
                flag = false;
                break;
            }

            if ((str[i] == '}' && s.items[s.top] == '{') ||
                (str[i] == ')' && s.items[s.top] == '(') ||
                (str[i] == ']' && s.items[s.top] == '['))
            {
                pop(&s);
            }
            else
            {
                error = str[i];
                if (s.items[s.top] == '{')
                {
                    expected = '}';
                }
                else if (s.items[s.top] == '(')
                {
                    expected = ')';
                }
                else
                {
                    expected = ']';
                }
                flag = false;
                break;
            }
        }
    }

    if (flag && s.top == -1)
    {
        printf("All opening brackets have a corresponding closing bracket\n");
    }
    else if (!flag)
    {
        printf("Error at character %d, expected '%c' but found '%c'\n", (i + 1), expected, error);
    }
    else
    {
        if (s.items[s.top] == '{')
        {
            expected = '}';
        }
        else if (s.items[s.top] == '(')
        {
            expected = ')';
        }
        else
        {
            expected = ']';
        }
        printf("Error at end of input, expected '%c' but found end of string\n", expected);
    }


    return 0;
}
