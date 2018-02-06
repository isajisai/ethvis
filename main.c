#include "evm.h"

int main(void) {
	// Buffers
	char *BUFFER = (char *) malloc(1000);
	char *TOKS; 
	char *TOK0 = (char *) malloc(20);
	char *TOK1 = (char *) malloc(20);
	char *TOK2 = (char *) malloc(20);
	char *TOK3 = (char *) malloc(20);
	char enter;
	int i;
	
	Machine *MAIN_VM = init_machine("test0", "test1");	
	
	while (1) {
		printf(">>> ");
		fgets(BUFFER, 1000, stdin);
		TOKS = strtok(BUFFER, " ,.-");
		
		TOK0 = TOKS;
		TOKS = strtok(NULL, " ,.-");
		TOK1 = TOKS;
		TOKS = strtok(NULL, " ,.-");
                TOK2 = TOKS;
		TOKS = strtok(NULL, " ,.-");
                TOK3 = TOKS;
		if (strncmp(TOK0, "EXIT", 4) == 0) 
			break;
		TOK0[0] = '\0';
		TOK1[0] = '\0';
		TOK2[0] = '\0';
		TOK3[0] = '\0';
		BUFFER[0] = '\0';
	}

	shutdown_machine(MAIN_VM);
	printf("Machine shutdown successful\n");	
}
