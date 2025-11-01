//---------------------------------------------------
//
//      mkdir.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "analyseCommande.hpp"
#include "erreurs.hpp"
#include "sd.hpp"

void mkdirAide(void){
    Serial.println("Commande mkdir :");
    Serial.println("fonction : cré un répertoire");
    Serial.println("usage    : mkdir <nom du répertoire>");
}

int mkdir(String commande){
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        mkdirAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        Serial.println("mkdir");
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            if (! fileExist(filename)){
                int res = sdMkdir(filename);
                if (res != NO_ERREUR){
                    Serial.println("ERREUR : le repertoire " + filename + " n'a pas ete crée");
                    returnValue = ERREUR_CREATION_FILE;
                }
            } else {
                Serial.println("ERREUR : Le repertoire " + filename + " existe deja");
                returnValue = ERREUR_CREATION_FILE;
            }
        } else {
            Serial.printf("ERREUR : manque nom du fichier\n");
            returnValue=ERREUR_FILE_NOT_FOUND;
        }
    } else {
        Serial.println("ERREUR : Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}