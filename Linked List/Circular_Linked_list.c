#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void last_insert()
{
    struct node *new_Node, *temp;
    new_Node = (struct node *)malloc(sizeof(struct node));
    temp = head;

    printf("Enter node data: ");
    scanf("%d", &new_Node->data);
    // new_Node->next = head;
    if (head == NULL)
    {
        head = new_Node;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_Node;
    }
    new_Node->next = head;
}

void create()
{
    int n;
    printf("Number of nodes you want to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        last_insert();
    }
}

void display()
{
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    // this while loop won't be printing last node so next line of code is to print last node
    printf("%d\n", temp->data);
}

void beg_insert()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head; // I am going to use temp for traversal/to reach last node
    printf("Enter node data: ");
    scanf("%d", &newNode->data);
    newNode->next = head; // it is first node if this if block excequte so first node has to link with it self to make it circular.

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next; // traversing
        }
        temp->next = newNode;
        temp = newNode;
    }
}

void delete ()
{
    struct node *temp;
    int location;
    length();
    printf("Enter location to delete: ");
    scanf("%d", &location);
    // if (location > len)
    // {
    //     printf("Invalid location!");
    // }
    if (location == 1) // if you want to delete 1st node
    {
        temp = head;
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else // to delete node at all location except 1st and last
    {
        struct node *p = head, *q;
        for (int i = 1; i < location - 1; i++)
        {
            p = p->next;
        }
        q = p->next; // we want to delete this one
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
    printf("Node at loation %d deleted successfully.", location);
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n\n1.Create circular linked list\n2.Display\n3.Insertion at beginning\n4.Insertion at End");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            beg_insert();
            break;
        case 4:
            last_insert();
            break;

        default:
            printf("Invalide choice!");
        }
    }
}