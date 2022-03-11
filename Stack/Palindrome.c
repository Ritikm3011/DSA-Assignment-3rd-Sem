// Check String is Palindrome using Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 10

char stack[CAP];
char str[CAP];
int top = -1, front = 0;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == CAP - 1)
        return 1;

    else
        return 0;
}

void push(char item)
{

    if (isFull())
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (isEmpty())
    {

        printf("Stack UnderFlow!\n");
    }
    else
    {
        top--;
    }
}

void isPalindrome()
{
    printf("Enter a string: ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    for (int i = 0; i < (strlen(str) / 2); i++)
    {
        if (stack[front] == stack[top])
        {
            pop();
            front++;
        }
        else
        {
            printf("%s is not a palindrome\n", str);
            break;
        }
    }
    if ((strlen(str) / 2) == front)
    {
        printf("%s is palindrome", str);
    }
    front = 0;
    top = -1;
}
void main()
{

    int ch;

    while (1)
    {
        printf("\n\n1.Is Palindrome \n2.Exit\nEnter Your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            isPalindrome();
            break;

        case 2:
            exit(0);
        default:
            printf("Invalid choice!");
        }
    }
}
// last edit: 04.01.2022       by Ritik_Mondal