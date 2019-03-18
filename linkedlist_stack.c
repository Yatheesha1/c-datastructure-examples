#include <stdio.h>
#include <stdlib.h>
struct SNode
{
    int data;
    struct SNode *next;
} * head;

struct SNode *newNode(int value)
{
    struct SNode *temp = (struct SNode *)malloc(sizeof(struct SNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct SNode *push(struct SNode *sNode, int value)
{
    struct SNode *temp = sNode;
    if (sNode == NULL)
    {
        sNode = newNode(value);
        temp = sNode;
    }
    else
    {
        while (sNode->next)
        { /* code */
            sNode = sNode->next;
        }
        sNode->next = newNode(value);
    }
    printf("Pushed to the stack\n");
    return temp;
}
int getNodeLength(struct SNode *node)
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

void displayStack(struct SNode *node)
{
    if (node)
    {
        printf(">>>Stack Length: %d\n", getNodeLength(node));
        printf(">>>Stack elements: ");
    }
    else
        printf(">>>Stack is empty\n");

    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
        /* code */
    }
    printf("\n");
}
struct SNode *pop(struct SNode *sNode, int *value)
{
    if (sNode == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        if (!sNode->next)
        {
            *value = sNode->data;
            sNode = NULL;
        }
        else
        {
            struct SNode *temp = sNode;
            struct SNode *prev = sNode;
            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            *value = temp->data;
            prev->next = NULL;
            free(temp);
        }
        printf("%d is popped\n", *value);
    }
    return sNode;
};

int main()
{
    char *ch[] = {"Exit", "PUSH", "POP", "Display"};
    int choice, value;
    printf("\n------------------------------------------\nSTACK OPERATION\n");
    while (1)
    {
        printf("------------------------------------------\n");
        printf("      0    -->    EXIT           \n");
        printf("      1    -->    PUSH               \n");
        printf("      2    -->    POP               \n");
        printf("      3    -->    DISPLAY               \n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your value: ");
            scanf("%d", &value);
            head = push(head, value);
            break;

        case 2:
            head = pop(head, &value);
            break;

        case 3:
            displayStack(head);
            break;

        case 0:
            exit(0);
        }

        fflush(stdin);
    }
    return 0;
}