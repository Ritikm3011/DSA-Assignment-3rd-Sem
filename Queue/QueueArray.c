// Queue implementation using Static Array
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int queue[CAPACITY];
int front = 0, rear = 0;

void insert()
{
    if (rear == CAPACITY)
    {
        printf("queue is Full!");
    }
    else
    {
        int element;
        printf("Enter element: ");
        scanf("%d", &queue[rear]);
        rear++; // in the end when queue will be full the value of rear = CAPACITY but last index of queue is CAPACITY-1
    }
}



void delete () // use this if you want to make your code more time efficent but you can't use space which deteled
{
    if (front == 0 && rear == 0)
    {
        printf("queue is Empty!");
    }

    else if (front == rear)
    {
        // front = 0;
        // rear = 0;
        printf("queue is Empty!");
    }
    else
    {
        printf("deleted element: %d", queue[front]);
        front++; // moving fornt to next index
    }
}

void traverse()
{
    if (front == rear)
        printf("queue is Empty!");

    else
    {
        printf("queue elements are:\t");
        for (int i = front; i < rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}

void main()
{
    printf("\t::::Queue implementation using Static Array::::");
    int ch;

    while (1)
    {
        printf("\n__________________________________________________________________________________________");
        printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Quit\n");
        printf("__________________________________________________________________________________________");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            traverse();
            break;

        case 4:
            exit(1);

        default:
            printf("Invalid Input!");
        }
    }
}

// Last edit 11.12.2021 by Ritik Mondal