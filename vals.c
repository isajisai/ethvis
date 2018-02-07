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
	printf("LT: %lu\n", hash("LT"));
	printf("GT: %lu\n", hash("GT"));
	printf("SLT: %lu\n", hash("SLT"));
	printf("SGT: %lu\n", hash("SGT"));
	printf("EQ: %lu\n", hash("EQ"));
	printf("ISZERO: %lu\n", hash("ISZERO"));
	printf("AND: %lu\n", hash("AND"));
	printf("OR: %lu\n", hash("OR"));
	printf("XOR: %lu\n", hash("XOR"));
	printf("NOT: %lu\n", hash("NOT"));
	printf("BYTE: %lu\n", hash("BYTE"));
}
