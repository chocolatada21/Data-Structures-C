#ifndef QUEUE_H
#define QUEUE_H

#include "../node/header/node.h"
struct queue_struct {
    Node first_element;
};
typedef struct queue_struct* Queue;
Queue create_queue();
void queue_insert(Queue queue, Data data);
Node queue_remove(Queue queue);
void free_queue(Queue queue);

#endif // QUEUE_H