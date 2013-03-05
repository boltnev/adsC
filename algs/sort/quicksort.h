//
//  quicksort.h
//  ads
//
//  Created by Ilya Boltnev on 2/16/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#ifndef ads_quicksort_h
#define ads_quicksort_h

long comparsions;

size_t IB_qsort_divide(long *data, size_t left, size_t right);
void IB_quicksort(long *data, int datasize);

#endif
