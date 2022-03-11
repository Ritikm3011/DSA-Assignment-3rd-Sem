#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;
node *root = NULL;

node *create()
{
    struct node *newnode = (node *)malloc(sizeof(node));
    int x, choice;

    printf("Enter Node Data, or Enter 0 to exit:  ");
    scanf("%d", &x);
    if (x == 0)
        return NULL;
    newnode->data = x;
    printf("\nLeft child of %d-->", x);
    newnode->left = create();

    printf("\nRight child of %d-->", x);
    newnode->right = create();

    return newnode;
}

void preorder(node *root)
{

    if (root == NULL)
        return;
    else
    {
        printf("\t%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{

    if (root == NULL)
        return;
    else
    {

        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->data);
    }
}

void inorder(node *root)
{

    if (root == NULL)
        return;
    else
    {

        inorder(root->left);
        printf("\t%d", root->data);
        inorder(root->right);
    }
}

void main()
{
    printf("\t**Binary Tree**\n");
    int choice;
    while (1)
    {
        printf("\n__________________________________________________________________________________________");
        printf("\n1.Create BT\n2.Traversal through Preorder\n3.Traversal through Inorder\n4.Traversal through Postorder\n5.Exit\n");
        printf("\n__________________________________________________________________________________________");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = create();
            break;

        case 2:
            printf("Pre-order: ");
            preorder(root);
            break;
        case 3:
            printf("In-order: ");
            inorder(root);

            break;
        case 4:
            printf("Post-order: ");
            postorder(root);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("invalid input");
        }
    }
}

// last edit:11.02.2022     by Ritik_Mondal