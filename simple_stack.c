#include <stdlib.h>
#include <stdio.h>
#include "simple_stack.h"
#include "token.h"

void stack_init(struct stack *stack) {
    (*stack).top = 0;
}

void stack_push(struct stack *stack, struct token token) {
    if ((*stack).top + 1 >= MAX_STACK_SIZE) {
        printf("Stack overflow");
        abort();
    }

    (*stack).top++;
    (*stack).storage[(*stack).top] = token;
}

struct token stack_pop(struct stack *stack) {
    if ((*stack).top == 0) {
        struct token end_list = {TT_END, 0};
        return end_list;
    }
    
    (*stack).top--;
    return (*stack).storage[(*stack).top + 1];
}
