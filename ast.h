#ifndef AST_H
#define AST_H
#include "global.h"
Node* generate_ast(struct token* tokens, Node* root);
void print_ast(Node* root);
#endif
