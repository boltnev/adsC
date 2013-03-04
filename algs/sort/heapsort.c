//
//  heapsort.c
//  adsC
//
//  Created by Ilya Boltnev on 3/4/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include "global.h"

void heapify(long *heap, size_t datasize, size_t el){
    
    size_t lpos, rpos, largest;
    lpos = 2 * (el + 1) - 1;
    rpos = 2 * (el + 1);
    
    int rightExist = rpos < datasize;
    int leftExist  = lpos < datasize;
    
    if(!rightExist && !leftExist)
        return;
    
    largest = el;
    
    if(leftExist && heap[lpos] > heap[el])
        largest = lpos;
    
    if(rightExist && heap[rpos] > heap[el])
        largest = rpos;
    
    if(leftExist && rightExist && heap[lpos] > heap[el] && heap[rpos] > heap[el])
        if(heap[lpos] > heap[rpos])
            largest = lpos;
        else
            largest = rpos;
    
    if(largest > el){
        swap(heap[el], heap[largest]);
        heapify(heap, datasize, largest);
    }
};

void makeHeap(long *heap, size_t datasize){
    for(size_t i = datasize / 2 ; i != (size_t) 0 - 1; i-- )
        heapify(heap, datasize, i);
}

void IBheapsort(long *data, int datasize){
    
}