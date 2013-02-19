
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXDATA 2048
#define MAXNUMBER 50

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
    char *ch_number = malloc(sizeof(char) * sizeof(long));
    
    FILE* file = fopen (filename, "r");
    
    size_t max_number =  MAXNUMBER;
    int i = 0;
    while(getline(&ch_number, &max_number, file) > 0){
        data[i++] = atol(ch_number);
    }
    *len = i;
    fclose(file);
}

