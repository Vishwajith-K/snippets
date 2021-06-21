#gcc -o file.o -c -fpic file.c && gcc [SWITCH] -o\
 main.o -c main.c && gcc -shared -o libprime.so file.o && gcc -o isprime.out\
 main.o -ldl

SRC := main.c file.c

isprime.out: main.o libprime.so
	gcc -o $@ $(filter %.o, $^) -ldl

main.o: main.c file.h
	gcc -o $@ -c $<

%.o: %.c
	gcc -o $@ -c -fpic $<

libprime.so: $(subst .c,.o,$(filter-out main.c, $(SRC)))
	gcc -shared -o $@ $^

.PHONY:all
all: isprime.out

.PHONY:clean
clean:
	@rm -f *.i *.o *.s *.a *.so *.out *~
