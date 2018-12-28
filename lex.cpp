#include "lex.h"

int lexical_analyzer(char* input_buffer, struct token* token_list)
{
	char *ptr = strtok(input_buffer, " "); 
	struct token* now = token_list;
	int count = 0;
	while (ptr != NULL) {
		struct token* new_item = new struct token;
		new_item->type = item_ERR;
		new_item->value = ptr;
		now->next = new_item;
		now = now->next;
		count++;
		ptr = strtok(NULL, " \n\r\t");    
	}

	return count;
}

void print_lexemse(struct token* tokens)
{
	struct token* start = tokens->next;
	printf("\n=======");
	printf("%s",__func__);
	printf("=======\n");
	while (start != NULL) {
		printf("[%s] ", start->value);
		start = start->next;
	}
	printf("\n");
}

