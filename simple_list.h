#include "token.h"

#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#define MAX_LIST_SIZE 200

struct list {
    struct token storage[MAX_LIST_SIZE];
    int current;
    int count;
};

void list_init(struct list *list);

struct token list_get_first(struct list *list);

struct token list_get_next(struct list *list);

void list_append(struct list *list, struct token token);

void list_debug_print(struct list *list);

#endif //SIMPLE_LIST_H
