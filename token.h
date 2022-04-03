#ifndef TOKEN_H
#define TOKEN_H

// TT = Token Type
#define TT_END 0
#define TT_DIGIT  1
#define TT_PLUS  2
#define TT_MINUS  3
#define TT_MUL  4
#define TT_DIV 5
#define TT_OPEN_BRACKET 6
#define TT_CLOSE_BRACKET 7
#define TT_SIN 8
#define TT_COS 9
#define TT_TAN 10
#define TT_CTG 11
#define TT_SQRT 12
#define TT_LN 13
#define TT_X 14
#define TT_UNKNOWN 15

struct token {
    int token_type;
    double value;
    char string[80];
};


#endif //TOKEN_H
