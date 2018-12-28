#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128 

enum token_type{
	item_ERR,
	item_ADD,
	item_SUB,
	item_PUSH,
	item_DROP,
	item_DUP,
	item_PRINT,
	item_LIT
};

struct token {
	token_type type;
	char* value;
	struct token* next;
};

class Node {
public:
	struct token* c; 
	Node* left;
	Node* right;
	bool print;
	Node(struct token* n, Node* l, Node* r) {
		c = n;
		left = l;
		right = r;
		print = false;
	}
};

template <class T>
class sigmoid_stack
{
private:
	int sp;
	T stack[MAX];
public:
	sigmoid_stack()
	{
		sp = 0;
	}

	void push(T symbol)
	{
		if(sp > MAX) {
			printf("Stack overflow\n");
		}
		else {
			stack[++sp] = symbol;
		}
	} 

	T pop()
	{
		if (sp == 0) {
			printf("Stack underflow \n");
			return 0;
		}
		else {
			T retval = stack[sp--];
			return retval;
		}
	}

	T top()
	{
		if (sp == 0) {
			return 0;
		}
		else
			return stack[sp];
	}
};

#endif
