#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../node/header/node.h"

#define LL_DATA_INT   0
#define LL_DATA_FLOAT 1
#define LL_DATA_CHAR  2

struct linked_list_structure {
    Node first_node;
    Node last_node;
    int size;
};

typedef struct linked_list_structure* LinkedList;

LinkedList create_linked_list();
void ll_print(LinkedList ll, int type_print_code);
void ll_insert(LinkedList ll, Data value);
void ll_remove(LinkedList ll, int position);
Node ll_get(LinkedList ll, int position);
void ll_free(LinkedList ll);

#endif // LINKED_LIST_H