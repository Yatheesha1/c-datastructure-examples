#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Node
{
    int data;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node * head;

Node *createNode(int);
void getNodeDetails(Node *);
int getNodeLength(Node *);
Node *insertNode(Node *, int, int);
Node *removeNode(Node *, int);
Node *removeNodeRec(Node *node);
Node *removeNodeIndexRec(Node *node, int k);

int main()
{
    char *ch[] = {"Exit", "Create", "Insert", "Remove", "Node details", "RemoveNodeRec", "RemoveNodeIndexRec"};
    while (1)
    {
        int menu, n, index, value, menulen;
        menulen = sizeof(ch)/sizeof(ch[0]);
        printf("\n==========\nMenus\n==========\n");
        for (int i = 0; i < menulen; i++) {
            printf("%d. %s\n", i, ch[i]);
        }
        printf("\nEnter your input: ");

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
        case 5:
            head = removeNodeRec(head);
            printf("Nodes are cleared");
            break;

        case 6:
            printf("Enter index: ");
            scanf("%d", &index);
            head = removeNodeIndexRec(head, index);
            printf("Nodes are cleared");
            break;

        default:
            printf("Invalid input please try again.\n");
            break;
        }
    }
    return 0;
}
int hasNode(Node *node)
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
int getNodeLength(Node *node)
{
    int count = 0;
    while (node)
    {
        node = node->next;
        count++;
    }
    return count;
}
Node *createNode(int n)
{
    Node *node = NULL;
    if (n <= 0)
    {
        printf("Length should be >0");
    }
    else
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        for (int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            if (i == 0)
            {
                node = (Node *)malloc(sizeof(Node));
                node->data = value;
                node->next = NULL;
                node->prev = NULL;
                temp = node;
            }
            else
            {
                temp->next = (Node *)malloc(sizeof(Node));
                temp->next->prev = temp;
                temp = temp->next;
                temp->data = value;
                temp->next = NULL;
            }
        }
    }
    return node;
}

void getNodeDetails(Node *node)
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
Node *insertNode(Node *node, int position, int value)
{
    int nodelength = getNodeLength(node);
    if (position < 0 || position > nodelength)
    {
        printf("Unable find location");
        if (!node)
            printf(" your Node is empty.");
        return node;
    }
    Node *temp = (Node *)malloc(sizeof(Node));

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
            temp->next = (Node *)malloc(sizeof(Node));
            temp->next->prev = temp;
            temp = temp->next;
            temp->data = value;
            temp->next = NULL;
        }
        else
        {
            Node *temp2 = (Node *)malloc(sizeof(Node));
            temp2->prev = temp;
            temp2->next = temp->next;
            temp2->data = value;
            temp->next = temp2;
        }
    }
    printf("Item inserted to node.");
    return node;
}
Node *removeNode(Node *node, int index)
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
                Node *temp = node;
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                temp->next = NULL;
                free(temp->next);
            }
            else
            {
                Node *temp2 = node;
                index--;
                while (index--)
                {
                    temp2 = temp2->next;
                }
                Node *temp1 = temp2->next->next;
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

Node *removeNodeRec(Node *node)
{
    if (node == NULL) {
        return NULL;
    }

    node->next = removeNodeRec(node->next);
    printf("Address: %p, Data: %d\n", node->next, node->data);
    free(node);
    node = NULL;
    return node;
}

Node *removeNodeIndexRec(Node *node, int k)
{
    printf("k: %d: \n", k);
    if (node == NULL) {
        printf("Node is out of index\n");
        return NULL;
    }
    if (k == 0) {
        return node->next;
    }

    if (k == 1) {
        Node *temp = node->next;
        if (temp != NULL) {
            node->next = temp->next;
        }
        printf("Deleting %d: \n", temp->data);
        free(temp);
        temp = NULL;
        return node;
    }

    node->next = removeNodeIndexRec(node->next, k-1);
    if (node->next != NULL) {
        node->next->prev = node;
    }
    return node;
}
