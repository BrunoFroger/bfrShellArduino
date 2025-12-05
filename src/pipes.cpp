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
    for(int i = 0 ; i < NB_PIPES ; i++){
        if (! tblPipe[i].used){
            tblPipe[i].used = true;
            tblPipe[i].filename="pipe_" + i;
            pipe
        }
    }
}

File *getpipeFile(String pipeName){

}

int deletePipe(String pipeName){

}