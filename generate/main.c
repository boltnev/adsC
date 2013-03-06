//
//  main.c
//  generate
//
//  Created by Ilya Boltnev on 2/24/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include "generator.h"
#include "test.h"
#include "global.h"

int main(int argc, const char * argv[])
{
    randomSortTestGeneration(MEGABYTE * 1000);
    
    return 0;
}

