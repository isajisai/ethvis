
unsigned long hash(unsigned char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash;
}

void decode_instruction(char **tokens) {
	switch (hash(tokens[0])) {
		case 6384411237:
			printf("YEAAAAA");
			break;
		default:
			printf("Aww...");
			break;
	}
}
