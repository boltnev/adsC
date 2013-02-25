//
//  select.c
//  ads
//
//  Created by Ilya Boltnev on 2/25/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "global.h"

void IB_simpleSelectSort(long *data, size_t datasize){
    size_t i, j;
    long *temp;
    for(i = 0; i < datasize; i++){
        temp = &data[i];
        for(j = i; j < datasize; j++){
            if(data[j] < *temp)
                temp = &data[j];
        }
        swap(*temp, data[i]);
    }
}