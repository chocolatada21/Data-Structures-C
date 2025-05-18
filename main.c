#include <stdio.h>
//#include "../linked_list/header/linked_list.h"
//#include "../stack/header/stack.h"
#include "../queue/header/queue.h"
int main(void) {
    Queue queue = create_queue();
    int a = 1;
    int b = 2;
    int c = 3;
    queue_insert(queue, &a);
    queue_insert(queue, &b);
    queue_insert(queue, &c);
    Node node = queue_remove(queue);
    while(node != NULL) {
        printf("%d ", *(int*) node->value);
        node = queue_remove(queue);
    }
}