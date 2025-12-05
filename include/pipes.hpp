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

#include "sd.hpp"

#ifndef __PIPES__
    #define __PIPES__

    String creePipe(void);
    File *getpipeFile(String pipeName);
    int deletePipe(String pipeName);

#endif