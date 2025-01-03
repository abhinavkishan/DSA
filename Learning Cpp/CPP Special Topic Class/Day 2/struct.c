#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

struct test {
    int i1;
    char c1;
    // char c2;
};

int main()
{
    printf("%lu\n",sizeof(test));  
    return 0;
}