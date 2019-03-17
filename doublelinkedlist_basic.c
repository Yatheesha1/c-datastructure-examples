#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} * head;

struct Node *createNode(int);
void getNodeDetails(struct Node *);
int getNodeLength(struct Node *);
struct Node *insertNode(struct Node *, int, int);
struct Node *removeNode(struct Node *, int);

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
            head = createNode(n);
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
int hasNode(struct Node *node)
{
    if (node)
    {
        return 1;
    }
    else
    {
        printf(">>>Node is null\n");
        return 0;
    }
}
int getNodeLength(struct Node *node)
{
    int count = 0;
    while (node)
    {
        node = node->next;
        count++;
    }
    return count;
}
struct Node *createNode(int n)
{
    struct Node *node = NULL;
    if (n <= 0)
    {
        printf("Length should be >0");
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        for (int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            if (i == 0)
            {
                node = (struct Node *)malloc(sizeof(struct Node));
                node->data = value;
                node->next = NULL;
                node->prev = NULL;
                temp = node;
            }
            else
            {
                temp->next = (struct Node *)malloc(sizeof(struct Node));
                temp->next->prev = temp;
                temp = temp->next;
                temp->data = value;
                temp->next = NULL;
            }
        }
    }
    return node;
}

void getNodeDetails(struct Node *node)
{
    if (node)
    {
        printf(">>>Node Length: %d\n", getNodeLength(node));
        printf(">>>Node elements: ");
        while (node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
    else
    {
        printf(">>>Node is empty");
    }
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
        if (node)
        {
            node->prev = temp;
            temp->next = node;
        }
        else
        {
            temp->next = NULL;
        }

        temp->prev = NULL;
        node = temp;
    }
    else
    {
        temp = node;
        int index = position;
        position--;
        while (position--)
        {
            temp = temp->next;
        }
        if (index == nodelength)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp->next->prev = temp;
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
        else
        {
            struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
            temp2->prev = temp;
            temp2->next = temp->next;
            temp2->data = value;
            temp->next = temp2;
        }
    }
    printf("Item inserted to node.");
    return node;
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
                node->prev = NULL;
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
                temp1->prev = temp2;
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
