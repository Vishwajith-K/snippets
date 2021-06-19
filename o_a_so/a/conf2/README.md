- This configuration compiles all the source files, creates an archive file from `prime.o`,
& `stoz.o`, statically links the archive files with main.o to create `isprime.out`
- build guide: `make` _or_ `gcc -o prime.o -c prime.c && gcc -o main.o -c main.c \
 && gcc -o stoz.o -c stoz.c && ar rcs libprime.a prime.o && ar rcs libstoz.a stoz.o \
 && gcc -o isprime.out main.o -L. -lprime -lstoz`
- unbuild: `make clean`
- usage: `./isprime.out <number> ; echo $?`
- rets:
  - 1 => `number` is prime
  - 0 => `number` is composite/non-prime
  - 255 => `number` is not-supplied!
