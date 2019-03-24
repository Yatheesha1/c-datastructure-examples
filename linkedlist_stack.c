#include <stdio.h>
#include <stdlib.h>
struct SNode
{
    int data;
    struct SNode *next;
} * top;

struct SNode *newNode(int value)
{
    struct SNode *temp = (struct SNode *)malloc(sizeof(struct SNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
void push(struct SNode **tSNode, int value)
{
    struct SNode *temp = newNode(value);
    if ((*tSNode) == NULL)
    {
        (*tSNode) = temp;
    }
    else
    {
        temp->next=(*tSNode);
        (*tSNode)=temp;
    }
    printf("Pushed to the stack\n");
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
        while (node)
    {
        printf("%d ", node->data);
        node = node->next;
        /* code */
    }
    printf("\n");
    }
    else
        printf(">>>Stack is empty\n");
}
void pop(struct SNode **tSNode, int *value)
{
    if ((*tSNode) == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
            struct SNode *temp = (*tSNode);
            *value = temp->data;
            (*tSNode)=(*tSNode)->next;
            free(temp);
        printf("%d is popped\n", *value);
    }
}

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
            push(&top, value);
            break;

        case 2:
            pop(&top, &value);
            break;

        case 3:
            displayStack(top);
            break;

        case 0:
            exit(0);
        }

        fflush(stdin);
    }
    return 0;
}