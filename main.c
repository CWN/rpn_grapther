#include <stdio.h>
#include <math.h>
#include "simple_stack.h"
#include "simple_list.h"
#include "parser.h"
#include "rpn_executor.h"
#include "display.h"

int main() {
    //char test[] = "Test! Test(dfs )aaa+1+1000a+sin(x)*cos(y)";
    //char test[] = "sin(cos(2*x))*tan(x)- 1";
    char test[] = "sin(cos(2*x))";
    //char test[] = "sin ( cos ( x ) / 3 * 2)";

    printf("%s\n", test);

    double x, y;
    int i, j;

    double delta = 3.1415 * 4 / 80;

    struct display display;
    struct stack parse_stack;
    struct list parsed_list;
    struct list rpn_list;

    parsed_list = parse_source(test);
    check_parse_errors(&parsed_list);

    printf("parsed list:\n");
    list_debug_print(&parsed_list);

    rpn_list = rpn(&parsed_list);

    printf("RPN List:\n");
    list_debug_print(&rpn_list);

    x = 0;
    display_clear(&display);

    for (i = 0; i < DISPLAY_WIDTH; i++) {
        y = executor(&rpn_list, x);
        printf("%lf : %lf\n", x, y);
        x += delta;

        j = DISPLAY_CENTER_Y + (int) round(DISPLAY_HALF_HEIGHT * y) - 1;

        if (j >= 0 && j < DISPLAY_HEIGHT) {
            display.grid[i][j] = 1;
        }
    }

    display_print(&display);

    /*
    stack_init(&parse_stack);

    for (int i = 0; i < 5; i++) {
        struct token tkn = {TT_DIGIT, i};
        stack_push(&parse_stack, tkn);
    }

    struct token tkn2 = stack_pop(&parse_stack);
    while (tkn2.token_type != TT_END) {
        printf("Stack pop: %lf\n", tkn2.value);
        tkn2 = stack_pop(&parse_stack);
    }*/

    return 0;
}