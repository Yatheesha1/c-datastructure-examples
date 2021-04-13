#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head;

void createNode(int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        if (i == 0)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = value;
            head->next = NULL;
            temp = head;
        }
        else
        { /* code */
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
    }
}
int getNodeLength(struct Node *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
        /* code */
    }
    return count;
}

struct Node *insertNode(struct Node *node, int position, int value)
{
    int nodelength = getNodeLength(node);
    if (position < 0 || position > nodelength)
    {
        printf("Unable find location");
        if (!node)
            printf(" your Node is empty.");
        return node;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (position == 0)
    {
        temp->data = value;
        temp->next = node;
        node = temp;
    }
    else
    {
        temp = node;
        int pos = position;
        position--;
        while (position--)
        {
            temp = temp->next;
        }
        if (pos == nodelength)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
        else
        {
            struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
            temp2->next = temp->next;
            temp2->data = value;
            temp->next = temp2;
        }
    }
    printf("Item inserted to node.");
    return node;
}

void getNodeDetails(struct Node *node)
{
    if (node)
    {
        printf(">>>Node Length: %d\n", getNodeLength(node));
        printf(">>>Node elements: ");
    }
    else
        printf(">>>Node is empty");

    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
        /* code */
    }
    printf("\n");
}
struct Node *removeNode(struct Node *node, int index)
{
    if (node)
    {
        int nodeLength = getNodeLength(node);
        if (index < 0 || index > nodeLength - 1)
        {
            printf("Unable to find location");
        }
        else
        {
            if (index == 0)
            {
                node = node->next;
            }
            else if (index == nodeLength - 1)
            {
                struct Node *temp = node;
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
                free(temp->next);
            }
            else
            {
                struct Node *temp2 = node;
                index--;
                while (index--)
                {
                    temp2 = temp2->next;
                }
                struct Node *temp1 = temp2->next->next;
                temp2->next = temp1;
            }
            printf("Item removed from node.");
        }
    }
    else
    {
        printf("Node is empty.");
    }
    return node;
};

int main()
{
    char *ch[] = {"Exit", "Create", "Insert", "Remove", "Node details"};
    while (1)
    {
        int menu, n, index, value;
        printf("\n==========\nMenus\n==========\n0. Exit\n1. Create\n2. Insert\n3. Remove\n4. Node details\n\nEnter your input: ");
        scanf("%d", &menu);
        printf(">>>You selected %s\n", ch[menu]);
        switch (menu)
        {
        case 0:
            printf("Thank you.\n");
            exit(0);
            break;
        case 1:
            // int n;
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter %d values of node: ", n);
            createNode(n);
            break;

        case 2:
            // int index, value;
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter values: ");
            scanf("%d", &value);
            head = insertNode(head, index, value);
            break;
        case 3:
            printf("Enter index: ");
            scanf("%d", &index);
            head = removeNode(head, index);
            break;
        case 4:
            getNodeDetails(head);
            break;

        default:
            printf("Invalid input please try again.\n");
            break;
        }
    }
    return 0;
}