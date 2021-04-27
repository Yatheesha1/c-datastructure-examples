#include <stdio.h>
#include <stdlib.h>

#define NODE_MAX 20
#define LOOP_AT 1
#define PRINT_MAX 30

typedef struct _Node
{
    int data;
    struct _Node* next;
    
} Node;

Node *head, *lastNode = NULL;


void createNode() {
    for (int i = 1; i <= NODE_MAX; i++) {
        Node *temp = (Node*) malloc (sizeof(Node));
        temp->data = i;
        temp->next = NULL;
        if (lastNode == NULL) {
            head = temp;
        } else {
            lastNode->next = temp;
        }
        
        lastNode = temp;
    }
}

void addLoop() {
    Node* temp = head;
    int k = 0;
    while (temp != NULL) {
        k++;
        if (k == LOOP_AT) {
            lastNode->next = temp;
            printf("Loop added\n");
            return;
        }
        temp = temp->next;
    }
}

void printNode(Node *node) {
    for (int i = 0; i < PRINT_MAX; i++) {
        if (node == NULL) {
            break;
        }
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


Node* detectLoop(Node * node) {
    Node *fastptr = node;
    Node *slowptr = node;
    int complexity = 0;

    while(fastptr != NULL && slowptr != NULL && fastptr->next != NULL) {
        complexity++;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (fastptr == slowptr) {
            printf("Complexity: %d\n", complexity);
            return fastptr;
        }
    }

    printf("Complexity: %d\n", complexity);
    return NULL;
}

void removeLoop(Node* node) {
    Node* temp = head;
    if(node == head) {
        lastNode->next = NULL;
        printf("Loop at %p:%d\n", head, head->data);
    } else {
        while (temp->next != node->next) {
            temp =temp->next;
            node = node->next;
        }
        printf("Loop at %p:%d\n", node->next, node->next->data);
        node->next = NULL;
    }
}

int main() {
    printf("Started....\n");

    createNode();

    addLoop();

    printNode(head);

    Node *loopflag = detectLoop(head);
    if( loopflag != NULL) {
        printf("Loop detected\n");
        removeLoop(loopflag);
        printf("Loop removed\n");
        printNode(head);
    }

    printf("\n");
    return 0;
}





