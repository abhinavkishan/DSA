#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef union hex
{
    char d1[4];
    long d4;
}hex;


int main()
{
    long l = 0x01020304;
    hex digit;
    digit.d4 = l;
    // big endian
    for(int i = 0; i < 4; i++) printf("%x\n",digit.d1[i]);
    // printf("%d\n",digit.d1[1]);
    for(int i = 0; i < sizeof(long); i++) {
        // printf("byte")
    }
    return 0;
}