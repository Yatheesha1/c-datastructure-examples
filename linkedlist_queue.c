#include <stdio.h>
#include <stdlib.h>
struct QNode
{
    int data;
    struct QNode *next;
} * head;

struct QNode *newNode(int value)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct QNode *push(struct QNode *qNode, int value)
{
    struct QNode *temp = qNode;
    if (qNode == NULL)
    {
        qNode = newNode(value);
        temp = qNode;
    }
    else
    {
        struct QNode *temp = newNode(value);
        temp->next = qNode;
        qNode = temp;
    }
    printf("Pushed to the stack\n");
    return qNode;
}
int getNodeLength(struct QNode *node)
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

void displayQueue(struct QNode *node)
{
    if (node)
    {
        printf(">>>Queue Length: %d\n", getNodeLength(node));
        printf(">>>Queue elements: ");
    }
    else
        printf(">>>Queue is empty\n");

    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
        /* code */
    }
    printf("\n");
}
struct QNode *pop(struct QNode *qNode, int *value)
{
    if (qNode == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (!qNode->next)
        {
            *value = qNode->data;
            qNode = NULL;
        }
        else
        {
            struct QNode *temp = qNode;
            struct QNode *prev = qNode;
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
    return qNode;
};

int main()
{
    char *ch[] = {"Exit", "PUSH", "POP", "Display"};
    int choice, value;
    printf("\n------------------------------------------\nQUEUE OPERATION\n");
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
            displayQueue(head);
            break;

        case 0:
            exit(0);
        }

        fflush(stdin);
    }
    return 0;
}