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

void unsetAide(void){
    Serial.println("Commande unset :");
    Serial.println("fonction : supprime une variable d'environnement");
    Serial.println("usage    : unset <nom_variable>");
}

int unset(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        unsetAide();
        return returnValue;
    } 
    String variable = cdeTbl[1];
    // test si la variable existe deja
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
        Serial.println("Erreur : la variable " + variable + " n'existe pas");
        returnValue = ERREUR_SYSTEM;
    }
    return returnValue;
}