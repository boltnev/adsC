//
//  dataoutput.c
//  adsC
//
//  Created by Ilya Boltnev on 3/6/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include "global.h"

size_t writeArrayToFile(char * filename, long * data, size_t max){
    
    FILE* file = fopen (filename, "w");
    
    size_t i = 0;
    
    while(fprintf(file, "%ld\n", data[i++]) > 0 && i < max){}
    
    fclose(file);
       
    return i;
}

size_t writeArrayToPosition(char * filename,
                            long * data,
                          size_t   datasize,
                          size_t   currentPos){
    
    FILE* file = fopen (filename, "a");
    
    if( file == NULL || fseek(file, (int) currentPos, 0) != 0 ){
        printf("File %s is denied", filename);
        abort();
    }
    
    int bytesWritten;
    
    size_t i = 0;
    
    while(
          ((bytesWritten = fprintf(file, "%ld\n", data[i++])) > 0) &&
          (i < datasize                                          )
         )
    {
        currentPos += bytesWritten;
    }
    
    fclose(file);
    
    return currentPos;
}