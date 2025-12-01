//---------------------------------------------------
//
//      unset.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"
#include "sd.hpp"
#include "datas.hpp"
#include "gestionFlux.hpp"

void unsetAide(void){
    fluxWriteln("fluxout", "Commande unset :");
    fluxWriteln("fluxout", "fonction : supprime une variable d'environnement");
    fluxWriteln("fluxout", "usage    : unset <nom_variable>");
}

int unset(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        unsetAide();
        return returnValue;
    } 
    String variable = cdeTbl[1];
    // test si la variable est protegee
    if (variable.equals("pwd")) returnValue = ERREUR_VARIABLE_PROTEGEE;
    if (returnValue == ERREUR_VARIABLE_PROTEGEE){
        fluxWriteln("fluxerr", "Impossible de supprimer une variable protégée");
        return returnValue;
    }
    int i;
    for (i = 0 ; i < NB_VARIABLES_ENV ; i++){
        if (variable.equals(listeVariablesEnv[i])){
            // Serial.println("la variable existe, on l'efface'");
            listeVariablesEnv[i]="";
            valeurVariablesEnv[i]="";
            break;
        }
    }

    if (i >= NB_VARIABLES_ENV){
        fluxWriteln("fluxerr", "la variable " + variable + " n'existe pas");
        returnValue = ERREUR_SYSTEM;
    }
    return returnValue;
}