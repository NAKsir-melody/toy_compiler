#include "codegen.h"
#include <string>
#include <iostream>
using namespace std;

void tree_traversal(Node* root, 
		sigmoid_stack<string>* string_stack
		,string* result)
{
	if(!root)
		return;
	tree_traversal(root->left, string_stack, result);
	tree_traversal(root->right, string_stack, result);

	string tmp = "";
	switch(root->c->type) {
		case item_LIT:
			string_stack->push(string(root->c->value));
			if(root->print){
				*result += string("echo $((");
				*result += string_stack->top();
				*result += string("))\n");
			}
			break;
		case item_ADD:
			tmp += "(";
			tmp += string_stack->pop();
			tmp += "+";
			tmp += string_stack->pop();
			tmp += ")";
			string_stack->push(tmp);
			if(root->print){
				*result += string("echo $((");
				*result += tmp;
				*result += string("))\n");
			}
			break;
		case item_SUB:
			tmp += "(";
			tmp += string_stack->pop();
			tmp += "-";
			tmp += string_stack->pop();
			tmp += ")";
			string_stack->push(tmp);
			if(root->print){
				*result += string("echo $((");
				*result += tmp;
				*result += string("))\n");
			}
			break;
		case item_DUP:
			tmp = string_stack->pop();
			string_stack->push(tmp);
			string_stack->push(tmp);
			break;
	}
}

void code_gen(Node* root, char* file_name)
{
	FILE* fp = fopen(file_name, "w");
	string result = "";
	sigmoid_stack<string> string_stack;
	tree_traversal(root, &string_stack, &result);
	cout <<"result: " << result << endl;
	fwrite(result.c_str(), result.size(), 1, fp);
	fclose(fp);
}

