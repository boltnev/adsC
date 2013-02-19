//
//  test.c
//  ads
//
//  Created by Ilya Boltnev on 2/19/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CFIFOBuffer.h"
#include "mergesort.h"
#include "dataloader.h"
#include "quicksort.h"
#include <sys/types.h>
#define MAX_ELEMENTS 1024*1024

void test_quicksort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    //dataload(data, &datalength);
    
    load_from_file("/Users/ilya/apps/ads/ads/c/dataloader/QuickSort.txt", data, &datalength);
    //long data[] = {2, 8, 9, 3, 7, 5, 10, 1, 6, 4};// {100, 0, 1, -1, 2, -2, 3, -3};
    //datalength = 10;
    
    printf("\n\n%d\n\n", datalength);
    
    IBquicksort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    printf("\n\ncomparsions number is %ld ...\n\n", comparsions);
    
}