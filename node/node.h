#ifndef NODE_H
#define NODE_H

typedef struct node_struct* Node;

struct node_struct {
    int value;
    Node next_node;
};

Node create_node(int value, Node next_node);
void set_value(Node current_node, int new_value);
void set_next_node(Node current_node, Node new_next_node);
void free_node(Node node);

#endif // NODE_H