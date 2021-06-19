// #include "file.h" // not actually req

unsigned short isprime(unsigned long long n) {
	if (n == 1) return 0;
	else
		switch (n) {
		case 2:
		case 3:
		case 5:
		case 7: return 1;
		}
	{
		unsigned long long i;
		// not willing to use math.h for sqrt
		for (i = 2; i < (n / 2 + 1); ++i)
			if (n % i == 0) return 0;
	}
	return 1;
}
