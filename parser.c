#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "token.h"
#include "string.h"

struct token get_token(char *token_string) {
    struct token result_token;

    result_token.token_type = TT_UNKNOWN;
    result_token.value = 0;
    memset(result_token.string, 0, MAX_LEXEMA_LENGTH);

    if (strlen(token_string) == 1) {
        switch (token_string[0]) {
            case '(':
                result_token.token_type = TT_OPEN_BRACKET;
                break;
            case ')':
                result_token.token_type = TT_CLOSE_BRACKET;
                break;
            case '+':
                result_token.token_type = TT_PLUS;
                break;
            case '-':
                result_token.token_type = TT_MINUS;
                break;
            case '*':
                result_token.token_type = TT_MUL;
                break;
            case '/':
                result_token.token_type = TT_DIV;
                break;
            case 'x':
                result_token.token_type = TT_X;
                break;
            default:
                break;
        }
    } else {
        if (strcmp(token_string, "sin") == 0) {
            result_token.token_type = TT_SIN;
        } else if (strcmp(token_string, "cos") == 0) {
            result_token.token_type = TT_COS;
        } else if (strcmp(token_string, "tan") == 0) {
            result_token.token_type = TT_TAN;
        } else if (strcmp(token_string, "ctg") == 0) {
            result_token.token_type = TT_CTG;
        } else if (strcmp(token_string, "sqrt") == 0) {
            result_token.token_type = TT_SQRT;
        } else if (strcmp(token_string, "ln") == 0) {
            result_token.token_type = TT_LN;
        } else if (strcmp(token_string, "sqrt") == 0) {
            result_token.token_type = TT_SQRT;
        }
    }

    if (result_token.token_type == TT_UNKNOWN) {
        char *endptr;
        double d = strtod(token_string, &endptr);
        if (token_string == endptr) {
            result_token.token_type = TT_UNKNOWN;
        } else {
            if (strlen(endptr) == 0) {
                result_token.token_type = TT_DIGIT;
                result_token.value = d;
            } else {
                result_token.token_type = TT_UNKNOWN;
            }
        }
    }

    strcpy(result_token.string, token_string);

    return result_token;
}

struct list parse_source(char *source) {
    struct list result;
    list_init(&result);

    int i = 0; // текущий символ в строке ввода
    char lexema[MAX_LEXEMA_LENGTH] = {'\0'}; // текущая лексема
    int lexema_length = 0; // длина текущей лексемы
    char single[2] = {'\0'}; // текущий символ, если совпал с односимвольной лексемой

    struct token tkn;

    while (source[i] != '\0') {
        switch (source[i]) {
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
                if (lexema[0] != '\0') {
                    list_append(&result, get_token(lexema));
                }

                memset(lexema, 0, MAX_LEXEMA_LENGTH);
                lexema_length = 0;

                single[0] = source[i];
                list_append(&result, get_token(single));
                break;
            case ' ':
                // пропустим пробелы
                break;
            default:
                lexema[lexema_length] = source[i];
                lexema_length++;
        }
        i++;
    }

    if (lexema[0] != '\0') {
        list_append(&result, get_token(lexema));
    }

    return result;
}

void check_parse_errors(struct list *parsed_list) {
    struct token tt = list_get_first(parsed_list);

    while (tt.token_type != TT_END) {
        if (tt.token_type == TT_UNKNOWN) {
            printf("Unknown lexema: %s", tt.string);
            abort();
        }
        tt = list_get_next(parsed_list);
    }
}