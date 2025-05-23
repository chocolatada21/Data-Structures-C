#include "../linked_list/header/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList create_linked_list() {
    LinkedList ll = (LinkedList) malloc(sizeof(struct linked_list_structure));
    ll->first_node = NULL;
    ll->last_node = NULL;
    ll->size = 0;
    return ll;
}
void ll_print(LinkedList ll, int type_print_code) {
    if(type_print_code != LL_DATA_INT && type_print_code != LL_DATA_FLOAT && type_print_code != LL_DATA_CHAR) {
        printf("linked_list: Invalid print code. Expected LL_DATA_INT, LL_DATA_FLOAT_ or LL_DATA_CHAR\n");
        return;
    }
    Node current_node = ll->first_node;
    while(current_node != NULL) {
        if(type_print_code == LL_DATA_INT) {
            print_int_node(current_node);
        }
        if(type_print_code == LL_DATA_FLOAT) {
            print_float_node(current_node);
        }
        if(type_print_code == LL_DATA_CHAR) {
            print_char_node(current_node);
        }
        printf(" ");
        current_node = current_node->next_node;
    }
    printf("\n");
}
void ll_insert(LinkedList ll, Data value) {
    Node new_node = create_node(value, NULL);
    ll->size += 1;
    if(ll->first_node == NULL && ll->last_node == NULL) {
        ll->first_node = new_node;
        ll->last_node = new_node;
        return;
    }
    if(ll->first_node == ll->last_node) {
        set_next_node(ll->first_node, new_node);
        ll->last_node = new_node;
        return;
    }
    set_next_node(ll->last_node, new_node);
    ll->last_node = new_node;
}
void ll_remove(LinkedList ll, int position) {
    if(ll->size - 1 < position) {
        printf("linked_list: Invalid position. Size is %d and requested position is %d", ll->size, position);
        return;
    }
    if(position == 0) {
        Node old_first_node = ll->first_node;
        ll->first_node = old_first_node->next_node;
        free_node(old_first_node);
        ll->size -= 1;
        return;
    }
    if(position == ll->size - 1) {
        Node old_last_node = ll->last_node;
        Node new_last_node = ll_get(ll, position - 1);
        ll->last_node = new_last_node;
        set_next_node(ll->last_node, NULL);
        free_node(old_last_node);
        ll->size -= 1;
        return;
    }
    Node current_node = ll->first_node;
    for(int i = 0 ; i < position - 1 ; i++) {
        current_node = current_node->next_node;
    }
    Node delete_this_node = current_node->next_node;
    current_node->next_node = delete_this_node->next_node;
    free_node(delete_this_node);
    ll->size -= 1;
}
Node ll_get(LinkedList ll, int position) {
    if(ll->size - 1 < position) {
        printf("linked_list: Invalid position. Size is %d and requested position is %d", ll->size, position);
        return NULL;
    }
    if(position == 0) {
        return ll->first_node;
    }
    if(position == ll->size - 1) {
        return ll->last_node;
    }
    Node current_node = ll->first_node;
    for(int i = 0 ; i < position ; i++) {
        current_node = current_node->next_node;
    }
    return current_node;
}
void ll_free(LinkedList ll) {
    if(ll->size == 0) {
        free(ll);
        return;
    }
    Node current_node = ll->first_node;
    Node next_node = current_node->next_node;
    while(next_node != NULL) {
        free_node(current_node);
        current_node = next_node;
        next_node = current_node->next_node;
    }
    free(ll);
}