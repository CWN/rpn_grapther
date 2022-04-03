#include "simple_list.h"

#ifndef PARSER_H
#define PARSER_H

#define MAX_LEXEMA_LENGTH 80

struct list parse_source(char *source);

void check_parse_errors(struct list *parsed_list);

#endif //PARSER_H
