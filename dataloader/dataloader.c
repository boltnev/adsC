
#include "global.h"

#define MAXNUMBER 50


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

size_t loadFilePart(const char filename[], long data[], size_t maxelements){
    char *ch_number = malloc(sizeof(char) * sizeof(long));
    
    FILE* file = fopen (filename, "r");
    
    size_t max_number =  MAXNUMBER;
    size_t i = 0;
    while(getline(&ch_number, &max_number, file) > 0 && i < maxelements){
        data[i++] = atol(ch_number);
    }
    
    fclose(file);
    
    return i;
}