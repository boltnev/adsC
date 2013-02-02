#include <stdio.h>
#include <stdlib.h>
#include "dataloader.h"
#include "mergesort.h"
/* Test Project for data input;*/
#define MAX_ELEMENTS 1024*1024

int main(){
    int i;
    //int datalength;
    //long *data = malloc(sizeof(long) * MAX_ELEMENTS);

    //dataload(data, &datalength);

    //printf("\n%d\n", datalength);

    //long data1[] = {5, 3};
    
    //*data = malloc(sizeof(long) * 4);
    
    long data[] = {100, 3, 5, 2, 8 };
    
    merge(data, data + 1, 1);
    merge(data + 2, data + 3, 1);
    
    
    merge(data, data + 2, 2);

    for(i = 0; i < 4; i++)
        printf("%ld ", data[i]);

    return 0;
}
