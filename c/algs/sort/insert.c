//
//  insert.c
//  ads
//
//  Created by Ilya Boltnev on 2/24/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//
//  Insert sort implementations

#include "global.h"

void IB_simpleInsertSort(long *data, size_t datasize){
    size_t i;
    size_t j;
    size_t k;
    
    long temp;
    for(i = 1; i < datasize; i++){
        j = 0;
        while(data[j] < data[i])
            j++;
        temp = data[i];
        for( k = i; k > j; k--){
            data[k] = data[k - 1];
        }
        data[j] = temp;
    }    
}
