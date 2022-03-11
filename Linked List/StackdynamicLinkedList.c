// Stack implementation using Single Linked List(last in first out)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
int len = 0;

void push()
{
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &new_Node->data);
    new_Node->link = top;
    top = new_Node;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!");
    }
    else
    {
        struct node *temp = top;
        printf("Poped element:%d\n", top->data);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void traverse()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("\n");
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("\t%d\n", temp->data);
            temp = temp->link;
        }
    }
}

int size()
{
    len = 0;
    struct node *temp = top;
    while (temp != NULL)
    {
        len++;
        temp = temp->link;
    }
    return len;
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n_________________________________________________________________________________");
        printf("\n\n1.Push\n2.pop\n3.Display/Traverse\n4.size\n0.Exit\n");
        printf("\n_________________________________________________________________________________");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            // case 1:
            //     // create();
            //     // break;

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            traverse();
            break;

        case 4:
            size();
            printf("size of stack is: %d\n", len);
            break;

        case 0:
            exit(1);

        default:
            printf("Invalid choice!");
        }
    }
}


//Last edit 09122021