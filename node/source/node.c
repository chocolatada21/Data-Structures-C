#include "../node/header/node.h"
#include <stdio.h>
#include <stdlib.h>
Node create_node(Data value, Node next_node) {
    Node n = (Node) malloc(sizeof(struct node_struct));
    n->value = value;
    n->next_node = next_node;
    return n;
};
void print_int_node(Node node) {
    int value = *(int*) node->value;
    printf("%d", value);
};
void print_float_node(Node node) {
    float value = *(float*) node->value;
    printf("%.2f", value);
};
void print_char_node(Node node) {
    char value = *(char*) node->value;
    printf("%s", value);
};
void set_value(Node current_node, Data new_value) {
    current_node->value = new_value;
};
void set_next_node(Node current_node, Node new_next_node) {
    current_node->next_node = new_next_node;
};
void free_node(Node node) {
    free(node);
};