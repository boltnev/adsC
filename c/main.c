#include <stdio.h>
#include <stdlib.h>
#include "ds/CFIFOBuffer.h"
#include "algs/mergesort.h"
#include "dataloader/dataloader.h"
#include "quicksort.h"

#define MAX_ELEMENTS 1024*1024

int main(){
    int i;

    int datalength;
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);

    dataload(data, &datalength);

    //long data[] = {100, 0, 1, -1, 2, -2, 3, -3};
    //datalength = 8;
    
    printf("\n\n%d\n\n", datalength);

    IBquicksort(data, datalength);

    printf("\n\nsorted array...\n\n");

    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);

    return 0;
}
