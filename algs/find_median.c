//
//  find_median.c
//  adsC
//
//  Created by Ilya Boltnev on 3/5/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>

#include "quicksort.h"

size_t IB_findNOrder(long * data, size_t datasize, const size_t n){
    size_t result = IB_qsort_divide(data, 0, datasize);
    if(n > result)
    {
        return result + IB_findNOrder(data + result + 1, datasize - result - 1, n - result - 1) + 1;
    }
    else if(n < result)
    {
        return IB_findNOrder(data, result, n);
    }
    else
        return result;
}

size_t IB_findMedian(long * data, size_t datasize){    
    return IB_findNOrder(data, datasize, datasize / 2);    
}