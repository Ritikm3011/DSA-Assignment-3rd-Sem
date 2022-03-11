// AVL Tree
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
struct Node *root = NULL;

int max(int a, int b);

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
	struct Node *node = (struct Node *)
		malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{

	if (node == NULL)
		return (newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left),
						   height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct Node *minValueNode(struct Node *node)
{
	struct Node *current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

struct Node *deleteNode(struct Node *root, int key)
{

	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{

		if ((root->left == NULL) || (root->right == NULL))
		{
			struct Node *temp = root->left ? root->left : root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			free(temp);
		}
		else
		{

			struct Node *temp = minValueNode(root->right);

			root->key = temp->key;

			root->right = deleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(height(root->left),
						   height(root->right));

	int balance = getBalance(root);

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preOrder(struct Node *root)
{
	if (root != NULL)
	{
		printf("\t%d", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postorder(struct Node *root)
{

	if (root == NULL)
		return;
	else
	{

		postorder(root->left);
		postorder(root->right);
		printf("\t%d", root->key);
	}
}

void inorder(struct Node *root)
{

	if (root == NULL)
		return;
	else
	{

		inorder(root->left);
		printf("\t%d", root->key);
		inorder(root->right);
	}
}

void main()
{
	printf("\t**AVL Tree**");
	int ch;
	int val;
	int vala;
	int item;
	while (1)
	{
		printf("\n__________________________________________________________________________________________");
		printf("\n1.Create\n2.Add Node\n3.Preorder traversal\n4.Postorder traversal\n5.Inorder traversal\n6.Delete\n7.Exit\n");
		printf("\n__________________________________________________________________________________________");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			int n;
			printf("Enter number of node: ");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				printf("Enter data: ");
				scanf("%d", &val);
				root = insert(root, val);
			}

			break;

		case 2:

			printf("Enter data: ");
			scanf("%d", &vala);
			root = insert(root, vala);
			break;

		case 3:
			printf("Preorder traversal: ");
			preOrder(root);
			break;

		case 4:
			printf("Postorder traversal: ");
			postorder(root);
			break;

		case 5:
			printf("Inorder traversal: ");
			inorder(root);
			break;

		case 6:

			printf("Enter item: ");
			scanf("%d", &item);
			// Node *deleteNode(Node *root, int data)
			printf("\nDeleted item: %d\n", item);
			root = deleteNode(root, item);
			// root = deleteNode(root, 10);
			printf("Inorder traversal of the modified tree: ");
			inorder(root);
			break;

		case 7:
			exit(1);
			break;

		default:
			printf("Invalid Input");
		}
	}
}

// last edit:18.02.2022     by Ritik_Mondal