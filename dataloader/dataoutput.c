//
//  dataoutput.c
//  adsC
//
//  Created by Ilya Boltnev on 3/6/13.
//  Copyright (c) 2013 Ilya Boltnev. All rights reserved.
//

#include <stdio.h>

size_t writeArrayToFile(char * filename, long * data, size_t max){
    
    FILE* file = fopen (filename, "w");
    
    size_t i = 0;
    
    while(fprintf(file, "%ld\n", data[i++]) > 0 && i < max){}
    
    fclose(file);
       
    return i;
}