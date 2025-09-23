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

void envAide(void){
    Serial.println("Commande env :");
    Serial.println("fonction : affiche les variables d'environnement");
    Serial.println("usage    : env ");
}

int env(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        envAide();
        return returnValue;
    } 
    for (int i = 0 ; i < NB_VARIABLES_ENV ; i++){
        if (!listeVariablesEnv[i].isEmpty()){
            Serial.println(listeVariablesEnv[i] + " = " + valeurVariablesEnv[i]);
        }
    }
    return returnValue;
}