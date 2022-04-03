#include <math.h>
#include "rpn_executor.h"
#include "simple_list.h"
#include "token.h"

struct list rpn(struct list *parsed_list) {
    struct list result;
    list_init(&result);
    return result;
}

double executor(struct list *rpn, double x) {
    //double result = sin(cos(2 * x));
    double result = sin(x);

    return result;
}