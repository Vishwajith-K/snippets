#ifndef __BUF_QUEUE_H__
#define __BUF_QUEUE_H__

// number of array elements in each node of the
// singly linked list
#ifndef THRESHOLD
#define THRESHOLD 3
#endif // THRESHOLD

// maximum garbage nodes that can be parked
#ifndef Q_GBG_MAX
#define Q_GBG_MAX 2
#endif // Q_GBG_MAX

typedef enum _status {SUCCESS, FAIL = -1, NOMEM = -2} status_t;

typedef struct _node {
	unsigned int data[THRESHOLD];
	struct _node *next;
} node_t;

// nodes of queue may be visualized like
// front -> node ... -> node -> rear -> garbage
//   ^-- garbage <- garbage ... <- garbage <-v
// front points to the node that will be considered for next deque
// rear points to the node that will be considered for next enque
// fin shorts for front index - array index till which elements of
// front node are valid
// rin shorts for rear index - array index till which elements of
// rear node are valid
// gc shorts for garbage count - number of nodes chained after
// rear node of the queue
typedef struct _buf_queue {
	node_t *front, *rear;
	short fin, rin, gc;
} buf_queue_t;

status_t buf_enque(buf_queue_t *q, unsigned int data);
status_t buf_deque(buf_queue_t *q, unsigned int *data);
void buf_qprint(const buf_queue_t *q);
unsigned int buf_qcount(const buf_queue_t *q);

#endif // __BUF_QUEUE_H__
