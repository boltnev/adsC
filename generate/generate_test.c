//
//  generate_test.c
//  adsC
//
//  Created by Ilya Boltnev on 3/6/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "generator.h"
#include "naive.h"


/* Tests of generators */

int test_substr_generator(){
    
    int result;
    
    size_t textsize = MEGABYTE * 10;
    
    char *text = malloc(textsize * sizeof(char));
    
    size_t right_answer_position = textsize - 500;
    
    printf("\nTesting substring generation...\n");
    
    generate_test_substring(text, textsize, right_answer_position);
    
    int pos = IB_naive_substr(text, "This string is what i search for");
    
    if(pos == textsize - 500)
    {
        result = 0;
        printf("0=OK ");
    }
    else{
        result = !0;
        printf("0=F ");
    }
    
    printf("\n");
    
    return result;
}
