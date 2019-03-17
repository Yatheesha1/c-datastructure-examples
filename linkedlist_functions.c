#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head;

int hasNode(struct Node *);
struct Node *createNode(int);
void getNodeDetails(struct Node *);
int getNodeLength(struct Node *);
int getMiddleNumber(struct Node *);
int isPalindrome(struct Node *);
void doReverse(struct Node **);
int isEven(struct Node *);
void doRecursive(struct Node *);
void doMerging(struct Node *, struct Node *);
int doCompare(struct Node *, struct Node *);
void doSorting(struct Node *);
/* Function to check if given linked list is 
  palindrome or not */
int ispalindrome(struct Node *);

int main()
{
    char *ch[] = {"Exit", "Create", "Node details", "Middle number", "Palindrome",
                  "Reverse", "Even or odd", "Recursive", "Merging", "Sorting", "Compare"};
    while (1)
    {
        int menu, n, index, value;
        struct Node *node;
        printf("\n==========\nMenus\n==========\n0. Exit\n1. Create\n2. Node Details \n3. Middle number"
               "\n4. Palindrome\n5. Reverse\n6. Even or odd\n7. Recursive\n8. Merging\n9. Sorting\n10. Compare\n"
               "\nEnter your input: ");
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
            getNodeDetails(head);
            break;
        case 3:
            printf(">>>Middle number: %d", getMiddleNumber(head));
            break;
        case 4:
            if (isPalindrome(head))
            {
                printf(">>>Node is Palindrome");
            }
            else
            {
                printf(">>>Node is not Palindrome");
            }
            break;
        case 5:
            doReverse(&head);
            // head = doReverse(head);
            printf(">>>Node is reversed");
            break;
        case 6:
            if (isEven(head))
            {
                printf(">>>Node has Even number of elements");
            }
            else
            {
                printf(">>>Node has odd number of elements");
            }
            break;
        case 7:
            doRecursive(head);
            break;
        case 8:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter %d values of node: ", n);
            node = createNode(n);
            doMerging(head, node);
            printf(">>>Nodes are merged");
            break;
        case 9:
            doSorting(head);
            printf(">>>Node is sorted");
            break;
        case 10:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            printf("Enter %d values of node: ", n);
            node = createNode(n);
            if (doCompare(head, node))
            {
                printf(">>>Nodes are not equal");
            }
            else
            {
                printf(">>>Node are equal");
            }
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
                temp = node;
            }
            else
            {
                temp->next = (struct Node *)malloc(sizeof(struct Node));
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

int getMiddleNumber(struct Node *node)
{
    if (hasNode(node))
    {
        struct Node *temp = node;
        while (temp)
        {
            if (!temp->next)
            {
                break;
            }
            temp = temp->next->next;
            node = node->next;
        }
        return node->data;
    }
    else
    {
        return 0;
    }
}

int isPalindrome(struct Node *node)
{
    int ret = 0;
    if (hasNode(node))
    {
        int nodeLength = getNodeLength(node);
        if (node->next == NULL)
            return 1;
        else
        {
            struct Node *temp = node;
            struct Node *first = node;
            struct Node *second = NULL;
            struct Node *mid = NULL;
            while (1)
            {
                temp = temp->next->next;
                if (temp == NULL)
                {
                    //Even
                    second = first->next;
                    mid = second;
                    break;
                }
                if (temp->next == NULL)
                {
                    //Odd
                    second = first->next->next;
                    mid = first->next;
                    break;
                }
                first = first->next;
            }
            first->next = NULL;
            doReverse(&second);
            ret = doCompare(node, second);
            doReverse(&second);
            // mid->next = second;
            first->next = mid;
            return ret;
        }
    }
}

void doReverse(struct Node **node)
{
    if (hasNode(*node))
    {
        struct Node *prev = NULL, *curr = *node;
        while (curr)
        {
            struct Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        *node = prev;
    }
    // return *node;
}
int isEven(struct Node *node)
{
    if (hasNode(node))
    {
        while (node)
        {
            if (!node->next)
            {
                return 0;
            }
            node = node->next->next;
        }
        return 1;
    }
    else
    {
        return 1;
    }
}
void doRecursive(struct Node *node)
{
    if (hasNode(node))
    {
        if (node->next == NULL)
        {
            head = node;
            return;
        }
        doRecursive(node->next);
        struct Node *prev = node->next;
        prev->next = node;
        node->next = NULL;
    }
}
void doMerging(struct Node *node1, struct Node *node2)
{
    if (hasNode(node2))
    {
        if (node1)
        {
            while (node1->next)
            {
                node1 = node1->next;
            }

            node1->next = node2;
        }
        else
        {
            printf("Node 1 is empty");
        }
    }
}
void doSorting(struct Node *node)
{
    if (hasNode(node))
    {
        struct Node *i, *j;
        for (i = node; i->next != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
}

int doCompare(struct Node *head1, struct Node *head2)
{
    struct Node *node1 = head1;
    struct Node *node2 = head2;
    if (hasNode(node1) && hasNode(node2))
    {
        while (node1 && node2)
        {
            if (node1->data == node2->data)
            {
                node1 = node1->next;
                node2 = node2->next;
            }
            else
            {
                return 0;
            }
        }
        if (node1 || node2)
        {
            return 1;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}