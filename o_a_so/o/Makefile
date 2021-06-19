SRC := main.c file.c

isprime.out: $(SRC:.c=.o)
	gcc -o $@ $?

*.o: *.c
	gcc -o $@ -c $<

all: isprime.out

clean:
	@rm -f *.i *.o *.s *.out *~
