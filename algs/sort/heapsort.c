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


void heapifyMin(long *heap, size_t datasize, size_t el){
    
    size_t lpos, rpos, smallest;
    lpos = 2 * (el + 1) - 1;
    rpos = 2 * (el + 1);
    
    int rightExist = rpos < datasize;
    int leftExist  = lpos < datasize;
    
    if(!rightExist && !leftExist)
        return;
    
    smallest = el;
    
    if(leftExist && heap[lpos] < heap[el])
        smallest = lpos;
    
    if(rightExist && heap[rpos] < heap[el])
        smallest = rpos;
    
    if(leftExist && rightExist && heap[lpos] < heap[el] && heap[rpos] < heap[el])
        if(heap[lpos] < heap[rpos])
            smallest = lpos;
        else
            smallest = rpos;
    
    if(smallest > el){
        swap(heap[el], heap[smallest]);
        heapifyMin(heap, datasize, smallest);
    }
};


void makeHeap(long *heap, size_t datasize){
    for(size_t i = datasize / 2 ; i != (size_t) 0 - 1; i-- )
        heapify(heap, datasize, i);
}

void makeMinHeap(long *heap, size_t datasize){
    for(size_t i = datasize / 2  ; i != (size_t) 0 - 1; i-- )
        heapifyMin(heap, datasize, i);
}


void IB_heapsort(long *data, size_t datasize){
    makeHeap(data, datasize);
    for(size_t i = 0; i < datasize; i++){
        swap(data[0], data[datasize - i - 1]);
        heapify(data, datasize - i - 1, 0);
    }
}

