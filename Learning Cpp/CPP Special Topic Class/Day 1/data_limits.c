#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

// the size depends on compiler

int main()
{
    printf("The maximum value of int = %d\n", INT_MAX);
    printf("The minimum value of int = %d\n", INT_MIN);
    printf("The maximum value of unsigned int = %u\n", UINT_MAX);
    printf("The maximum value of long = %ld\n", LONG_MAX);
    printf("The minimum value of long = %ld\n", LONG_MIN);
    printf("The maximum value of short = %d\n", SHRT_MAX);
    printf("The minimum value of short = %d\n", SHRT_MIN);
    printf("The maximum value of char = %d\n", CHAR_MAX);
    printf("The size of char = %d\n", CHAR_BIT);
    printf("Sizes: \n");
    printf("The size of int = %d\n", sizeof(int));
    printf("The size of long = %d\n", sizeof(long));
    printf("The size of short = %d\n", sizeof(short));
    printf("The size of double = %d\n", sizeof(double));
    printf("The size of char = %d\n",sizeof(char));
    return 0;
}