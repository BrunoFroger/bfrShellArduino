//---------------------------------------------------
//
//      rm.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "analyseCommande.hpp"
#include "erreurs.hpp"
#include "sd.hpp"

void rmAide(void){
    Serial.println("Commande rm :");
    Serial.println("fonction : supprime un fichier");
    Serial.println("usage    : rm <nom du fichier>");
}

int rm(String commande){
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        rmAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            if (fileExist(filename)){
                sdRemove(filename);
            }
        } else {
            Serial.printf("manque nom du fichier\n");
            returnValue=ERREUR_FILE_NOT_FOUND;
        }
    } else {
        Serial.println("Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}