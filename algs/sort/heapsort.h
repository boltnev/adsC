//
//  heapsort.h
//  adsC
//
//  Created by Ilya Boltnev on 3/4/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#ifndef adsC_heapsort_h
#define adsC_heapsort_h

void makeHeap(long *heap, size_t datasize);
void makeMinHeap(long *heap, size_t datasize);

void heapify(long *heap, size_t datasize, size_t el);
void heapifyMin(long *heap, size_t datasize, size_t el);

void IB_heapsort(long *data, size_t datasize);


#endif
