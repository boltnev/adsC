//
//  test.c
//  ads
//
//  Created by Ilya Boltnev on 2/19/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//testing CFIFOBuffer
#include "CFIFOBuffer.h"

//testing sorts
#include "mergesort.h"
#include "quicksort.h"
#include "insert.h"
#include "select.h"
#include "bubble.h"
#include "shellsort.h"
#include "heapsort.h"

#include "find_median.h"
// testing substring functions
#include "naive.h"
#include "kmp.h"
#include <string.h>

#include "generator.h"
#include "global.h"

// testing IO functions
#include "dataloader.h"
#include "dataoutput.h"

#define MAX_ELEMENTS 1024*1024
#define QuickSorttxt "/Users/ilya/apps/adsC/adsC/dataloader/QuickSort.txt"

/* Sort Algorithms Tests */

int test_quicksort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_quicksort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);
    return 0;
}

int test_simpleInsertSort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_simpleInsertSort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);    
    return 0;
}


int test_simpleSelectSort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_simpleSelectSort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);
    return 0;
}

int test_simpleBubbleSort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_simpleSelectSort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);
    return 0;
}


int test_ShellSort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_ShellSort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);
    return 0;
}

int test_heapSort(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    printf("\n\n%d\n\n", datalength);
    
    IB_heapsort(data, datalength);
    
    printf("\n\nsorted array...\n\n");
    
    for(i = 0; i < datalength; i++)
        printf("%ld ", data[i]);
    
    free(data);
    return 0;
}


/* Heapify test */

int test_makeHeap(){
    int i;
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);

    makeHeap(data, datalength);
    
    for(i = 1; i < datalength; i++)
        if( i % 2 ? data[i / 2] < data[i]      :
                    data[(i - 1) / 2] < data[i]){
            
            printf("problem at %d", i);
            assert(0);
        }
    
    makeMinHeap(data, datalength);
    
    for(i = 1; i < datalength; i++)
        if( i % 2 ? data[i / 2] > data[i]      :
                    data[(i - 1) / 2] > data[i]){
            
            printf("problem at %d", i);
            assert(0);
        }
    
    free(data);
    return 0;
}

int test_heap(){
    int result =  test_makeHeap() + test_heapSort();

    return result;
}

/* Find N order and find median test */

int test_findNOrder(){
    
    int datalength;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    load_from_file(QuickSorttxt, data, &datalength);
    
    assert(data[IB_findMedian(data, datalength)] == 5001);
    
    assert(data[IB_findNOrder(data, datalength, 200)] == 201);
    
    assert(data[IB_findNOrder(data, datalength, 0)] == 1);
    
    assert(data[IB_findNOrder(data, datalength, 5897)] == 5898);
    
    assert(data[IB_findNOrder(data, datalength, 9999)] == 10000);
    
    return 0;
}

/* Substring finding tests */

int test_naive_substr(){
    int i;
    int tests[4];
    int expect[] = {6, 14, 29, -1};
    int result = 0;
    char *s = "azcasdabc\0";
    char *p = "abc";
    
    printf("\nNaive substring search...\n");
    
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

int test_KMP_substr(){
    int i;
    int tests[4];
    int expect[] = {6, 14, 29, -1};
    int result = 0;
    char *s = "azcasdabc\0";
    char *p = "abc";
    
    printf("\nKMP substring search...\n");
    
    tests[0] = IB_KMP_substr(s, p);
    
    s = "aaabbbcccppprrrttt12312354\0";
    p = "rt";
    
    tests[1] = IB_KMP_substr(s, p);
    
    s = "0000000000000000000000000000001001000\0";
    p = "010010";
    
    tests[2] = IB_KMP_substr(s, p);
    
    
    s = "0000000000000000000000000000001001000\0";
    p = "no you are worng";
    
    tests[3] = IB_KMP_substr(s, p);
    
    
    for(i = 0; i < 4; i++){
        if(expect[i] == tests[i])
            printf("%d=OK ", i);
        else{
            printf("%d=F ", i);
            result++;
        }
    }
    
    return result;
}


int test_KMP_preprocessing(){
    int result = 0;
    
    printf("\nKMP prefix function...\n");
    
    char *s = "abcabcd";
    long m = strlen(s);
    size_t i = 0;
    int expect[] = {0, 0, 0, 1, 2, 3, 0};
    
    long prefix_result[m];
    
    IB_get_prefix_function(s, prefix_result);
    
    for (i = 0; i < m; i++) {
        if (prefix_result[i] != expect[i]) {
            result++;
        }
    
    }
    
    
    s = "aabaaab";
    
    int expect2[] = {0, 1, 0, 1, 2, 2, 3};
    
    IB_get_prefix_function(s, prefix_result);
    
    for (i = 0; i < m; i++) {
        if (prefix_result[i] != expect2[i]) {
            result++;
        }
        
    }
    
    if(!result)
        printf("0=OK");
    else{
        printf("1=F ");
        result++;
    }
    return result;
}

int tests_substr(){
    int result = test_naive_substr() +
                 test_KMP_preprocessing() +
                 test_KMP_substr();

    printf("\nTesting algoritms of substring find... %d errors\n", result);
    return result;
}

/* ==== */

int test_dataload_dataoutput(){
    size_t datalength;
    size_t inputCurrentPos = 0;
    size_t outputCurrentPos = 0;
    
    long *data = malloc(sizeof(long) * MAX_ELEMENTS);
    
    datalength = 2000;
    
    inputCurrentPos = loadFilePart(QuickSorttxt, data, &datalength, inputCurrentPos);
    
    assert(datalength == 10000);
    
    IB_quicksort(data, datalength);
        
    outputCurrentPos = writeArrayToPosition("output", data, datalength, outputCurrentPos);
    
    assert(datalength == 10000);
    
    inputCurrentPos = loadFilePart(QuickSorttxt, data, &datalength, inputCurrentPos);
    
    assert(datalength == 0);
    
    IB_quicksort(data, datalength);
    
    outputCurrentPos = writeArrayToPosition("output", data, datalength, outputCurrentPos);
    
    assert(datalength == 0);
    
    return 0;
}

