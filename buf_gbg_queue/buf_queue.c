#include <stdio.h>
#include <stdlib.h>

#include "buf_queue.h"

#ifndef Q_PRINT_DELIM
#define Q_PRINT_DELIM " < "
#endif // Q_PRINT_DELIM

status_t buf_enque(buf_queue_t *q, unsigned int data) {
	if (!q) return FAIL;
	// getting called for first time
	if (!q->rear) {
		q->rear = q->front = malloc(sizeof(*(q->rear)));
		if (!q->rear) return NOMEM;
		q->rear->data[q->rin = q->fin = 0] = data,
			q->rear->next = NULL;
		return SUCCESS;
	}
	// current node is full
	if (q->rin == THRESHOLD-1) {
		q->rear->next = malloc(sizeof(*(q->rear)));
		if (!q->rear->next) return NOMEM;
		q->rin = -1;
		q->rear = q->rear->next,
			q->rear->next = NULL;
	}
	q->rear->data[++q->rin] = data;
	return SUCCESS;
}

status_t buf_deque(buf_queue_t *q, unsigned int *data) {
	if (!q || !data) return FAIL;
	if (! q->front) return FAIL;
	*data = q->front->data[q->fin];
	if (q->rear == q->front) {
		if (q->rin == q->fin) {
			free(q->front);
			*q = (buf_queue_t) {};
		}
		else
			q->fin++;
	}
	else {
		if (q->fin == THRESHOLD-1) {
			node_t *t;

			t = q->front;
			q->front = q->front->next;
			q->fin = 0;
			free(t);
		}
		else
			q->fin++;
	}
	return SUCCESS;
}

void buf_qprint(const buf_queue_t *q) {
	node_t *cur;
	short i;
	if (!q) return;
	// print everything till rear (excl)
	for (cur = q->front, i = q->fin;
		 cur != q->rear;
		 cur = cur->next, i = 0) {
		while (i < THRESHOLD)
			printf("%u" Q_PRINT_DELIM, cur->data[i++]);
	}

	if (cur) {
		// cur is at rear now
		while(i <= q->rin) {
			// printf("%d", i++);
			printf("%u" Q_PRINT_DELIM, cur->data[i++]);
		}
	}
	puts("X");
}

unsigned int buf_qcount(const buf_queue_t *q) {
	node_t *cur;
	unsigned int count;

	for (count = 0, cur = q->front;
		 cur && (++count);
		 cur = cur->next);
	
	return count;
}
