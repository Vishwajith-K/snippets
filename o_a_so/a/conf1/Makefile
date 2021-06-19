SRC := main.c file.c

isprime.out: main.o libprime.a
#	echo $(subst lib_, -l, $(filter %.a, $^))
	gcc -o $@ $(filter %.o, $^) -L. $(subst .a,,$(subst lib,-l,$(filter %.a, $^)))

%.o: %.c
	gcc -o $@ -c $<

libprime.a: $(subst .c,.o,$(filter-out main.c, $(SRC)))
	ar rcs $@ $^

all: isprime.out

clean:
	@rm -f *.i *.o *.s *.a *.so *.out *~
