//---------------------------------------------------
//
//      set.cpp
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

void setAide(void){
    Serial.println("Commande set :");
    Serial.println("fonction : cree ou modifie une variable d'environnement (valeur doit etre une chaine de caracteres uniquement)");
    Serial.println("usage    : set <nom_variable> <valeur> ");
}

int set(String commande){
    int returnValue = NO_ERREUR;
    if (commande.equals("aide")){
        setAide();
        return returnValue;
    } 
    String variable = cdeTbl[1];
    String valeur = cdeTbl[2];
    if ((variable.length() == 0) || (valeur.length() == 0)){
        Serial.println ("Erreur : pas assez de parametres !");
        setAide();
        returnValue = ERREUR_PARAMETRES;
    } else {
        // test si la variable existe deja
        int i;
        for (i = 0 ; i < NB_VARIABLES_ENV ; i++){
            if (variable.equals(listeVariablesEnv[i])){
                // Serial.println("la variable existe, on la modifie");
                break;
            }
        }
        if (i < NB_VARIABLES_ENV){
            // Serial.println("la variable existe, on la modifie");
            valeurVariablesEnv[i] = valeur;
        } else {
            // Serial.println("la variable n'existe pas, on la crée");
            for (i = 0 ; i < NB_VARIABLES_ENV ; i++){
                if (listeVariablesEnv[i].isEmpty()){
                    // Serial.println("Creation de la variable " + (String)i);
                    listeVariablesEnv[i]=variable;
                    valeurVariablesEnv[i]=valeur;
                    break;
                }
            }
            if (i >= NB_VARIABLES_ENV){
                Serial.println("Erreur : table de variable d'environnement pleine");
                returnValue = ERREUR_SYSTEM;
            }
        }
    }
    return returnValue;
}