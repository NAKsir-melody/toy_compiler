#include "lex.h"

int syntax_validate(struct token* tokens)
{
	struct token* start = tokens->next;
	while (start != NULL) {
		if(start->type == item_ERR)
			return -1;
		if(start->type == item_PUSH && !start->next)
			return -2;
		if(start->type != item_PUSH && start->next)
		if(start->next->type == item_LIT)
			return -3;
		start = start->next;
	}
	return 0;
}

int syntax_analyzer(struct token* tokens)
{
	struct token* start = tokens->next;
	while (start != NULL) {
		if(!strcmp("ADD",start->value)) {	
			start->type = item_ADD;
			start = start->next;
			continue;
		}
		if(!strcmp("SUB",start->value))	{
			start->type = item_SUB;
			start = start->next;
			continue;
		}
		if(!strcmp("PUSH",start->value)) {	
			start->type = item_PUSH;
			start = start->next;
			continue;
		}
		if(!strcmp("DROP",start->value)) {	
			start->type = item_DROP;
			start = start->next;
			continue;
		}
		if(!strcmp("DUP",start->value))	{
			start->type = item_DUP;
			start = start->next;
			continue;
		}
		if(!strcmp("PRINT",start->value)) {	
			start->type = item_PRINT;
			start = start->next;
			continue;
		}

		start->type = item_LIT;
		for(int i=0; i<strlen(start->value); i++) {
			if( start->value[i] - '0' > 9 || start->value[i] - '0' < 0 ){
				start->type = item_ERR;
				printf("error\n");
				break;
			}

		}
		start = start->next;
	}
	return syntax_validate(tokens);
}


void print_tokens(struct token* tokens)
{
	struct token* start = tokens->next;
	printf("\n=======");
	printf("%s",__func__);
	printf("=======\n");
	while (start != NULL) {
		printf("%d %s\n", start->type, start->value);
		start = start->next;
	}
}
