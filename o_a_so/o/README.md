- build guide: `make` _or_ `gcc -o file.o -c file.c && gcc -o main.o -c main.c
&& gcc -o isprime.out main.o file.o`
- unbuild: `make clean`
- usage: `./isprime.out <number> ; echo $?`
- rets:
  - 1 => `number` is prime
  - 0 => `number` is composite/non-prime
  - 1 => `number` is not-supplied!
