#include "opcodes.h"

#define BUF_SIZE 1000
#define TOK_SIZE 20
#define DELIMS "\t\r\n\a, "

char *read_line(void);
char **split_line(char *);

int main(void) {
	// Buffers
	char *BUFFER;
	char **TOKS; 
	char *curr_token;
	int i;
	
	Machine *MAIN_VM = init_machine("test0", "test1");	
	
	while (1) {
		printf(">>>>> ");
		BUFFER = read_line();
		TOKS = split_line(BUFFER);
		if (TOKS[0] == NULL)	
			continue;
		if (strncmp(TOKS[0], "STOP", 4) == 0)
			break;
		decode_instruction(MAIN_VM, TOKS);
	}
	shutdown_machine(MAIN_VM);
	printf("Machine shutdown successful\n");	
}

char *read_line(void) {
	char *line = NULL;
	ssize_t bufsize = BUF_SIZE;
	getline(&line, &bufsize, stdin);
	return line;
}

char **split_line(char *line) {
	int bufsize = BUF_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	token = strtok(line, DELIMS);
	while (token != NULL) {
		tokens[position] = token;
		position++;
		token = strtok(NULL, DELIMS);
	}	
	tokens[position] = NULL;
	return tokens;
}
