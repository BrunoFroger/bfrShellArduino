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

    #define NB_PIPES    20
    typedef struct {
        boolean open;
        String filename;
        File *fic;
    } sdPipe;

    extern sdPipe tblPipe[NB_PIPES];

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
    extern String sdPipeOpen(void);
    extern void sdPipeClose(String);
#endif