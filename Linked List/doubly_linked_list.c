#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root;
int count = 0;

void append()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data:");
    scanf("%d", &temp->data);
    temp->right = NULL;
    temp->left = NULL;
    // till now creation of node is done

    if (root == NULL) // this if block will execute when it is first node
    {
        root = temp;
    }

    else
    {
        struct node *p = root;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        p->left = p;
    }
}

void addatbegin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data:");
    scanf("%d", &temp->data);
    temp->right = NULL;
    temp->left = NULL;
    // ceation of node is done

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

int lenght()
{
    struct node *temp = root;

    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

void insert()
{
    struct node *temp, *p;
    int loc;
    printf("Enter location after which you want to insert: ");
    scanf("%d", &loc);
    lenght(); // it will provide count variable
    if (loc > count)
    {
        printf("Invalid location!\nCurrently list is having only %d node", count);
    }
    else
    {
        p = root;
        for (int i = 1; i < loc; i++)
        {
            p = p->right;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->right = NULL;
        temp->left = NULL;
        // till here creation on new node is done
        //right side connection first
        temp->right = p->right;
        p->right->left = temp;
        //left side conncetion
        temp->left = p;
        p->right = temp;
    }
}

void display()
{
    struct node *temp = root;
    if (temp == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d<=>", temp->data);
            temp = temp->right;
        }
    }
}

void delete ()
{
    lenght();
    struct node *temp;
    int location;
    printf("Enter Location: ");
    scanf("%d", &location);

    if (location > count)
        printf("Invalid Location\nList have only %d node", count);
    else if (location == 1)
    {
        temp = root;
        root = temp->right;
        root->left = NULL;
        free(temp);
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n\n1.Append\n2.Add at Beginning\n3.Length\n4.Display\n5.Insert\n6.Delete\n8.Exit\n\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();
            break;

        case 2:
            addatbegin();
            break;

        case 3:
            lenght();
            printf("Length:%d\n\n", count);
            break;

        case 4:
            display();
            break;

        case 5:
            insert();
            break;

        case 6:
            delete ();
            break;

        case 8:
            exit(1);
            break;

        default:
            printf("Invalid Input:)");
        }
    }
}