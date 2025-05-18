#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <node.h>

struct linked_list_structure {
    Node first_node;
    Node last_node;
    int size;
};

typedef struct linked_list_structure* LinkedList;

LinkedList create_linked_list();
void ll_print(LinkedList ll);
void ll_insert(LinkedList ll, int value);
void ll_remove(LinkedList ll, int position);
Node ll_get(LinkedList ll, int position);
void ll_free(LinkedList ll);

#endif // LINKED_LIST_H