#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define INPUT  "input.txt"
#define OUTPUT "output.txt"

matrix a, b, c;

void doReopen()
{
    freopen(INPUT,  "r", stdin);
    freopen(OUTPUT, "w", stdout);
}

int main()
{
    doReopen();

    readMatrix(&a);
    readMatrix(&b);

#ifdef DEBUG
    printf("A ");
    printMatrix(a);
    printf("\nB ");
    printMatrix(b);
    printf("\nC ");
#endif

    multiplyAllocateMatrices(a, b, &c);
    multiplyMatrices(a, b, c, 0, 1);

    printMatrix(c);

    freeMatrix(&a);
    freeMatrix(&b);
    freeMatrix(&c);

    return(0);
}
