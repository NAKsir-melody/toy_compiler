#ifndef LEX_H
#define LEX_H
#include "global.h"
int lexical_analyzer(char* input_buffer, struct token* tokens);
void print_lexemse(struct token* tokens);
#endif
