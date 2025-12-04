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
#include "commandes.hpp"

void pwdAide(void){
    fluxWriteln("fluxout", "Commande pwd :");
    fluxWriteln("fluxout", "fonction : affiche le nom du repertoire courant sur carte SD");
    fluxWriteln("fluxout", "usage    : pwd ");
}

int pwd(struct_cde_data data){
    int returnValue = NO_ERREUR;
    if (data.commande.equals("aide")){
        pwdAide();
        return returnValue;
    } 
    fluxWriteln("fluxout", getPwd());
    return returnValue;
}