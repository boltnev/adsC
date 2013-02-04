#include <stdio.h>

#define MAXBUFFER 1024

static int in = 0;
static int out = 0;
static long buffer[MAXBUFFER];
static int n = MAXBUFFER;
int bufferfull = 0;
int bufferempty = 1;

void depose(long x){
    if(!bufferfull){
        buffer[in] = x;
        in = in++;
        in = in % MAXBUFFER;
        n = n--;

        if(n == 0){
            bufferfull = 1;
        }
        bufferempty = 0;
    }
}

long fetch(){
    if(!bufferempty){
        out = out++;
        out = out % MAXBUFFER;
        n++;

        if(n == MAXBUFFER){
            bufferempty = 1;
        }

        bufferfull = 0;
        return buffer[(out - 1 ) % MAXBUFFER];
    }
}
