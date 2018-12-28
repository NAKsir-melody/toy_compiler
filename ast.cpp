#include "ast.h"

Node* parse(struct token* tokens)
{
	sigmoid_stack<Node*> expr_stack;
	Node *e, *e1, *e2;
	struct token* start = tokens->next;
	while (start) {
		e = e1 = e2 = 0;
		switch(start->type) {
			case item_PRINT:
				e = expr_stack.top();
				e->print = true;
			break;
			case item_PUSH:
				start = start->next;
				expr_stack.push(new Node(start, 0, 0));
			break;
			case item_DUP:
				e = expr_stack.pop();
				expr_stack.push(new Node(e->c, e->left, e->right));
				e1 = expr_stack.top();
				e1->print = e->print;
				expr_stack.push(new Node(e->c, e->left, e->right));
				e2 = expr_stack.top();
				e2->print = e->print;
			break;
			case item_DROP:
				e = expr_stack.pop();
				delete e;
			break;
			case item_ADD:
				e2 = expr_stack.pop();
				e1 = expr_stack.pop();
				expr_stack.push(new Node(start, e1, e2));
			break;
			case item_SUB:
				e2 = expr_stack.pop();
				e1 = expr_stack.pop();
				expr_stack.push(new Node(start, e1, e2));
			break;
		}
		start = start->next;
	}
	return expr_stack.pop();
}

void do_traversal(Node* root)
{
	if(!root)
		return;

	do_traversal(root->left);
	do_traversal(root->right);

	if(root->print)
		printf("%d %s [P]\n", root->c->type, root->c->value);
	else
		printf("%d %s\n", root->c->type, root->c->value);
}

void print_ast(Node* root)
{
	printf("\n=======");
	printf("%s",__func__);
	printf("=======\n");
	do_traversal(root);
	printf("\n");
}

Node* generate_ast(struct token* tokens, Node* root)
{
	return parse(tokens);
}
