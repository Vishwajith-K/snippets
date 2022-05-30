#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 100
int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch,s[MAX_LEN],sen[MAX_LEN]; /* s, sen are arrays of 100 byte long */
    scanf("%c",&ch); /* read single character */
    scanf("%s\n",s); /* read a string till a space or tab or new line is entered in terminal */
    scanf("%[^\n]%*c", sen); /* read a string till new line is entered */
    printf("%c\n", ch); /* anything in double quotes is called as string or even string literals */
    printf("%s\n", s);
    puts(sen); /* puts is another function which is unformatted std output function - available in stdlib.h */
    return 0; /* if you return 0 from main, caller in our case terminal gets this value. 0 usually means success */
}

/*
#define lines are replaced during pre-processing as it is.
These are not variables but're simple macros or sort of find & replace utils.
So, MAX_LEN whereever is found is replaced with 100 unless it's mentioned inside double quotes or single quotes.

Remember character array = string

Check this link for a list of format specifiers: https://github.com/Vishwajith-K/gist/issues/2

Notes:
When we hit ./a.out and hit enter, OS will copy entire a.out into RAM.
a.out contains assembly instructions all this will be marked as READ-ONLY in RAM - this section in RAM is called .code or .text.
.bss, .stack, .heap are other commonly defined sections when loading a.out in memory.
Once code is loaded in memory, a fixed section .bss is reserved which will contain all global variables, static variables & their values are initialized from whatever assembly (C) says.
.stack will be a unidirectional growing, shrinking memory region - will contain local variables of a function when it's being executed.
.heap will be undirectional growing, shrinking memory region - is known as dynamic memory region which means, it's not fixed at compile time.

┌───────────┬───────────┬──┬─┬─┬─┬──────────────────┬───────────────────────────────┐
│           │           │  │ │ │ │                  │                               │
│ code      │ global    │  │ │ │ │                  │                               │
│ section   │   or      │  │ │ │ │                  │                               │
│           │  .bss     │  │ │ │ │                  │                               │
│           │ section   │stack section/region       │<-------heap region----------->│
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │ -------->        │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
│           │           │  │ │ │ │                  │                               │
└───────────┴───────────┴──┴─┴─┴─┴──────────────────┴───────────────────────────────┘
*/
