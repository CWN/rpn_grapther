#include "token.h"

#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H

#define MAX_STACK_SIZE 100

struct stack {
    struct token storage[MAX_STACK_SIZE];
    int top;
};

void stack_init(struct stack *stack);

void stack_push(struct stack *stack, struct token token);

struct token stack_pop(struct stack *stack);

#endif //SIMPLE_STACK_H
