#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int data;
	struct node *next;
} sll;
typedef enum status {ESAME = -4, EINSUFF = -3, ENOFOUND = -2, ENOMEM = -1, SUCCESS = 0} status;

status sll_ins_end(sll **h, int data) {
	if (! *h) {
		*h = malloc(sizeof(sll));
		if (! *h) return ENOMEM;
		(*h)->data = data;
		(*h)->next = NULL;
	}
	else {
		sll *t;
		for (t = *h; t->next; t = t->next);
		t->next = malloc(sizeof(sll));
		if (! (t->next)) return ENOMEM;
		t->next->data = data;
		t->next->next = NULL;
	}
	return SUCCESS;
}

void sll_print(sll **h) {
	sll *head;
    
	for (head = *h; head; head = head->next)
		printf("(%d)->", head->data);
	puts("#");
}

status sll_del_all_key(sll **h, int key) {
	if (! (*h)) return ENOFOUND;
	else {
		sll *c, *t;
		// if head and elements contiguous to head
		// match key, then remove them and proceed
		while (*h && (*h)->data == key) {
			t = *h;
			*h = (*h)->next;
			free(t);
		}
		if (! (*h)) return SUCCESS;

		// stay at an element and access next element
		// compare and delete if matches with the key
		// if deleted then, don't step through
		// else step
		c = *h;
		while (c->next) {
			if (c->next->data == key) {
				t = c->next;
				c->next = t->next;
				free(t);
			}
			else
				c = c->next;
		}
	}
	return SUCCESS;
}

status sll_del_first_key(sll **h, int key) {
	if (! (*h)) return ENOFOUND;
	else {
		sll *c, *t;
		if ((*h)->data == key) {
			t = *h;
			*h = t->next;
			free(t);
			return SUCCESS;
		}
		c = *h;
		while (c->next) {
			if (c->next->data == key) {
				t = c->next;
				c->next = t->next;
				free(t);
				return SUCCESS;
			}
			c = c->next;
		}
	}
	return ENOFOUND;
}

status sll_del_pos(sll **h, unsigned int pos) {
	if (! (*h)) return EINSUFF;
	else {
		sll *t, *t1;
		unsigned int i;
		if (pos == 0) {
			t = *h;
			*h = t->next;
			free(t);
			return SUCCESS;
		}
		for (t = *h, i = 0; i < pos - 1; ++i) {
			if (t) 
				t = t->next;
			else
				return EINSUFF;
		}
		if (! (t->next))  return EINSUFF;
		t1 = t->next;
		t->next = t1->next;
		free(t1);
		return SUCCESS;
	}
}

unsigned int sll_len(sll *h) {
	unsigned int cnt = 0;
	for (; h; cnt++, h = h->next);
	return cnt;
}

status sll_swap_link(sll **h, int a, int b) {
	// contiguous elements - ok
	// head is one among the elements - ok
	// one/both elements does not exist - ok
	// same elements - ok
    
	// if atleast two elements doesn't exist or if both are same,
	// we don't know what to do and of-course, swapping them makes no sense
	// at-least in this sll
	if (! ((*h) && (*h)->next)) return EINSUFF;
	if (a == b) return ESAME;
	else {
		sll *t, *ta, *ta1, *ta2, *tb, *tb1, *tb2;
        
		if ((*h)->data == b || (*h)->data == a) {
			// head is one among the element
			// make sure ta will point to head to ease up later process
			// if not swap a, b
			if ((*h)->data == b) {
				int temp;
				temp = a;
				a = b;
				b = temp;
			}
			ta = *h;
			// if 2nd element is b then, do below
			if ((*h)->next->data == b) {
				tb = (*h)->next;
				*h = tb;
				ta->next = tb->next;
				tb->next = ta;
			}
			else {
				// if 2nd element is not b it'd exist elsewhere in the list
				for (t = (*h)->next; t->next; t = t->next) {
					if (t->next->data == b) {
						tb = t;
						break;
					}
				}
				if (! tb) return EINSUFF;
				tb1 = tb->next;
				tb2 = tb1->next;
				*h = tb1;
				tb1->next = ta->next;
				tb->next = ta;
				ta->next = tb2;
			}
			return SUCCESS;
		}
        
		// find previous element of matched node, so that relinking becomes easy
		// one more method is to keep track of previous element while holding
		// matched element; it's not followed here
		for (t = *h, ta = ta1 = ta2 = tb = tb1 = tb2 = NULL; t->next; t = t->next) {
			if (!ta && t->next->data == a) ta = t;
			else
				if (!tb && t->next->data == b) tb = t;
			if (ta && tb) break;
		}
        
		// if none/one doesn't exist in the list, return
		if (ta && tb) {
			// if given elements are contiguous
			if (ta->next == tb) {
				ta1 = ta->next;
				tb1 = tb->next;
				ta->next = tb1;
				tb->next = tb1->next;
				tb1->next = ta1;
			}
			else if (tb->next == ta) {
				ta1 = ta->next;
				tb1 = tb->next;
				tb->next = ta1;
				ta->next = ta1->next;
				ta1->next = tb1;
			}
			else {
				// elements are non-contiguous
				ta1 = ta->next;
				ta2 = ta1->next;
				tb1 = tb->next;
				tb2 = tb1->next;
                
				ta->next = tb1;
				tb1->next = ta2;
				tb->next = ta1;
				ta1->next = tb2;
			}
		}
		else
			return ENOFOUND;
		return SUCCESS;
	}
}

int main() {
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n, i;
	sll *l1 = NULL;
	n = sizeof(data) / sizeof(data[0]);
	for (i = 0; i < n; ++i) {
		if (sll_ins_end(&l1, data[i]) == ENOMEM)
			puts("ENOMEM");
		// else
		// puts("SUCCESS");
	}
	// printf("%d, %d\n", n, sll_len(l1));
	sll_print(&l1);
	sll_swap_link(&l1, 10, 1);
	sll_print(&l1);

	return 0;
}
