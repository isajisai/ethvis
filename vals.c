#include "opcodes.h"

int main(void) {
	printf("STOP: %lu\n", hash("STOP"));
	printf("PUSH: %lu\n", hash("PUSH"));
	printf("POP: %lu\n", hash("POP"));
	printf("PRINT: %lu\n", hash("PRINT"));
	printf("ADD: %lu\n", hash("ADD"));
	printf("MUL: %lu\n", hash("MUL"));
	printf("SUB: %lu\n", hash("SUB"));
	printf("DIV: %lu\n", hash("DIV"));
	printf("SDIV: %lu\n", hash("SDIV"));
	printf("MOD: %lu\n", hash("MOD"));
	printf("SMOD: %lu\n", hash("SMOD"));
	printf("ADDMOD: %lu\n", hash("ADDMOD"));
	printf("MULMOD: %lu\n", hash("MULMOD"));
	printf("EXP: %lu\n", hash("EXP"));
	printf("SIGNEXTEND: %lu\n", hash("SIGNEXTEND"));
}
