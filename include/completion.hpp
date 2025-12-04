//---------------------------------------------------
//
//      completion.hpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <Arduino.h>
#include <string.h>

#ifndef __COMPLETION__
    #define __COMPLETION__
    
    #include "commandes.hpp"
    #include "gestionFlux.hpp"

    extern String completion(struct_cde_flux flux,String saisie);

#endif