#ifndef __BUF_QUEUE_H__
#define __BUF_QUEUE_H__

#define THRESHOLD 5

typedef enum _status {SUCCESS, FAIL = -1, NOMEM = -2} status_t;

typedef struct _node {
	unsigned int data[THRESHOLD];
	struct _node *next;
} node_t;

typedef struct _buf_queue {
	node_t *front, *rear;
	short fin, rin;
} buf_queue_t;

status_t buf_enque(buf_queue_t *q, unsigned int data);
status_t buf_deque(buf_queue_t *q, unsigned int *data);
void buf_qprint(const buf_queue_t *q);
unsigned int buf_qcount(const buf_queue_t *q);

#endif // __BUF_QUEUE_H__
