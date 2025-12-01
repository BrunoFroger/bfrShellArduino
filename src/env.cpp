//---------------------------------------------------
//
//      env.cpp
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

void envAide(void){
    fluxWriteln("fluxout", "Commande env :");
    fluxWriteln("fluxout", "fonction : affiche les variables d'environnement");
    fluxWriteln("fluxout", "usage    : env ");
}

int env(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        envAide();
        return returnValue;
    } 
    for (int i = 0 ; i < NB_VARIABLES_ENV ; i++){
        if (!listeVariablesEnv[i].isEmpty()){
            fluxWriteln("fluxout", listeVariablesEnv[i] + " = " + valeurVariablesEnv[i]);
        }
    }
    return returnValue;
}