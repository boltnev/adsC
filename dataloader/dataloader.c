
#include "global.h"

#define MAXNUMBER 50
#define LOADMAX   1024*1024

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
/* loads numbers from file starting position startPos,
   writes to maxelements count
   returns number of readed bytes  */
size_t loadFilePart(const char * filename,
                          long * data,
                        size_t * count,
                        size_t   currentPos){
    
    char *ch_number = malloc(sizeof(char) * sizeof(long));
    int bytesWritten;
    FILE* file = fopen (filename, "r+");
    
    
    if( file == NULL || fseek(file, currentPos, 0) != 0 ){
        printf("File %s is denied", filename);
        abort();
    }
    
    size_t max_number =  MAXNUMBER;
    size_t i = 0;
    
    while(
          ((bytesWritten = getline(&ch_number, &max_number, file) ) > 0) &&
          (i < LOADMAX                                                 )
         ){
        data[i++] = atol(ch_number);
        currentPos += bytesWritten;
    }
    
    *count = i;
    
    free(ch_number);
    
    fclose(file);
    
    return currentPos;
}