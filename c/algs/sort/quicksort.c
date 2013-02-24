//
//  quicksort.c
//  ads
//
//  Created by Ilya Boltnev on 2/16/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
long comparsions = 0;

void IBlong_switch(long *a, long *b){
    long temp = *a;
    *a = *b;
    *b = temp;
}

int IBpivot_pos_of_three(long *data, int datasize){
    int apos, bpos, cpos;
    apos = 0;
    bpos = datasize / 2;
    cpos = datasize;
    //finding the medium of 3
    if((data[apos] <= data[bpos] && data[bpos] <= data[cpos] )||( data[apos] >= data[bpos] && data[bpos] >= data[cpos]))
        return bpos;
    
    if((data[bpos] <= data[apos] && data[apos] <= data[cpos] )||( data[bpos] >= data[apos] && data[apos] >= data[cpos]))
        return apos;
    
    if((data[apos] <= data[cpos] && data[cpos] <= data[bpos] )||( data[apos] >= data[cpos] && data[cpos] >= data[bpos]))
        return cpos;
}

int IBqsort_divide(long *data, int left, int right){
    int pivot_pos = IBpivot_pos_of_three(data, right - 1);
    long pivot = data[pivot_pos];
    int l = 1;
    int i;
    
    
    IBlong_switch(&data[pivot_pos], &data[0]);
    
    for(i = 1; i <= right - 1; i++ ){
        
        comparsions += 1;

        if (data[i] < pivot) {
            IBlong_switch(&data[i], &data[l++]);
        }
    }
    
    IBlong_switch(&data[l - 1], &data[0]);
    
    return l - 1;
}

void IBquicksort(long *data, int datasize){
    
    if(datasize <= 1)
        return;
        int pivot_pos = IBqsort_divide(data, 0, datasize);
    
    IBquicksort(data, pivot_pos);
    IBquicksort(data + pivot_pos + 1, datasize - pivot_pos - 1);
}
