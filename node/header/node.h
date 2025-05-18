#ifndef NODE_H
#define NODE_H

typedef struct node_struct* Node;
typedef void* Data;

struct node_struct {
    Data value;
    Node next_node;
};

Node create_node(Data value, Node next_node);
void print_int_node(Node node);
void print_float_node(Node node);
void print_char_node(Node node);
void set_value(Node current_node, Data new_value);
void set_next_node(Node current_node, Node new_next_node);
void free_node(Node node);

#endif // NODE_H