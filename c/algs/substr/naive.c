//
//  naive.c
//  ads
//
//  Created by Ilya Boltnev on 2/19/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//
#include <string.h>

int IB_naive_substr(char *s, char *p){
    int i = 0;
    int j;
    int n = strlen(s);
    int m = strlen(p);
    while(i < (n - m + 1))
    {
        j = 0;
        while(s[i + j] == p[j]){
            if(j == m - 1)
                return i;
            j++;
        }
        i++;
    }
    return -1;
}