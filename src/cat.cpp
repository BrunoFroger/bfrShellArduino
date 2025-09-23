//---------------------------------------------------
//
//      cat.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "analyseCommande.hpp"
#include "erreurs.hpp"
#include "sd.hpp"

char buffer[255];

void catAide(void){
    Serial.println("Commande cat :");
    Serial.println("fonction : affiche a l'ecran le contenu d'un fichier");
    Serial.println("usage    : cat <nom du fichier>");
}

int cat(String commande){
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        catAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            fic = sdOpen(filename);
            if (!fic){
                Serial.println("ERREUR : fichier " + filename + " non trouvé");
                returnValue=ERREUR_FILE_NOT_FOUND;
            } else {
                if (fic.isDirectory()){
                    Serial.println(filename + " est un repertoire");
                    returnValue=ERREUR_FILE_NOT_FOUND;
                }
                while (fic.available()){
                    Serial.write(fic.read());
                }
                fic.close();
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