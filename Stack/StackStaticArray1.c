//Stack Operations using Static Array

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int stack[CAPACITY], top = -1;

int isFull()
{
    if (top == CAPACITY - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push()
{
    int item;

    if (isFull())
        printf("Stack Overflow\n");
    else
    {
        printf("Enter stack element: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d is inserted successfully!", item);
    }
}

void pop()
{
    if (isEmpty())
    {

        printf("Stack UnderFlow!");
    }
    else
    {
        printf("Element Poped: %d", stack[top]);
        top--;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Peek element : %d", stack[top]);
    }
}

void traverse()
{
    if (isEmpty())
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n______________________________________________________________________________________________");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Traverse/Display\n5.Size\n6.Quit\n");
        printf("______________________________________________________________________________________________");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Size of stack: %d", top + 1);
            break;
        case 6:
            exit(0);

        default:
            printf("Invalid Input\n");
        }
    }
}