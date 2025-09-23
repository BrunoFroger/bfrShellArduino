//---------------------------------------------------
//
//      commandes.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#ifndef __SD__
    #define __SD__

    extern String repertoire;
    
    extern int sdInit(void);
    extern int isSdAvailable(void);
    extern File sdOpen(String);
#endif