//
//  shellsort.c
//  ads
//
//  Created by Ilya Boltnev on 2/25/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include "global.h"

void insertSortWithStep(long *data, size_t datasize, int step){
    size_t i, j, k, s;

    long temp;
    
    for(s = 0; s < step; s++){
        for(i = s; i < datasize; i = i + step){
            j = s;
            while(data[j] < data[i])
                j = j + step;
            temp = data[i];
            for( k = i; k > j; k = k - step){
                data[k] = data[k - step];
            }
            data[j] = temp;
        }
    }    
}

void IB_ShellSort(long *data, size_t datasize){
    const int shellSequence[] = {4, 2, 1};
    int i;
    for(i = 0; i < 3; i++){
        insertSortWithStep(data, datasize, shellSequence[i]);
    }
}