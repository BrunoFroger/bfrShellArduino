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
#include "erreurs.hpp"

void pipeInit(void){
    for (int i=0 ; i < NB_PIPES ; i++){
        tblPipe[i].filename = "";
        tblPipe[i].fic = nullptr;
    }
}

String creePipe(void){
    return sdPipeOpen();
}

File *getpipeFile(String pipeName){
    for (int i = 0 ; i < NB_PIPES ; i++){
        if (tblPipe[i].filename.equals("")){
            return tblPipe[i].fic;
        }
    }
    return NULL;
}

int deletePipe(String pipeName){
    int result = NO_ERREUR;
    sdPipeClose(pipeName);
    return result;
}