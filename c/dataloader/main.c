#include <stdio.h>
#include <stdlib.h>
#include "dataloader.h"
#include "mergesort.h"
/* Test Project for data input;*/
#define MAX_ELEMENTS 1024*1024

int main(){
    int i;
    int datalength;
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);

    //dataload(data, &datalength);

    //printf("\n%d\n", datalength);

    long data1[] = {5, 3};
    long data2[] = {2, 7};

    merge(data1, data2, 2);

    for(i = 0; i < 4; i++)
        printf("%ld ", data1[i]);
    return 0;
}
