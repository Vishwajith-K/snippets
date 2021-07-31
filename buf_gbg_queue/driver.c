#include <stdio.h>

#include "buf_queue.h"

#ifndef MAX
#define MAX 100
#endif // MAX

static unsigned char isprime(unsigned int n) {
	if (n == 1 || n == 0) return 0;
	for (unsigned int i = 2; i < n / 2; ++i)
		if (n % i == 0) return 0;
	return 1;
}

int main(int arg_count, const char *arg_vector[]) {
	// declare and initialise queue with zeros
	buf_queue_t q = {};
	unsigned int temp;

	for (unsigned int i = 0; i < MAX; ++i) {
		// if (isprime(i)) {
		{	switch (buf_enque(&q, i)) {
			case SUCCESS:continue;
			case FAIL: fprintf(stderr, "NULL cannot be the reference for queue\n");
				break;
			case NOMEM: fprintf(stderr, "Unable to get memory from the system\n");
				break;
			default: fprintf(stderr, "Unknown error!!!\n");
			}
		}
	}
	/* buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp);buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp);buf_deque(&q, &temp); */
	/* buf_deque(&q, &temp);buf_deque(&q, &temp); */
	/* buf_qprint(&q); */
	/* printf("%d elements exist in the queue, %d gbg\n", buf_qcount(&q), q.gc); */
	/* buf_enque(&q, 10); */
	/* buf_qprint(&q); */
	printf("%d elements exist in the queue, %d gbg\n", buf_qcount(&q), q.gc);
	switch (buf_deque(&q, &temp)) {
	case SUCCESS:
		printf("%d was the first element in the queue\n", temp);
		break;
	case FAIL:
		fprintf(stderr, "Failed to deque - check arguments to deque are non-NULL and elements exist in the queue\n");
		break;
	default:
		fprintf(stderr, "Unknown error!!!\n");
	}
	buf_qprint(&q);
	return 0;
}
