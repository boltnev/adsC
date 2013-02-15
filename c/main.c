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

    IBmergesort(data, datalength);

    printf("\n\nsorted array...\n\n");

    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);

    printf("\n\ndeposing...\n\n");

    for(i = 0; i < 10; i++)
        depose(data[i]);


    printf("\n\nfetching...\n\n");

    for(i = 0; i < 100 && !bufferempty; i++)
        printf("%ld ", fetch());


    return 0;
}
