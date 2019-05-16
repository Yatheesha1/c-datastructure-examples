#ifndef Config_H
#define Config_H

struct Node
{
    int value;
    struct Node *link;
};

class NodeFunctions
{
public:
    struct Node *header, *current;

public:
    NodeFunctions();
    struct Node *newNode(int);
    int getNodeLength(struct Node *);
    void display(struct Node *);
    struct Node *insert(struct Node *);
    void remove(struct Node **, struct Node **);
};

#endif