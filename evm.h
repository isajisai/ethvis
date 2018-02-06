#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
	uint32_t SP;
	uint32_t REG[32];
	uint32_t MEM[MEMORY_SPACE];
	uint32_t STACK[STACK_SPACE];
	Contract *c0;
	Contract *c1;
} Machine;

//####################################################
Machine *init_machine(char *, char *);
void shutdown_machine(Machine *);

void stack_push(Machine *, uint32_t);
uint32_t  stack_pop(Machine *);
void stack_duplicate(Machine *);

void stack_overflow_err();
void empty_stack_err(char *);
void size_err(char *);
//####################################################

// Large machine ops
Machine *init_machine(char *c0_name, char *c1_name) {
        Machine *ret = (Machine *) malloc(sizeof(Machine));
	ret->c0 = (Contract *) malloc(sizeof(Contract));
	(ret->c0)->name = c0_name;
	ret->c1 = (Contract *) malloc(sizeof(Contract));
	(ret->c1)->name = c1_name;
	ret->PC = 0;
	ret->SP = 0;
	return ret;
}

void shutdown_machine(Machine *dest) {
	free(dest->c0);
	free(dest->c1);
	free(dest);
}

// Stack ops
void stack_push(Machine *dest, uint32_t item) {
	if (dest->SP >= STACK_SPACE)
		stack_overflow_err();
	if (dest->SP != 0)
		dest->SP++;
       	dest->STACK[dest->SP] = item;
}

uint32_t stack_pop(Machine *dest) {
	uint32_t tmp = dest->STACK[dest->SP];
	dest->STACK[dest->SP] = 0;
	dest->SP--;
	return tmp;
}

void stack_duplicate(Machine *dest) {
	if (dest->SP == 0)
                empty_stack_err("stack_duplicate");
	stack_push(dest, *(dest->STACK));
}

// Errors
void stack_overflow_err() {
        printf("[!!!] Fatal error: stack overflow.\n");
        exit(-1);
}

void empty_stack_err(char *name) {
        printf("[!!!] Fatal error: %s from empty stack.\n", name);
        exit(-1);
}

void size_err(char *name) {
        printf("[!!!] Fatal error: %s called with insufficient sized stack.\n", name);
        exit(-1);
}
