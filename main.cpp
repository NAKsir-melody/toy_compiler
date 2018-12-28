#include "global.h"
#include "lex.h"
#include "syntax.h"
#include "ast.h"
#include "codegen.h"

int main(int argc, char* argv[])
{
	//check input
	if(argc != 2){
		printf("missing input file, execution binary with [source file]\n");
		return -1;
	}

	FILE* fp;
	fp = fopen((char*)argv[1],"r");
	if(fp == 0) {
		printf("missing input file, execution binary with [source file]\n");
		return -2;
	}

	size_t read_len;
	char* read_buf = (char*)malloc(256 * sizeof(char)); // 1line

	//read input source file
	while(fscanf(fp, "%[^\n]\n",read_buf) != EOF) {
		read_buf[strlen(read_buf)] ='\0';
		printf("%s\n",read_buf);

		//lexycal
		struct token* token_list = new struct token;
		lexical_analyzer(read_buf, token_list);
		print_lexemse(token_list);

		//syntax
		int ret = syntax_analyzer(token_list);
		print_tokens(token_list);
		if(ret < 0) {
			printf("syntax error %d\n",ret);
			return -1;
		}

		//ast
		Node* root = generate_ast(token_list, root);
		print_ast(root);

		//code_gen
		code_gen(root, "a.out");
		//return 0;
		
	}
	fclose(fp);
	delete read_buf;
	return 0;
}
