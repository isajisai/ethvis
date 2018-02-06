#include "evm.h"
#include <math.h>

unsigned long hash(unsigned char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash;
}

void decode_instruction(Machine *dest, char **tokens) {
	switch (hash(tokens[0])) {
		// PUSH
		case 6384411237:
			if (tokens[1] == NULL) {	
				fprintf(stderr, "[!!!] decode: malformed PUSH\n");
				break;
			}
			stack_push(dest, (uint32_t) atoi(tokens[1]));
			break;
		// PRINT
		case 210685452402:
			if (tokens[1] != NULL) {
                                fprintf(stderr, "[!!!] decode: malformed PRINT\n");
                                break;
			}
			stack_print(dest);
			break;
		
		// ADD
		case 193450094:
			stack_push(dest, stack_pop(dest) + stack_pop(dest));
			break;
		// MUL
                case 193463731:
                        stack_push(dest, stack_pop(dest) * stack_pop(dest));
                        break;
		// SUB
                case 193470255:
                        stack_push(dest, stack_pop(dest) - stack_pop(dest));
                        break;
		// DIV
                case 193453544:
                        stack_push(dest, stack_pop(dest) / stack_pop(dest));
                        break;
		// SDIV 
                case 6384500219:
                        stack_push(dest, (int32_t) stack_pop(dest) % (int32_t) stack_pop(dest));    
                        break;
		// MOD 
		case 193463525:
			stack_push(dest, stack_pop(dest) % stack_pop(dest));
			break;
		// SMOD 
                case 6384510200:
                        stack_push(dest, (int32_t) stack_pop(dest) % (int32_t) stack_pop(dest));    
                        break;
		// ADDMOD
                case 6952016114606:	
                        stack_push(dest, (stack_pop(dest) + stack_pop(dest)) % (uint32_t) atoi(tokens[1]));                       
                        break;		
		// MULMOD
                case 6952506187475:
                        stack_push(dest, (stack_pop(dest) * stack_pop(dest)) % (uint32_t) atoi(tokens[2]));      
                        break;
		// EXP
                case 193455122:
                        stack_push(dest, pow(stack_pop(dest), stack_pop(dest)));                             
                        break;
		default:
			printf("Aww...\n");
			break;
	}
}
