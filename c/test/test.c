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
#include "naive.h"

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
    free(data);
}

/* Substring finding tests */

int test_naive_substr(){
    int i;
    int tests[4];
    int expect[] = {6, 14, 29, -1};
    int result;
    char *s = "azcasdabc\0";
    char *p = "abc";
    
    printf("Naive sort\n");
    
    tests[0] = IB_naive_substr(s, p);
    
    s = "aaabbbcccppprrrttt12312354\0";
    p = "rt";
    
    tests[1] = IB_naive_substr(s, p);
    
    s = "0000000000000000000000000000001001000\0";
    p = "010010";
    
    tests[2] = IB_naive_substr(s, p);
    
    
    s = "0000000000000000000000000000001001000\0";
    p = "no you are worng";
    
    tests[3] = IB_naive_substr(s, p);
    
    
    for(i = 0; i < 4; i++){
        if(expect[i] == tests[i])
            printf("%d=OK ", i);
        else{
            printf("%d=F ", i);
            result = !0;
        }
    }
    
    return result;
}


int tests_substr(){
    printf("Testing algoritms of subtring finding\n");
    return test_naive_substr();
}

