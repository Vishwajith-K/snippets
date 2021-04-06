// goto construct in C has scope and is limited to function
// There may be a need to jump across functions
// One of the C standard header itself has solution to address
// this issue/problem

// setjmp header provides 3 constructs: a datatype and two macros
// Set a checkpoint using a var of 'datatype' and then use the
// same var to jump back to the checkpoint; ta-da! time-machine is
// ready
// Following code is from tutorialspoint.com
#include <stdio.h>
#include <setjmp.h>

void jmpfunction(jmp_buf env_buf) {
	longjmp(env_buf, 10);
}

int main() {
	int val;
	jmp_buf env_buffer;

	// mark this as a checkpoint;
	// if longjmp is made with same env_buf,
	// it'd jump here again.
	// yeah, first time return will be a zero
	// and next returns depends on longjmp's param
	val = setjmp(env_buffer);
	
	if (val) {
		printf("Returned from a longjmp() with value = %d\n", val);
		return 0;
	}
	printf("Jump function call\n");
	jmpfunction(env_buffer);
	
	return 0;
}