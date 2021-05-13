#include <stdio.h>
#include <stdlib.h>

#ifndef DEFAULT
#define DEFAULT 10
#endif

int main(int arg_count, char **args) {
	volatile int i, j;
	int n = DEFAULT;
	const char *s = args[0];

	if (arg_count > 1)
		n = atoi(args[1]);
	else {
		while (*s && !(*s >= '0' && *s <= '9'))
			s++;
		if (*s)
			n = atoi(s);
	}
	for (i = 0; i < n; ++i) {
		for (j = 0xFFFFFFF >> 1; j; --j);
		putchar('\a');
		fflush(stdout);
	}

	return 0;
}
