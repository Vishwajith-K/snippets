unsigned long long atoull(char *s) {
	unsigned long long n;
	for (n = 0; *s; ++s) {
		// left shift existing value
		// to append new digit
		n = n * 10 + (*s - '0');
	}
	return n;
}
