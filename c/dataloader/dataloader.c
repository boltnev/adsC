
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXDATA 1024*1024*256

void generate(long data[], int *len){
    srand(time(NULL));
    int r = rand() % 1000;
    int i;
    for(i = 0; i < r; i++){
        data[i] = (long) rand();
        printf("%ld\n", data[i]);
    }
    *len = i;
}

void dataload(long data[], int *len){
    //
    generate(data, len);

}
