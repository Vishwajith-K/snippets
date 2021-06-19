SRC := main.c prime.c stoz.c
LIBS := prime

# consider all the source files as object files except the ones in LIBS variable
# append .c to LIBS then filter them out from SRC; convert remaining .c to .o
isprime.out: $(subst .c,.o, $(filter-out $(addsuffix .c, $(LIBS)), $(SRC))) $(addsuffix .a, $(addprefix lib, $(LIBS)))
	gcc -o $@ $(filter %.o, $^) -L. $(subst .a,,$(subst lib,-l,$(filter %.a, $^)))

%.o: %.c
	gcc -o $@ -c $<

lib%.a: %.o
	ar rcs $@ $^

all: isprime.out

clean:
	@rm -f *.i *.o *.s *.a *.so *.out *~

# This declaration preserves intermediary files
# check site:www.gnu.org "Chains" "of" "Implicit" "Rules"
# comment the below line, make clean, make to see the difference
.PRECIOUS: $(subst .c,.o,$(SRC)) $(addsuffix .a, $(addprefix lib, $(LIBS)))
