#include <stdio.h>
#include <string.h>

// explaination at my article:
// https://iq.opengenus.org/print-all-sub-strings/

int main(int arg_count, char *arg_vec[])
{
    char *s = (arg_count > 1) ? arg_vec[1] : "Hello";
    unsigned int len = strlen(s);

    for (unsigned int k = 0; k < len; ++k) {
        for (unsigned int i = 0; i < len - k; ++i) {
            for (unsigned int j = 0; j < k + 1; ++j)
                printf("%c", s[i + j]);
            puts("");
        }
    }

    return 0;
}
