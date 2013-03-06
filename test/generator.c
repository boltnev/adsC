//
//  generator.c
//  ads
//
//  Created by Ilya Boltnev on 2/21/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//
//  Test data generators

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXDATA 2048
void generate_rand_numbers(long data[], int *len){
    
    srand( (int)  time(NULL));
    
    int r = rand() % MAXDATA;
    int i;
    for(i = 0; i < r; i++){
        data[i] = (long) rand();
        printf("%ld\n", data[i]);
    }
    *len = i;
}

void generate_test_substring(char *text, size_t textsize, size_t right_answer_position){
    
    srand( (int)  time(NULL));
    
    char *s = "This string is what i search for";
    
    size_t m = strlen(s);
    
    size_t i;
    size_t j = 0;
    
    for (i = 0; i < textsize; i++) {
        if(i >= right_answer_position && j < m)
            text[i] = s[j++];
        else
            text[i] = 'a' + (rand() % ('z' - 'a') ) ;
    }
    
    text[textsize - 1] = '\0';
}

void randomSortTestGeneration(size_t datasize){
    srand( (int)  time(NULL));
    FILE * file;
    file = fopen("RandomLongsForSortTests", "w");
    size_t i;
    
    for(i = 0; i < datasize; i++)    {
        fprintf(file, "%zd\n", rand());
    }
        
    fclose(file);
}
