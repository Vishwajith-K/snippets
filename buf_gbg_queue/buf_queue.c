#include <stdio.h>
#include <stdlib.h>

#include "buf_queue.h"

// delim that shall be displayed between 2 queue elements
// when print api is called
#ifndef Q_PRINT_DELIM
#define Q_PRINT_DELIM " < "
#endif // Q_PRINT_DELIM

status_t buf_enque(buf_queue_t *q, unsigned int data) {
	if (!q) return FAIL;

	// getting called for first time
	// get a node into front and rear
	// insert data
	// create loop
	// reset rest
	if (q->rear == NULL) {
		q->front = q->rear = malloc(sizeof(*(q->rear)));
		if (q->rear == NULL) return NOMEM;
		q->rear->data[q->rin = q->fin = q->gc = 0] = data,
			q->rear->next = q->rear;
		return SUCCESS;
	}

	// rear points to garbage
	// make front point to rear
	// negative of gc is an indication that the rear is garbage
	// but the actual gc is sign reversed of gc itself
	// change gc's sign and dec it
	// reset other parameters
	if (q->gc < 0) {
		q->front = q->rear,
			q->rear->data[q->rin = q->fin = 0] = data;
		q->gc = -q->gc;
		--q->gc;
		return SUCCESS;
	}

	// current node is full
	// get new node
	// either from garbage
	// or from system
	if (q->rin == THRESHOLD-1) {
		// attach new node next to rear
		// set it as rear
		// set rear's next to front (no garbage)
		// if (q->gc == 0) {
		if (q->rear->next == q->front) {
			q->rear->next = malloc(sizeof(*(q->rear)));
			if (!q->rear->next) return NOMEM;
			q->rear = q->rear->next;
			q->rear->next = q->front;
		}
		// if there's garbage then use it
		// dec count
		else {
			q->rear = q->rear->next;
			--q->gc;
		}
		q->rin = -1;
	}
	q->rear->data[++q->rin] = data;
	return SUCCESS;
}

status_t buf_deque(buf_queue_t *q, unsigned int *data) {
	if (!q || !data) return FAIL;
	if (q->gc < 0) return FAIL;

	*data = q->front->data[q->fin];
	// same node
	if (q->rear == q->front) {
		if (q->rin == q->fin) {
			if (q->gc < Q_GBG_MAX) {
				++q->gc; q->gc = -q->gc;
			}
			else {
				q->gc = -q->gc;
				if (q->rear->next == q->front) {
					// single node in the complete loop
				}
				else {
					// free any one element and re-establish the links
					node_t *t;
					t = q->rear->next;
					q->rear->next = t->next;
					free(t);
				}
			}
		}
		else
			++q->fin;
	}
	else if (q->fin == THRESHOLD - 1) {
		if (q->gc == Q_GBG_MAX) {
			node_t *t;
			if (q->rear->next == q->front) {
				q->fin = 0;
				t = q->front;
				q->front = t->next;
				free(t);
				q->rear->next = q->front;
			}
			else {
				q->front = q->front->next;
				q->fin = 0;
				t = q->rear->next;
				q->rear->next = t->next;
				free(t);
			}
		}
		else {
			q->fin = 0;
			q->front = q->front->next;
			++q->gc;
		}
	}
	else {
			++q->fin;
	}
	/* // same node */
	/* if (q->rear == q->front) { */
	/* 	// same element => free all incl garbage (if any) */
	/* 	if (q->rin == q->fin) { */
	/* 		node_t *t, *tt; */

	/* 		t = q->front->next; */
	/* 		while (t != q->front) { */
	/* 			tt = t->next; */
	/* 			free(t); */
	/* 			t->next = t; */
	/* 		} */
	/* 		free(q->front); */
	/* 		*q = (buf_queue_t) {}; */
	/* 	} */
	/* 	else */
	/* 		q->fin++; */
	/* } */
	/* else { */
	/* 	if (q->fin == THRESHOLD-1) { */
	/* 		node_t *t; */

	/* 		t = q->front; */
	/* 		q->front = q->front->next; */
	/* 		q->fin = 0; */
	/* 		free(t); */
	/* 	} */
	/* 	else */
	/* 		q->fin++; */
	/* } */
	return SUCCESS;
}

void buf_qprint(const buf_queue_t *q) {
	node_t *cur;
	short i;
	if (!q || q->gc < 0) return;

	// print everything till rear (excl)
	for (cur = q->front, i = q->fin;
		 cur != q->rear;
		 cur = cur->next, i = 0) {
		while (i < THRESHOLD)
			printf("%u" Q_PRINT_DELIM, cur->data[i++]);
	}

	// cur is at rear now
	while(i <= q->rin) {
		// printf("%d", i++);
		printf("%u" Q_PRINT_DELIM, cur->data[i++]);
	}
	puts("X");
}

unsigned int buf_qcount(const buf_queue_t *q) {
	node_t *cur;
	unsigned int count;

	if (!q || !q->front || !q->rear || q->gc < 0) return 0;
	for (count = 1, cur = q->front;
		 cur != q->rear && (++count);
		 cur = cur->next);
	
	return count;
}
