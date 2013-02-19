//
//  naive.c
//  ads
//
//  Created by Ilya Boltnev on 2/19/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

int IB_naive_substr(char *s, char *p, int n, int m){
    int i = 0, j = 0;
    while(i < (n - m))
    {
        while(s[i + j] == p[j])
            j++;
        if(j == m)
            return i;
        i++;
    }
    return -1;
}