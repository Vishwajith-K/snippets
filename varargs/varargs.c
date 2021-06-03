#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// this code is powered by 3 almonds,
// 3 chapathis and curd (as I had loose-motions)

// Code tries to explain usage of the concept of
// variable number of arguments with an example
// A function which takes variable number of arguments
// will find maximum, minimum, average, sum, standard
// deviation of the elements passed to it

// Multi-line & function like macro as a single expression
// we may even use 'do { ... } while(0)' too
// note the line-continuation character at the end of
// each line; it's a pre-processor stuff like comments
// and lines that start with pound/hash
#define print_gist(a) ({            \
    printf("Max %llu\n", a.max);    \
    printf("Min %llu\n", a.min);    \
    printf("Sum %llu\n", a.sum);    \
    printf("Avg %lf\n", a.avg);     \
    printf("standard_deviation %lf\n", a.standard_deviation);   \
    fflush(stdout);                 \
})

// Typical gist for number list
// args shall be set by caller before calling corresponding function
// any user-defined types/typedefs might end with _t
// like uint8_t
typedef struct _gist {
    unsigned long long max, min, sum;
    double avg, standard_deviation;

    unsigned int args;
} gist_t;

// variable number of arguments to a function
// stdarg header is a must (in/directly)
// printf uses ellipsis ('...') token to get variable
// number of arguments
// atleast one arg is must
void gist_the_list(gist_t *g, ...) {
    va_list ls, ll;
    unsigned int i, current;

    // for loop parts can span across multiple lines
    // keep a copy of input list, so that standard_deviation
    // can be computed even after the actual list is consumed
    for (va_start(ls, g), va_copy(ll, ls),
    // type of argument read must be specified
    // I think that's the only bottle-neck to implement
    // C++ styled function/method overloading
    // printf uses format specifier in the string to read next argument
    g->sum = g->max = g->min = va_arg(ls, unsigned int),
    i = 1; i < g->args; ++i) {
        // assignment is an operator => expressions may have
        // assignment operator
        g->sum += (current = va_arg(ls, unsigned int));
        if (g->max < current) g->max = current;
        if (g->min > current) g->min = current;
    }
    // type-cast so that result is not unsigned long long 
    g->avg = g->sum / (double) g->args;
    va_end(ls);

    for (g->standard_deviation = i = 0; i < g->args; ++i) {
        current = va_arg(ll, unsigned int);
        g->standard_deviation += (current - g->avg) * (current - g->avg);
    }
    g->standard_deviation /= g->args;
    g->standard_deviation = sqrt(g->standard_deviation);
    va_end(ll);
}

int main() {
    gist_t a;
    // if colon is not supported, use '.args = 5'
    // comma used as operator in first argument
    // and as seperator for passing the arguments (usual case)
    gist_the_list((a = (gist_t) {args : 5}, &a), 1, 2, 3, 4, 5);
    print_gist(a);
    // empty puts for new-line
    puts("");
    gist_the_list((a = (gist_t) {args : 10}, &a),
                    1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    print_gist(a);

    return 0;
}

