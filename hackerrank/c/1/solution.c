#include <stdio.h> /* include this if you want to use scanf, printf */
#include <string.h> /* not actually required - but are included by Hackerrank */
#include <math.h> /* not actually required - but are included by Hackerrank */
#include <stdlib.h> /* not actually required - but are included by Hackerrank */

int main() 
{
    char s[100]; /* This is an array of character data-type. Character is 1B wide usually */
    scanf("%[^\n]%*c", &s); /* the ones with paranthesis () are called functions with an exception to C keywords */
    /* scanf function is used to read input from terminal/stdin */
    /* f in the end stands for format-specifier or formatted IO */
    /* it's an input function */

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    printf("Hello, World!\n%s",s);
    /* printf is used to output to terminal/stdout */
    /* printf is a formatted output function */
    /* Format here nearly means interpreting data when reading from terminal or writing to terminal.
    %s stands for string, %d stands for decimal... Format specfiers few view related setting such as alignment, prepending zeros, significant figures when displaying/reading floating numbers */
    return 0;
}

/*
Few rules:
 - main is also a function
 - Usually main is the first function to be executed.
 - Names given to variables, functions are called as identifiers. Variables, functions are together called as symbols.
 - It is possible to write a C program with no headers included.
 - Any symbol must be declared before it's used (whether it's a function/variable).
 - First line inside main is declaration of a variable called s. Declaration helps compiler settle size related issues.
 - Declaration of printf, scanf are present inside stdio.h.

 - Compilation is a broad term & is a big step which will do pre-processing, compiling/translating from C to assembly code, linking
 - All comments are removed & lines starting with # are resolved during pre-processing - file.i.
 - C to assembly conversion happens during compiling & generates a file.o.
 - File generated after linking = .out or .exe or .elf or .hex - these are termed as executables.

Translating from C to assembly is needed as processor cannot understand C but can understand ASM.
For example compiler may replace assignment operations with MOV instructions, comparision operations with CMP, bitwise operations with AND, OR, NOT instructions, calls to functions such as printf, scanf might be replaced with BL; Other C constructs like if, else, for, while might be replaced be GOTOs, Bs.

Given executable can be executed on a machine for which it's compiled.
Machine here stands for processor architecture most of the time & sometimes it also covers processor arch + OS.
*/
