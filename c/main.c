#include <stdio.h>
#include <stdlib.h>
#include "ds/CFIFOBuffer.h"
#include "algs/mergesort.h"
#include "dataloader/dataloader.h"

#define MAX_ELEMENTS 1024*1024

int main(){
    int i;

    int datalength;
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);

    dataload(data, &datalength);

    printf("\n\n%d\n\n", datalength);

    mergesort(data, datalength);

    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);

    return 0;
}
