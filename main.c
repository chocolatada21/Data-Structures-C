#include <stdio.h>
#include "../linked list/header/linked_list.h"

int main(void) {
    LinkedList ll = create_linked_list();
    int y;
    for(int i = 0 ; i <= 10 ; i++) {
        y = i*3 + 10;
        ll_insert(ll, y);
    }
    printf("First print\n");
    ll_print(ll);
    ll_remove(ll, 7);
    printf("\nSecond print\n");
    ll_print(ll);
    ll_free(ll);
    printf("\nFinished\n");
}