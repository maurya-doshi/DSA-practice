#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct
{
    int items[MAX];
    int top;
} stack;

void create (stack *s)
{
    s->top = -1;
}

int isFull (stack *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty (stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push (stack *s, int n)
{
    if (isFull(s))
    {
        printf("Stack full\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = n;
        printf("%d added\n", s->items[s->top]);
    }
}

void pop (stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d removed\n", s->items[s->top]);
        s->top--;
    }
}

void peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("%d\n", s->items[s->top]);
    }
}


void print (stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack empty\n");
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    stack st;
    create(&st);

    pop(&st);
    push(&st, 1);
    push(&st, 2);
    pop(&st);
    push(&st, 3);
    push(&st, 4);
    peek(&st);
    push(&st, 5);
    print(&st);

    return 0;
}