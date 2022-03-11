// Queue implementation using linked list
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} queue;
queue *front, *rear;

void insert()
{
    queue *New = (queue *)malloc(sizeof(queue));
    printf("Enter element: ");
    scanf("%d", &New->data);
    New->next = NULL;                  
    if (front == NULL && rear == NULL) // this if block  is for insertion of first element.
    {
        front = rear = New;
    }
    else
    {
        rear->next = New;
        rear = New;
    }
}

void traverse()
{

    if (front == NULL)
        printf("**UnderFlow**");
    else
    {
        queue *temp = front;
        printf("Queue Elements:");
        while (temp->next != NULL) // this loop won't print last node so after this loop print last node speretly
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
        printf("\t%d", temp->data);
    }
}

void delete ()
{
    if (front == NULL)
    {
        printf("**UnderFlow**");
    }
    else
    {
        queue *temp = front;
        front = front->next;
        free(temp);
    }
}

void main()
{
    printf("\t:::: Queue implementation using linked list::::");
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

// last edit 14.12.2021