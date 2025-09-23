//---------------------------------------------------
//
//      analyseCommande.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#ifndef __ANALYSE_COMMANDE__
    #define __ANALYSE_COMMANDE__

    #define NB_PARAM 10
    #define PARAM_SIZE  50

    extern String cdeTbl[NB_PARAM];

    int analyseCommande(String);
    void decomposeCommande(String, char);
    
#endif
