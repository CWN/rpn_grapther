#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpn_executor.h"
#include "simple_list.h"
#include "token.h"
#include "simple_stack.h"

/*
{'_', 10, ASSOC_RIGHT, 1, eval_uminus},
{'^', 9,  ASSOC_RIGHT, 0, eval_exp},
{'*', 8,  ASSOC_LEFT,  0, eval_mul},
{'/', 8,  ASSOC_LEFT,  0, eval_div},
{'%', 8,  ASSOC_LEFT,  0, eval_mod},
{'+', 5,  ASSOC_LEFT,  0, eval_add},
{'-', 5,  ASSOC_LEFT,  0, eval_sub},
{'(', 0,  ASSOC_NONE,  0, NULL},
{')', 0,  ASSOC_NONE,  0, NULL}
 */

struct list rpn(struct list *parsed_list) {
    // приоритет операций по типам токенов от TT_END до TT_UNKNOWN
    const int precedence[16] = {0, 0, 2, 2, 4, 4, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0};

    struct stack stack;
    struct list result;

    struct token current_tt, top_tt;

    stack_init(&stack);
    list_init(&result);

    current_tt = list_get_first(parsed_list);
    while (current_tt.token_type != TT_END) {
        switch (current_tt.token_type) {
            case TT_DIGIT:
            case TT_X:
                list_append(&result, current_tt);
                break;
            case TT_SIN:
            case TT_COS:
            case TT_TAN:
            case TT_CTG:
            case TT_SQRT:
            case TT_LN:
                stack_push(&stack, current_tt);
                break;
            case TT_PLUS:
            case TT_MINUS:
            case TT_MUL:
            case TT_DIV:
                top_tt = stack_top(&stack);
                while ((top_tt.token_type != TT_END) && (top_tt.token_type != TT_OPEN_BRACKET)
                       && (precedence[top_tt.token_type] > precedence[current_tt.token_type])) {
                    // пропущена проверка для унарного минуса

                    list_append(&result, stack_pop(&stack));
                    top_tt = stack_top(&stack);
                }

                stack_push(&stack, current_tt);
                break;
            case TT_OPEN_BRACKET:
                stack_push(&stack, current_tt);
                break;
            case TT_CLOSE_BRACKET:
                top_tt = stack_top(&stack);
                while (top_tt.token_type != TT_OPEN_BRACKET) {
                    if (top_tt.token_type == TT_END) {
                        printf("Absent open bracket\n");
                        abort();
                    }
                    list_append(&result, stack_pop(&stack));
                    top_tt = stack_top(&stack);
                }
                if (top_tt.token_type != TT_OPEN_BRACKET) {
                    printf("Absent open bracket\n");
                    abort();
                }
                stack_pop(&stack);
                top_tt = stack_top(&stack);
                switch (top_tt.token_type) {
                    case TT_SIN:
                    case TT_COS:
                    case TT_TAN:
                    case TT_CTG:
                    case TT_SQRT:
                    case TT_LN:
                        list_append(&result, stack_pop(&stack));
                        break;
                }

                break;
            default:
                break;
        }
        current_tt = list_get_next(parsed_list);
    }

    current_tt = stack_pop(&stack);
    while (current_tt.token_type != TT_END) {
        list_append(&result, current_tt);
        current_tt = stack_pop(&stack);
    }

    return result;
}

double executor(struct list *rpn, double x) {
    //double result = sin(cos(2 * x));
    double result = sin(x);

    return result;
}