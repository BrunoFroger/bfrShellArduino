//---------------------------------------------------
//
//      aide.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "erreurs.hpp"
#include "commandes.hpp"

int aide(String commande){
    char buffer[255];
    char buffer1[255];
    int returnValue=NO_ERREUR;
    if (cdeTbl[1].length() == 0){
        Serial.println("Liste des commandes disponibles : ");
        for (int i=0 ; i < NB_COMMANDES ; i++){
            listeCommandes[i].toCharArray(buffer1,255);
            sprintf(buffer, "%10s", buffer1);
            Serial.print(buffer);
        }
        Serial.println();
        Serial.println("Pour l'aide d'une commande spécifique tapez : aide <commnde>");
    } else {
        Serial.println("aide de la fonction " + cdeTbl[1]);
        for (int i = 0 ; i < NB_COMMANDES ; i++){
            if (cdeTbl[1].equals(listeCommandes[i])){
                returnValue=(*functptr[i])("aide");
            }
        }
    }
    return returnValue;
}