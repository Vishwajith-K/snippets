.PHONY: all
all: Makefile buf_queue.c buf_queue.h driver.c
	gcc buf_queue.c driver.c

.PHONY: help
help:
	@echo "gcc buf_queue.c driver.c # -> to build"
	@echo "Allowed defines:"
	@echo -n "\t"
	@echo "Q_PRINT_DELIM : a string delim; displayed b/w 2 queue elements"
	@echo -n "\t"
	@echo "THRESHOLD : +ve int; number of array elements in each node of linked-list"
	@echo -n "\t"
	@echo "Q_GBG_MAX : +ve int; maximum number of garbage elements that can be parked"

.PHONY: clean
clean:
	rm -f *.out *.*~ *~
