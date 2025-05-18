#include "../stack/header/stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack create_stack() {
    Stack s = (Stack) malloc(sizeof(struct stack_structure));
    s->last_element = NULL;
    return s;
};
Node peek(Stack stack) {
    if(stack->last_element == NULL) {
        printf("stack: Stack is empty\n");
    }
    return stack->last_element;
};
void push(Stack stack, Data data) {
    Node new_last_element = create_node(data, NULL);
    if(stack->last_element == NULL) {
        stack->last_element = new_last_element;
        return;
    }
    set_next_node(new_last_element, stack->last_element);
    stack->last_element = new_last_element;
};
void pop(Stack stack) {
    if(stack->last_element == NULL) {
        printf("stack: Stack is empty\n");
        return;
    }
    Node new_last_element = stack->last_element->next_node;
    free_node(stack->last_element);
    stack->last_element = new_last_element;
};
void free_stack(Stack stack) {
    while(stack->last_element != NULL) {
        pop(stack);
    }
    free(stack);
};