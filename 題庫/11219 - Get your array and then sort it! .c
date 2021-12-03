#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int* readInput() {
    int i, N, *seq;
    scanf("%d", &N);
    seq = (int*)malloc(sizeof(int)*(N + 1));
    seq[0] = N;
    for(i=1; i<N+1; i++)
        scanf("%d", &seq[i]);
    return seq;
}

int main() {
    int i;
    int *A = readInput();
    my_sort((int*)&A);
    printf("%d", A[1]);
    for(i=2;i<A[0]+1;i++)
        printf(" %d", A[i]);
    printf("\n");
    return 0;
}
//partial gudge 可以兩個函式一起交
int cmp(const void *_a,const void *_b)
{
    int a = *(int*)_a;
    int b = *(int*)_b;
    return a > b;
}

void my_sort(int* B)
{
    int *C = *(int**)B;
    qsort(C+1,C[0],sizeof(C[0]),cmp);
}
//
