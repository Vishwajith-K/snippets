#include "prime.h"
#include "stoz.h"

int main(int argc, char *argv[]) {
	if (argc == 1) return -1;
	return isprime(atoull(argv[1]));
}
