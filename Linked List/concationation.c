// ROLL:20203035,NAME:RITIK MONDAL,BRANCH:IT,SEMESTER:3RD SEM
#include <stdio.h>
#include <stdlib.h>

struct node1
{
    int data;
    struct node1 *link;
};
struct node1 *root1;

struct node2
{
    int data;
    struct node2 *link;
};
struct node2 *root2;

void append1()
{
    struct node1 *temp;
    temp = (struct node1 *)malloc(sizeof(struct node1));

    printf("Enter node data:");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root1 == NULL)
    {
        root1 = temp;
    }
    else
    {
        struct node1 *p = root1;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void append2()
{
    struct node2 *temp;
    temp = (struct node2 *)malloc(sizeof(struct node2));

    printf("Enter node data:");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root2 == NULL)
    {
        root2 = temp;
    }
    else
    {
        struct node2 *p = root2;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void display1()
{
    struct node1 *temp;
    temp = root1;
    if (temp == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
    }
}
void display2()
{
    struct node2 *temp;
    temp = root2;
    if (temp == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
    }
}

void concatinate()
{
    struct node1 *p = root1;
    struct node2 *q = root2;
    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = (struct node1 *)q;  // pointer p and q are of diffrent data type so we've to typecast it in to struct node1
}

void main()
{
    while (1)
    {
        int ch;
        printf("\n\n1.Append 1st list\n2.Display 1st list\n3.Append 2nd list\n4.Display 2nd list\n5.Concatinate\n6.Display concatinated list(1st list)\n7.Quit\n\n");

        printf("Enter you choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append1();
            break;

        case 2:
            display1();
            break;

        case 3:
            append2();
            break;

        case 4:
            display2();
            break;

        case 5:
            concatinate();
            break;

        case 6:
            display1();
            break;

        case 7:
            exit(1);
        default:
            printf("Invalid Input:)");
        }
    }
}