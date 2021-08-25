#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <DNA code>\n", argv[0]);
		fflush(stderr);
	}
	else {
		const char *dna_code = argv[1];
		char code;
		while (*dna_code) {
			switch (*dna_code) {
			case 'A':
			case 'a': code = 'U';
				break;
			case 'T':
			case 't': code = 'A';
				break;
			case 'C':
			case 'c': code = 'G';
				break;
			case 'G':
			case 'g': code = 'C';
				break;
			default:
				code = 'X';
			}
			putchar(code);
			dna_code++;
		}
		putchar('\n');
		fflush(stdout);
	}
	return 0;
}
