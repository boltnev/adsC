//
//  global.h
//  ads
//
//  Created by Ilya Boltnev on 2/24/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#ifndef ads_global_h
#define ads_global_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MEGABYTE 1024*1024*1 /* 1 MB */
#define swap(x,y)  \
{   size_t swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
    memcpy(swap_temp,&y,sizeof(x)); \
    memcpy(&y,&x,       sizeof(x)); \
    memcpy(&x,swap_temp,sizeof(x)); \
}

#endif
