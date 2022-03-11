// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *left, *right;
} Node;

Node *root = NULL;

Node *newNode(int val)
{
    Node *New = (Node *)malloc(sizeof(Node));
    New->data = val;
    New->left = New->right = NULL;
    return New;
}

Node *insertion(Node *ROOT, int val)
{
    if (ROOT == NULL)
        return newNode(val);

    else if (ROOT->data > val)
        ROOT->left = insertion(ROOT->left, val);

    else if (ROOT->data < val)
        ROOT->right = insertion(ROOT->right, val);

    return ROOT;
}

void createBST()
{

    int val;
    printf("Enter BST Node data: ");
    scanf("%d", &val);

    if (root == NULL)
        root = insertion(root, val);

    else
        insertion(root, val);
}
void inorder(Node *root)
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

void postorder(Node *root)
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

void preorder(Node *root)
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
// Deleting the node

Node *minValueNode(Node *node)
{
    Node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int data)
{

    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void main()
{
    printf("***Binary Search Tree***");
    int ch;
    while (1)
    {
        printf("\n__________________________________________________________________________________________");
        printf("\n1.Create\n2.Add Node\n3.Delete Node\n4.In-order\n5.Post-order\n6.Pre-order\n7.Exit\n");
        printf("__________________________________________________________________________________________");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            int n;
            printf("Enter number of node: ");
            scanf("%d",&n);
            for(int i=0; i<n; i++) {
                 createBST();
            }

           
            break;
        case 2:

            createBST();
            break;
        case 3:
            int item = 0;
            printf("Enter item: ");
            scanf("%d", &item);
            // Node *deleteNode(Node *root, int data)
            printf("\nDeleted item: %d\n", item);
            root = deleteNode(root, item);
            printf("Inorder traversal of the modified tree: ");
            inorder(root);
            break;

        case 4:
            printf("In-order: ");
            inorder(root);
            break;

        case 5:
            printf("Post-order: ");
            postorder(root);
            break;

        case 6:
            printf("Pre-order: ");
            preorder(root);
            break;

        case 7:
            exit(1);

        default:
            printf("Invalid input");
        }
    }
}
// last edit:18.02.2022      by Ritik_Mondal(20203035)