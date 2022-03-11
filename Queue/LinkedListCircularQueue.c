// Circular Queue implementation using Linked List
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} Cqueue;

Cqueue *front = NULL;
Cqueue *rear = NULL;

void insert()
{
    Cqueue *newNode = (Cqueue *)malloc(sizeof(Cqueue));
    printf("Enter node: ");
    scanf("%d", &newNode->data);
    // node creation done but i didn't do anything with newNode->next yet
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        rear->next = front; // this line is for making it circular
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void delete ()
{
    Cqueue *temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("**UnderFlow**");
    }
    else if (rear == front) // if only one node is leave
    {
        printf("Node deleted: %d", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("Node deleted: %d", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{

    if (rear == NULL)
    {
        printf("**UnderFlow**");
    }
    else
    {
        Cqueue *temp = front;
        printf("Queue elements: ");
        while (temp->next != front)
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        }
        printf("\t%d", temp->data);
    }
}
void main()
{
    printf("\t::::Circular Queue implementation using Linked List::::");
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
            display();
            break;

        case 4:
            exit(1);

        default:
            printf("Invalid Input!");
        }
    }
}

// last edit 15.12.2021