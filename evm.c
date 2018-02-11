#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "evm.h"

// Large machine ops
Machine *init_machine(char *c0_name, char *c1_name) {
        Machine *ret = (Machine *) malloc(sizeof(Machine));
	ret->c0 = (Contract *) malloc(sizeof(Contract));
	(ret->c0)->name = c0_name;
	ret->c1 = (Contract *) malloc(sizeof(Contract));
	(ret->c1)->name = c1_name;
	ret->PC = 0;
	ret->SP = -1;
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
	if (dest->SP == -1)
                empty_stack_err("stack_duplicate");
	stack_push(dest, *(dest->STACK));
}

void stack_print(Machine *dest) {
	int i;
	printf("[top]\n");
	for (i = dest->SP; i >= 0; i--) {
		printf("%u\n", dest->STACK[i]);
	}
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