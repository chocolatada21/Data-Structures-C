#include <node.h>
#include <stdlib.h>
Node create_node(int value, Node next_node) {
    Node n = (Node) malloc(sizeof(struct node_struct));
    n->value = value;
    n->next_node = next_node;
    return n;
};
void set_value(Node current_node, int new_value) {
    current_node->value = new_value;
};
void set_next_node(Node current_node, Node new_next_node) {
    current_node->next_node = new_next_node;
};
void free_node(Node node) {
    free(node);
};