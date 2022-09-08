#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int *S;
    int top;
};

void create(struct Stack *st)
{
    printf("\nEnter size :");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int a)
{
    //int x = 0;
    if (st->top == st->size - 1)
    {
        printf("\nStack is overflow");
    }
    else
    {
        st->top++;
        st->S[st->top] = a;
    }
}

void pop(struct Stack *st)
{
    if (st->top == -1)
    {
        printf("\nStack is underflow ");
    }
    else
    {
        st->S[st->top--];
    }
}

int peek(struct Stack *st, int position)
{
    int x = 0;
    if (st->S[st->top - position + 1])
    {
        printf("\nInvalid input try again");
    }

    else
    {
        x = st->S[st->top - position + 1];
        return x;
    }
}

void stackTop(struct Stack *st)
{
    printf("\nTop most value in the stack is %d", st->S[st->top]);
}

void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("\n%d", st.S[i]);
    }
}

int main()
{
    struct Stack st;
    int c;
    int n;
    int a, b, f, g;
    char e;

    // Create
    create(&st);

    // Menu driven program

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.peep\n4.stacktop\n5.display");
        printf("\nEnter your choice :");
        scanf("%d", &c);
        // int f = 1;
        switch (c)
        {
        case 1:
            for (int i = 0; i < st.size; i++)
            {
                printf("\nEnter your number :");
                scanf("%d", &a);
                push(&st, a);
            }

            break;

        case 2:
            printf("\nHow many numbers do you want to pop :");
            scanf("%d", &f);
            for (int i = 0; i < f; i++)
            {
                pop(&st);
            }
            break;

        case 3:
            printf("\nEnter position in to get the value at that position :");
            scanf("%d", &g);
            peek(&st, g);
            break;

        case 4:
            stackTop(&st);

        case 5:
            display(st);
            break;

        default:
            break;
        }

        printf("\nDo you want to perform more operation ? y/n ");
        scanf(" %c", &e);
        if (e == 'y')
        {
            continue;
        }
        else
            break;
    }
}