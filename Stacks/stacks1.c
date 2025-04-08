#include <stdio.h>
#include <string.h>

char word[100];

typedef struct
{
    char letters[100];
    int top;
} stack;

void create(stack *s)
{
    s->top = -1;
}

void read()
{
    do
    {
        printf("Enter word: ");
        fgets(word, 100, stdin);

        size_t len = strlen(word);
        if (len > 0 && word[len - 1] == '\n')
        {
            word[len - 1] = '\0';
        }
    } 
    while (strlen(word) == 0);
}

void stackLetters(stack *s, char c)
{
    s->top++;
    s->letters[s->top] = c;
}

void printReverse(stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->letters[i]);
    }
    printf("\n");
}

int main()
{
    stack st;
    create(&st);

    read();
    for (int i = 0; i < strlen(word); i++)
    {
        stackLetters(&st, word[i]);
    }

    printf("Reversed word: \n");
    printReverse(&st);
}