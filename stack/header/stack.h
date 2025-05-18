#ifndef STACK_H
#define STACK_H

#include "../node/header/node.h"

struct stack_structure {
    Node last_element;
};
typedef struct stack_structure* Stack;
Stack create_stack();
Node peek(Stack stack);
void push(Stack stack, Data data);
void pop(Stack stack);
void free_stack(Stack stack);
#endif // STACK_H