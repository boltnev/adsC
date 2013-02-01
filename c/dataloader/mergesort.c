
#include <stdlib.h>
#include <stdio.h>

void merge(long *left, long *right, int n){

    int i = 0, j = 0, k = 0;
    long *temp = malloc(2 * n);

    while(i < n && j < n){
        if(left[i] < right[j]){
            temp[k++] = left[i++];
        }else{
            temp[k++] = right[j++];
        }

        if(i == n){
            for(;j < n;){
                temp[k++] = right[j++];
            }
        }

        if(j == n){
            for(;j < n;){
                temp[k++] = left[j++];
            }
        }
    }
    memcpy(left, temp, sizeof(long) * 2 * n);
    free(temp);
}
