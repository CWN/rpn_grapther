#include "simple_list.h"

#ifndef RPN_EXECUTOR_H
#define RPN_EXECUTOR_H

struct list rpn(struct list *parsed_list);

double executor(struct list *rpn, double x);

#endif //RPN_EXECUTOR_H
