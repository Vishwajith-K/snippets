- This configuration compiles both source files, creates an archive file from `file.o`,
statically links the archive file with main.o to create `isprime.out`
- build guide: `make` _or_ `gcc -o file.o -c file.c && gcc -o main.o -c main.c \
&& ar rcs libprime.a file.o && gcc -o isprime.out main.o -L. -lprime`
- unbuild: `make clean`
- usage: `./isprime.out <number> ; echo $?`
- rets:
  - 1 => `number` is prime
  - 0 => `number` is composite/non-prime
  - 255 => `number` is not-supplied!