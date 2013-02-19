//
//  CFIFOBuffer.h
//  ads
//
//  Created by Ilya Boltnev on 2/16/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//
//  Cyclic FIFO buffer
//  TODO: remake it as struct
#ifndef CFIFOBUFFER_H_INCLUDED
#define CFIFOBUFFER_H_INCLUDED

int bufferempty;
int bufferfull;
void depose(long x);
long fetch();


#endif // CFIFOBUFFER_H_INCLUDED
