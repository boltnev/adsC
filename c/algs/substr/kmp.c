//
//  kmp.c
//  ads
//
//  Created by Ilya Boltnev on 2/19/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//
#include <string.h>

void IB_get_prefix_function(char *s, long prefix_function[]){
    size_t m = strlen(s);
    size_t i;
    size_t j;
    prefix_function[0] = 0;
    i = 1;
    
    for(i = 1; i < m; i++){
        j = prefix_function[i - 1];
        while( j > 0 && s[i] != s[j])
            j = prefix_function[j - 1];
        if(s[i] == s[j])
            j++;
        prefix_function[i] = j;
    }
}

size_t IB_KMP_substr(char *s, char *p){
    
    size_t i, j;
    
    size_t n =  strlen(s);
    
    long m = (long) strlen(p);
    
    long prefix_function[m];
    
    IB_get_prefix_function(p, prefix_function);
    
    i = 0;
    j = 0;
    while(i < n && (j < m))
    {
        if(s[i] != p[j]){
            j = prefix_function[j];
        }
        i++;
        j++;
    }
    if(j == m)
        return i - m;
    else
        return -1;
}