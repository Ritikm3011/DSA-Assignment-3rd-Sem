#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int len = 0;

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    // giving input
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    // if list is emply(making 1st node)
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
            p = p->link; // to move on next node(Traverse)
        }
        p->link = temp;
    }
}
int length()
{
    len = 0;
    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        len++;
        temp = temp->link;
    }
    //printf("Length:%d\n\n\n", len);
    return len;
}

void insert()
{
    struct node *temp, *p;
    int loc;
    printf("Enter the location after which you want to insert: ");
    scanf("%d", &loc);
    length(); // this function will provide length of linked list in form of variable len
    //printf("Length:%d",len);
    if (loc > len)
    {
        printf("Invalid Location!\nCurrently list is having only %d nodes", len);
    }
    else
    {
        p = root;
        for(int i = 1;i < loc;i++)
        {
            p = p->link;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        //right connection first then left connection
        temp->link = p->link;
        p->link = temp;
        printf("Inserted successfully");
    }
}
void display()
{
    struct node *temp;
    temp = root;
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

void delete ()
{
    struct node *temp;
    int location;
    length();
    printf("Enter location to delete: ");
    scanf("%d", &location);
    if (location > len)
    {
        printf("Invalid location!");
    }
    else if (location == 1) // if you want to delete 1st node
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else // to delete node at all location except 1st
    {
        struct node *p = root, *q;
        for (int i = 1; i < location - 1; i++)
        {
            p = p->link;
        }
        q = p->link; // we want to delete this one
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    printf("Node at loation %d deleted successfully.",location);
}

void reverse()
{
    int i, j, k, temp;
    struct node *p, *q;
    p = q = root;
    length(); // This will provide a variable called len from length function

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        k = 0;
        for (k = 0; k < j; k++)
        {
            q = q->link;
        }
        // swapping using 3rd variable
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = p->link;
        q = root;
    }
    printf("Successfully Reversed");
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n\n1.Append\n2.Addatbegin\n3.Insert\n4.Length\n5.Display\n6.Delete\n7.Reverse Linked_list\n8.Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();
            break;

        case 3:
            insert();
            break;

        case 4:
            length();
            printf("Length:%d\n\n\n", len);
            break;

        case 5:
            display();
            break;
        case 6:
            delete ();
            break;

        case 7:
            reverse();
            break;

        case 8:
            exit(1);
        default:
            printf("Invalid Input:)");
        }
    }
}