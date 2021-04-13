#include <stdio.h>
#include <stdlib.h>
struct QNode
{
    int data;
    struct QNode *next;
} * front,*rear;

struct QNode *newQNode(int value)
{
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void enQueue(struct QNode **fQNode,struct QNode **rQNode, int value)
{
    struct QNode *temp = newQNode(value);
    if ((*rQNode) == NULL)
    {
        (*fQNode) = (*rQNode)=temp;
    }
    else
    {
        (*rQNode)->next=temp;
        (*rQNode) = (*rQNode)->next;
    }
    printf("Pushed to the stack\n");
    // return rQNode;
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
        while (node)
    {
        printf("%d ", node->data);
        node = node->next;
        /* code */
    }
    }
    else
        printf(">>>Queue is empty\n");

    printf("\n");
}
void deQueue(struct QNode **fQNode,struct QNode **rQNode, int *value)
{
    if ((*rQNode) == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if ((*rQNode)==(*fQNode))
        {
            *value = (*rQNode)->data;
            (*rQNode)=(*fQNode) = NULL;
        }
        else
        {
            *value = (*fQNode)->data;
            struct QNode *temp=(*fQNode);
            (*fQNode)=(*fQNode)->next;
            free(temp);
        }
        printf("%d is popped\n", *value);
    }
    // return fQNode;
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
        printf("      1    -->    enQueue               \n");
        printf("      2    -->    deQueue               \n");
        printf("      3    -->    DISPLAY               \n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your value: ");
            scanf("%d", &value);
            enQueue(&front, &rear, value);
            break;

        case 2:
            deQueue(&front,&rear, &value);
            break;

        case 3:
            displayQueue(front);
            break;

        case 0:
            exit(0);
        }

        fflush(stdin);
    }
    return 0;
}