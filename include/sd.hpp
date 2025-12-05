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

    // extern String repertoire;

    extern int sdInit(void);
    extern int isSdAvailable(void);
    extern File sdOpenRead(String);
    extern File sdOpenWrite(String);
    extern File sdOpenDir(String);
    extern int sdRemove(String);
    extern int sdMkdir(String);
    extern int sdRmdir(String);
    extern int fileExist(String);
    extern String getPwd(void);
    extern String getPath(String);
    extern void setPwd(String);
    extern File sdPipeOpen(String);
    extern void sdPipeClose(File);
#endif