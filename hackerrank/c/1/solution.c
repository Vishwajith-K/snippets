#include <stdio.h> /* include this if you want to use scanf, printf */
#include <string.h> /* not actually required - but are included by Hackerrank */
#include <math.h> /* not actually required - but are included by Hackerrank */
#include <stdlib.h> /* not actually required - but are included by Hackerrank */

int main() 
{
    char s[100];
    scanf("%[^\n]%*c", &s);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    printf("Hello, World!\n%s",s); 
    return 0;
}
