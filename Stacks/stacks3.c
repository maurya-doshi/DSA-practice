#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int nums[MAX];
    int top;
} stack;

void create(stack *s)
{
    s->top = -1;
}

void push(stack *s, int n)
{
    s->top++;
    s->nums[s->top] = n;
}

void pop(stack *s)
{
    s->top--;
}

int main()
{
    stack s;
    create(&s);

    char line[100];
    printf("Enter expression: ");
    fgets(line, 100, stdin);

    int i = 0;
    int len = strlen(line);
    while (i < len)
    {
        if (isspace(line[i]))
        {
            i++;
            continue;
        }

        if (isdigit(line[i]))
        {
            int num = 0;
            while (i < strlen(line) && isdigit(line[i]))
            {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            push(&s, num);
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
        {
            if (s.top < 1)
            {
                printf("Not enough numbers in stack\n");
                break;
            }
            
            int a = s.nums[s.top];
            pop(&s);
            int b = s.nums[s.top];
            pop(&s);

            if (line[i] == '+')
            {
                push(&s, b + a);
            }
            else if (line[i] == '-')
            {
                push(&s, b - a);
            }
            else if (line[i] == '*')
            {
                push(&s, b * a);
            }
            else if (line[i] == '/')
            {
                if (a == 0)
                {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                push(&s, b / a);
            }
            i++;
        }
        else
        {
            printf("Ignoring invalid character: %c\n", line[i]);
            i++;
        }
    }

    if (s.top == 0)
    {
        printf("Result: %d\n", s.nums[s.top]);
    }
    else
    {
        printf("Invalid expression\n");
    }
    
    return 0;
}
