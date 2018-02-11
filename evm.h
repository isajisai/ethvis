#include <stdlib.h>
#include <stdio.h>

#define MEMORY_SPACE (10*1024*1024)
#define STACK_SPACE (1024*1024)
#define CONTRACT_SPACE (2*1024*1024)

typedef uint8_t byte;
typedef uint16_t word; 

typedef struct contract {
	uint32_t STORAGE[CONTRACT_SPACE];
	char *name;
} Contract;

typedef struct machine {
	uint32_t PC;
	int SP;
	uint32_t REG[32];
	uint32_t MEM[MEMORY_SPACE];
	uint32_t STACK[STACK_SPACE];
	Contract *c0;
	Contract *c1;
} Machine;

Machine *init_machine(char *, char *);
void shutdown_machine(Machine *);
void stack_push(Machine *, uint32_t);
uint32_t  stack_pop(Machine *);
void stack_duplicate(Machine *);
void stack_overflow_err();
void empty_stack_err(char *);
void size_err(char *);