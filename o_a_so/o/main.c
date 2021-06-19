#include "file.h"

unsigned long long atoull(char *s) {
	unsigned long long n;
	for (n = 0; *s; ++s) {
		// left shift existing value
		// to append new digit
		n = n * 10 + (*s - '0');
	}
	return n;
}

int main(int argc, char *argv[]) {
	if (argc == 1) return -1;
	return isprime(atoull(argv[1]));
}
