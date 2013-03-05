#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

typedef int (*intFunction)();

intFunction getSubprogram(int argc, char* argv[]){
    intFunction function;
    
    if(argc > 1)
    {
        if (strcmp(argv[1], "--test-substr") == 0)
            function = tests_substr;
        else if (strcmp(argv[1], "--test-sort") == 0) 
            function = test_quicksort;
        else if (strcmp(argv[1], "--test-substr-generator") == 0) 
            function = test_substr_generator;
        else{
           printf("Wrong input\n");
           abort();
        }
        return function;
    }else{
        //default
        function = test_findNOrder;
        return function;
    }
}

int main(int argc, char* argv[]){
    intFunction test = getSubprogram(argc, argv);
    
    
    return test();
}


