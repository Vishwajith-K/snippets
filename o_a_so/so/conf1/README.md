- This configuration compiles both source files, creates a shared object file from
`file.o`, dynamically links the `so` file with `main.o` to create `isprime.out`
- build guide: `make` _or_ `gcc -o file.o -c -fpic file.c && gcc -o main.o -c main.c \
 && gcc -shared -o libprime.so file.o && gcc -o isprime.out main.o -L. -lprime`
- unbuild: `make clean`
- usage: `export LD_LIBRARY_PATH=<backtick>pwd<backtick>:$LD_LIBRARY_PATH` once
 in each terminal, and `./isprime.out <number> ; echo $?` when we wish to run
- rets:
  - 1 => `number` is prime
  - 0 => `number` is composite/non-prime
  - 255 => `number` is not-supplied!