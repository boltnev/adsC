
#include <stdlib.h>
#include <stdio.h>

void merge(long *left, long *right, int lsize, int rsize){

    int i = 0, j = 0, k = 0;
    long *temp = malloc(sizeof(long) * (rsize + lsize));

    while(i < lsize && j < rsize){
        if(left[i] < right[j]){
            temp[k++] = left[i++];
        }else{
            temp[k++] = right[j++];
        }

        if(i == lsize){
            for(;j < rsize;){
                temp[k++] = right[j++];
            }
        }

        if(j == rsize){
            for(;i < lsize;){
                temp[k++] = left[i++];
            }
        }
    }
    memcpy(left, temp, sizeof(long) * (lsize + rsize));
    free(temp);
}

void mergesort(long *data, int datasize){
    int lsize, rsize;
    lsize = datasize / 2;
    rsize = datasize - lsize;

    if(lsize  < 1 || rsize < 1){
        return;
    }else{
        mergesort(data, lsize);
        mergesort(data + lsize, rsize);
        merge(data, data + lsize, lsize, rsize);
    }
}


