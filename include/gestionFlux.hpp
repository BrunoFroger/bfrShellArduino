//---------------------------------------------------
//
//      gestionFlux.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <Arduino.h>
#include <string.h>

#ifndef __GESTIONFLUX__
    #define __GESTIONFLUX__

    extern char fluxRead(const String flux);
    extern void fluxWrite(const String flux, String data);
    extern void fluxWriteln(const String flux, String data);
    extern int fluxAvailable(String flux);
    extern int fluxFlush(String flux);
#endif