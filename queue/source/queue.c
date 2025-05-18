#include "../queue/header/queue.h"
#include <stdlib.h>
#include <stdio.h>
Queue create_queue() {
    Queue q = (Queue) malloc(sizeof(struct queue_struct));
    q->first_element = NULL;
    return q;
};
void queue_insert(Queue queue, Data data) {
    Node new_element = create_node(data, NULL);
    if(queue->first_element == NULL) {
        queue->first_element = new_element;
        return;
    }
    Node current_node = queue->first_element;
    while(current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    set_next_node(current_node, new_element);
};
Node queue_remove(Queue queue) {
    if(queue->first_element == NULL) {
        printf("queue: Queue is empty\n");
        return NULL;
    }
    Node old_element = queue->first_element;
    queue->first_element = old_element->next_node;
    return old_element;
};
void free_queue(Queue queue) {
    Node current_node = queue->first_element;
    Node delete_this;
    while(current_node != NULL) {
        delete_this = current_node;
        current_node = current_node->next_node;
        free_node(delete_this);
    }
    free(queue);
};