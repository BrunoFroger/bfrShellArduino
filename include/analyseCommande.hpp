//---------------------------------------------------
//
//      analyseCommande.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------

#include <Arduino.h>

#include "commandes.hpp"

#ifndef __ANALYSE_COMMANDE__
    #define __ANALYSE_COMMANDE__

    #define PARAM_SIZE  50

    int analyseCommande(struct_cde_data);
    void decomposeCommande(String, char);
    
#endif
