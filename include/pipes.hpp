//---------------------------------------------------
//
//      pipes.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <Arduino.h>
#include <string.h>
#include <SPI.h>
#include <SD.h>

#ifndef __PIPES__
    #define __PIPES__

    #define NB_PIPES    20
        
    typedef struct {
        boolean used;
        String filename;
        File *fic;
    } sdPipe;
    
    extern sdPipe tblPipe[NB_PIPES];

    String creePipe(void);
    File *getpipeFile(String pipeName);
    int deletePipe(String pipeName);

#endif