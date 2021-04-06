// Who says that, C has no error checking mechnism?
// The following code tries to mimic/emulate/whatever
// try-catch style from C++, Java lang. I haven't seen
// an implementation of try-catch in them;
// may be they are using similar approach.
// However, it's left to compiler coder (shrug)

// Code tries to find average of command-line arguments
// If no elements are supplied, the function throws
// an error by making use of longjmp

// Idea & partial-code credits: Jacob Sorber
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf checkpoint1;
int exception1_val;

enum __errors {ERR_NOARGS = -1};
#define TRY if ((exception1_val = setjmp(checkpoint1)) == 0)
#define CATCH(NUM) else if (exception1_val == NUM)
#define CATCHALL else
#define THROW(NUM) longjmp(checkpoint1, NUM)

double calculate_avg(double *values, unsigned int n) {
	unsigned int i;
	double sum = 0;
	
	if (n == 0) {
		THROW(ERR_NOARGS);
	}
	else {
		for (i = 0; i < n; ++i)
			sum += values[i];
	}
	
	return (sum / (double) n);
}

int main(int argc, char **argv) {
	double *values;
	unsigned int i;

	values = (double *) malloc(sizeof(*values) * (argc - 1));
	// assuming that we have ZBs of heap section (wink)
	for (i = 1; i < argc; ++i)
		values[i - 1] = atof(argv[i]);
	
	TRY {
		printf("Average of doubles: %.2f\n", calculate_avg(values, argc - 1));
	}
	CATCH(5) {
		printf("Caught something else: %d\n", exception1_val);
	}
	CATCHALL {
		printf("Error at %s in %s() at %d'th line\n", __FILE__, __FUNCTION__, __LINE__);
		printf("Typical usage: exe_name <real_no1> <real_no2>...\n");
	}
	return 0;
}