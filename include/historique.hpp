//---------------------------------------------------
//
//      historique.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>
#include <string.h>


#ifndef __HISTORIQUE__
    #define __HISTORIQUE__

    #define HISTORY_SIZE    10

    extern String getHistoriqueUp(void);
    extern String getHistoriqueDown(void);
    extern void storeHistorique(String);
    extern void listeHistorique(void);

#endif