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
		case 6384517835: { // STOP
			shutdown_machine(dest);
			printf("Machine shutdown successful; exiting...\n");
			exit(1);
		} case 6384411237: { // PUSH
			if (tokens[1] == NULL) {	
				fprintf(stderr, "[!!!] decode: { malformed PUSH\n");
				break;
			}
			stack_push(dest, (uint32_t) atoi(tokens[1]));
			break;
		} case 210685452402: { // PRINT
			if (tokens[1] != NULL) {
                fprintf(stderr, "[!!!] decode: { malformed PRINT\n");
                break;
			}
			stack_print(dest);
			break;
		} case 193450094: { // ADD
			stack_push(dest, stack_pop(dest) + stack_pop(dest));
			break;
		} case 193463731: { // MUL
            stack_push(dest, stack_pop(dest) * stack_pop(dest));
            break;
        } case 193470255: { // SUB
            stack_push(dest, stack_pop(dest) - stack_pop(dest));
            break;
        } case 193453544: { // DIV
            stack_push(dest, stack_pop(dest) / stack_pop(dest));
            break;
        } case 6384500219: { // SDIV
            stack_push(dest, (int32_t) stack_pop(dest) / (int32_t) stack_pop(dest));    
            break;
		} case 193463525: { // MOD
			stack_push(dest, stack_pop(dest) % stack_pop(dest));
			break;	
        } case 6384510200: { // SMOD
            stack_push(dest, (int32_t) stack_pop(dest) % (int32_t) stack_pop(dest));    
            break;
        } case 6952016114606: {	// ADDMOD
            stack_push(dest, (stack_pop(dest) + stack_pop(dest)) % (uint32_t) atoi(tokens[1]));                       
            break;		
        } case 6952506187475: { // MULMOD
            stack_push(dest, (stack_pop(dest) * stack_pop(dest)) % (uint32_t) atoi(tokens[2]));      
            break;
        } case 193455122: { // POW
            stack_push(dest, pow(stack_pop(dest), stack_pop(dest)));                             
            break;
        } case 5862501: { // LT
			uint32_t top = stack_pop(dest);
			uint32_t bot = stack_pop(dest);
			if (top < bot)
				stack_push(dest, (uint32_t) 1);
			else 
				stack_push(dest, (uint32_t) 0);
            break;
        } case 5862336: { // GT
			uint32_t top = stack_pop(dest);
            uint32_t bot = stack_pop(dest);
            if (top > bot)
                    stack_push(dest, (uint32_t) 1);
            else 
                    stack_push(dest, (uint32_t) 0);
            break;
        } case 193469976: { // SLT
			uint32_t top = stack_pop(dest);
            uint32_t bot = stack_pop(dest);
            if ((int32_t) top < (int32_t) bot)
                    stack_push(dest, (uint32_t) 1);
            else 
                    stack_push(dest, (uint32_t) 0);
            break;
        } case 193469811: { // SGT
			uint32_t top = stack_pop(dest);
            uint32_t bot = stack_pop(dest);
            if ((int32_t) top > (int32_t) bot)
                    stack_push(dest, (uint32_t) 1);
            else
                    stack_push(dest, (uint32_t) 0);
            break;	
		} case 5862267: { // EQ
			uint32_t top = stack_pop(dest);
            uint32_t bot = stack_pop(dest);
            if (top == bot)
                    stack_push(dest, (uint32_t) 1);
            else
                    stack_push(dest, (uint32_t) 0);
            break;	
		} case 6952347768577: { // ISZERO
			uint32_t top = stack_pop(dest);
            if (top == 0)
                    stack_push(dest, (uint32_t) 1);
            else
                    stack_push(dest, (uint32_t) 0);
            break;	
		} case 193450424: { // AND
            stack_push(dest, stack_pop(dest) & stack_pop(dest));
            break;	
		} case 5862598: { // OR
			stack_push(dest, stack_pop(dest) | stack_pop(dest));
            break;	
		} case 193475518: { // XOR
			stack_push(dest, stack_pop(dest) ^ stack_pop(dest));
            break;	
		} case 193464630: { // NOT
			stack_push(dest, ~stack_pop(dest));
            break;	
		} case 6383912505: { // BYTE <UNDER CONSTRUCTION>
			printf("BYTE opcode under construction...\n");
            break;	
		} default: {
			printf("Aww...\n");
			break;
		}
	}
}
