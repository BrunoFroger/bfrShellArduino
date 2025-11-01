//---------------------------------------------------
//
//      cp.cpp
//
//      (c) B. Froger 2025
//
//---------------------------------------------------


#include <stdio.h>
#include <string.h>

#include "analyseCommande.hpp"
#include "erreurs.hpp"
#include "sd.hpp"

void cpAide(void){
    Serial.println("Commande cp :");
    Serial.println("fonction : copie le contenu d'un fichier dans un autre fichier");
    Serial.println("usage    : cp <fichier source> <fichier destination>");
}

int cp(String commande){
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        cpAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String fichierSource, fichierDest;
        File ficSource, ficDest;
        fichierSource = cdeTbl[1];
        fichierDest = cdeTbl[2];
        // Serial.println("filename = " + filename);
        if (fichierSource.length() > 0){
            ficSource = sdOpenRead(fichierSource);
            if (!ficSource){
                Serial.println("ERREUR : fichier " + fichierSource + " non trouvé");
                returnValue=ERREUR_FILE_NOT_FOUND;
            } else {
                if (fichierDest.length() > 0){
                    if (fileExist(fichierDest)){
                        Serial.println("ERREUR : le fichier destination (" + fichierDest + ") existe deja");
                        returnValue = ERREUR_FILE_EXIST;
                    } else {
                        ficDest = sdOpenWrite(fichierDest);
                        // if(!ficdest)
                        //  TODO
                    }
                }
                if (ficSource.isDirectory()){
                    Serial.println(fichierSource + " est un repertoire");
                    returnValue=ERREUR_FILE_NOT_FOUND;
                }
                while (ficSource.available()){
                    Serial.write(ficSource.read());
                }
                ficSource.close();
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