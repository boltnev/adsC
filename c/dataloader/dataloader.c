
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXDATA 2048

void generate(long data[], int *len){
    srand(time(NULL));
    int r = rand() % MAXDATA;
    int i;
    for(i = 0; i < r; i++){
        data[i] = (long) rand();
        printf("%ld\n", data[i]);
    }
    *len = i;
}

void dataload(long data[], int *len){

    generate(data, len);

}

void load_from_file(const char filename[], long data[], int *len){
}
