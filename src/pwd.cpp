//---------------------------------------------------
//
//      pwd.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "sd.hpp"
#include "gestionFlux.hpp"

void pwdAide(void){
    fluxWriteln("fluxout", "Commande pwd :");
    fluxWriteln("fluxout", "fonction : affiche le nom du repertoire courant sur carte SD");
    fluxWriteln("fluxout", "usage    : pwd ");
}

int pwd(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        pwdAide();
        return returnValue;
    } 
    fluxWriteln("fluxout", getPwd());
    return returnValue;
}