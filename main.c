#include <stdio.h>
#include <math.h>
#include "simple_stack.h"
#include "simple_list.h"
#include "parser.h"
#include "rpn_executor.h"
#include "display.h"

//#define DEBUG

int main() {
    //char test[] = "Test! Test(dfs )aaa+1+1000a+sin(x)*cos(y)";
    //char test[] = "sin(cos(2*x))*tan(x)- 1";
    //char test[] = "sin(cos(2*x))";
    //char test[] = "sin ( cos ( x ) / 3 * 2)";

    //char test[] = "sin(cos(2*x))";
    char func[MAX_LEXEMA_LENGTH];
    scanf("%s", func);

#ifdef DEBUG
    printf("%s\n", func);
#endif

    double x, y;
    int i, j;

    double delta = 3.1415 * 4 / 80;

    struct display display;
    struct list parsed_list;
    struct list rpn_list;

    parsed_list = parse_source(func);
    check_parse_errors(&parsed_list);

#ifdef DEBUG
    printf("parsed list:\n");
    list_debug_print(&parsed_list);
#endif

    rpn_list = rpn(&parsed_list);

#ifdef DEBUG
    printf("RPN List:\n");
    list_debug_print(&rpn_list);
#endif

    x = 0;
    display_clear(&display);

    for (i = 0; i < DISPLAY_WIDTH; i++) {
        y = executor(&rpn_list, x);
#ifdef DEBUG
        printf("%lf : %lf\n", x, y);
#endif
        j = DISPLAY_CENTER_Y + (int) round(DISPLAY_HALF_HEIGHT * y) - 1;

        if (j >= 0 && j < DISPLAY_HEIGHT) {
            display.grid[i][j] = 1;
        }
        x += delta;
    }

    display_print(&display);
    return 0;
}