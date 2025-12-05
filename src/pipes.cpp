//---------------------------------------------------
//
//      pipes.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <Arduino.h>
#include <string.h>

#include "pipes.hpp"
#include "sd.hpp"

String creePipe(void){
    String pipe = "";
    for(int i = 0 ; i < NB_PIPES ; i++){
        if (! tblPipe[i].used){
            tblPipe[i].used = true;
            pipe = "pipe_" + i;
            tblPipe[i].filename=pipe;
            break;
        }
    }
    return pipe;
}

File *getpipeFile(String pipeName){

}

int deletePipe(String pipeName){

}