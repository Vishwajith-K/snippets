- This configuration compiles both source files, creates a shared object file from
`file.o`, dynamically **loads** the `so` file with `main.o` to create `isprime.out`
- Dynamically loading = linking the `so` is unnessary and this so code changes are
are required. Try `man dlopen`
- build guide: `make` _or_ `gcc -o file.o -c -fpic file.c && gcc [SWITCH] -o\
 main.o -c main.c && gcc -shared -o libprime.so file.o && gcc -o isprime.out\
 main.o -ldl`. Where `SWITCH` can be:
  - `-DTEST` to validate `SEGMENTATION FAULT` after library is unloaded
  - `-DDEBUG` to get extra prints when error is encountered
- unbuild: `make clean`
- usage: `export LD_LIBRARY_PATH=<backtick>pwd<backtick>:$LD_LIBRARY_PATH` once
 in each terminal, and `./isprime.out <number> ; echo $?` when we wish to run
- rets:
  - 1 => `number` is prime
  - 0 => `number` is composite/non-prime
  - 254 => unable to locate the library; probably library isn't exported
  - 253 => may be symbol is not found! Try building same code with debug switch
  - 255 => `number` is not-supplied!