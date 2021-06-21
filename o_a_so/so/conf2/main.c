#ifdef DEBUG
#include <stdio.h>
#include <stdlib.h>
#define MY_ERROR_REPORT fprintf(stderr, "%s\n", dlerror())
#endif // DEBUG
#include <dlfcn.h>

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
	unsigned short (*isprime)(unsigned long long), ret;
	void *libprime;
	if (argc == 1) return -1;
	libprime = dlopen("libprime.so", RTLD_LAZY);
	if (!libprime) {
#ifdef DEBUG
		MY_ERROR_REPORT;
#endif // DEBUG
		return -2;
	}
	* (void **) (&isprime) = dlsym(libprime, "isprime");
	if (!isprime) {
#ifdef DEBUG
		MY_ERROR_REPORT;
#endif // DEBUG
		return -3;
	}
	ret = isprime(atoull(argv[1]));
	dlclose(libprime);
#ifdef TEST
	isprime(atoull(argv[1]));
#endif // TEST
	return ret;
}
