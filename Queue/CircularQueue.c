// Circular Queue implementation using Static Array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int Cqueue[SIZE];
int front = -1;
int rear = -1;

void insert()
{

    if ((rear + 1) % SIZE == front)
    {
        printf("**OverFlow**");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("Enter element: ");
        scanf("%d", &Cqueue[rear]);
    }
    else
    {
        rear = (rear + 1) % SIZE; // increment for circular queue
        printf("Enter element: ");
        scanf("%d", &Cqueue[rear]);
    }
}

void delete ()
{
    if (front == -1 && rear == -1)
    {
        printf("**UnderFlow**");
    }
    else if (front == rear)
    {
        printf("Deleted Cqueue element: %d", Cqueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted Cqueue element: %d", Cqueue[front]);
        front = (front + 1) % SIZE;
    }
}

void traverse()
{
    if(front =-1 && rear== -1 )
    printf("**UnderFlow**");

    else
    {
        int i = front;
        printf("Circular Queue Elements:");
        while(i != rear)
        {
            printf("\t%d",Cqueue[i]);
            i = (i+1)%SIZE;
        }
    }
}

void main()
{
    printf("\t::::Circular Queue implementation using Static Array::::");
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


// Last edit 12.12.2021 by Ritik Mondal