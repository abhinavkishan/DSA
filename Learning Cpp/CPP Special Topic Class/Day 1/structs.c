#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

typedef struct abc3 {
    char c1;
    short s1;
    char c2;
}abc3;

typedef struct abc1 {
    char c1;
    int i1;
    char c2;
}abc1;

typedef struct abc2 {
    char c1;
    char c2;
    int i1;
}abc2;

/* packing
5.52.7 Structure-Packing Pragmas
For compatibility with Microsoft Windows compilers, GCC supports a set of #pragma directives which change the maximum alignment of members of structures (other than zero-width bitfields), unions, and classes subsequently defined. The n value below always is required to be a small power of two and specifies the new alignment in bytes.

#pragma pack(n) simply sets the new alignment.
#pragma pack() sets the alignment to the one that was in effect when compilation started (see also command line option -fpack-struct[=<n>] see Code Gen Options).
#pragma pack(push[,n]) pushes the current alignment setting on an internal stack and then optionally sets the new alignment.
#pragma pack(pop) restores the alignment setting to the one saved at the top of the internal stack (and removes that stack entry). Note that #pragma pack([n]) does not influence this internal stack; thus it is possible to have #pragma pack(push) followed by multiple #pragma pack(n) instances and finalized by a single #pragma pack(pop).
*/

int main()
{
    abc1 var1;
    abc2 var2;
    abc3 var3;
    printf("Size of abc1: %u\n",sizeof(abc1));
    printf("Size of abc2: %u\n",sizeof(abc2));
    printf("Size of abc3: %u\n",sizeof(abc3));

    return 0;
}