//
//  quicksort.c
//  ads
//
//  Created by Ilya Boltnev on 2/16/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>

void IBlong_switch(long *a, long *b){
    long temp = *a;
    *a = *b;
    *b = temp;
}

int IBpivot_pos_of_three(long *data, int datasize){
    int apos, bpos, cpos;
    apos = 0;
    bpos = datasize / 2;
    cpos = datasize - 1;
    //finding the medium of 3
    if((data[apos] <= data[bpos] && data[bpos] <= data[cpos] )||( data[apos] >= data[bpos] && data[bpos] >= data[cpos]))
        return bpos;
    
    if((data[bpos] <= data[apos] && data[apos] <= data[cpos] )||( data[bpos] >= data[apos] && data[apos] >= data[cpos]))
        return apos;
    
    if((data[apos] <= data[cpos] && data[cpos] <= data[bpos] )||( data[apos] >= data[cpos] && data[cpos] >= data[bpos]))
        return cpos;
}

int IBqsort_divide(long *data, int left, int right){
    int pivot_pos = IBpivot_pos_of_three(data, right);
    long pivot = data[pivot_pos];
    int rborder = right;
    int i; ///test
    
    printf("medium = %d \n", pivot_pos);
    
    IBlong_switch(&data[pivot_pos], &data[rborder - 1]);
    
    for(i = 0; i <= rborder - 1; i++ ){
        if (data[i] < pivot) {
            IBlong_switch(&data[i], &data[left++]);
        }
    }
    
    IBlong_switch(&data[left], &data[rborder - 1]);
    
    return left;
}

void IBquicksort(long *data, int datasize){
    int i;
    for(i = 0; i < datasize; i++)
        printf("%ld ", data[i]);
    printf("\n");
    if(datasize <= 1)
        return;
    int pivot_pos = IBqsort_divide(data, 0, datasize);
    
    printf("pp = %d\n ", pivot_pos);
    


    IBquicksort(data, pivot_pos);
    IBquicksort(data + pivot_pos + 1, datasize - pivot_pos - 1);
}
