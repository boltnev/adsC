//
//  bubble.c
//  ads
//
//  Created by Ilya Boltnev on 2/25/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include "global.h"

void IB_simpleBubbleSort(long *data, size_t datasize){
    size_t i;
    size_t j;
    
    for(j = 0; i < datasize; j++){
        for(i = 1; i < datasize; i++){
            if(data[i] < data[i - 1])
                swap(data[i], data[i - 1]);
        }
    }
}