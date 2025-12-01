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
#include "gestionFlux.hpp"

void mkdirAide(void){
    fluxWriteln("fluxout", "Commande mkdir :");
    fluxWriteln("fluxout", "fonction : cré un répertoire");
    fluxWriteln("fluxout", "usage    : mkdir <nom du répertoire>");
}

int mkdir(String commande){
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        mkdirAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        // Serial.println("mkdir");
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            if (! fileExist(filename)){
                int res = sdMkdir(filename);
                if (res != NO_ERREUR){
                    fluxWriteln("fluxerr", "le repertoire " + filename + " n'a pas ete crée");
                    returnValue = ERREUR_CREATION_FILE;
                }
            } else {
                fluxWriteln("fluxerr", "Le repertoire " + filename + " existe deja");
                returnValue = ERREUR_CREATION_FILE;
            }
        } else {
            fluxWriteln("fluxerr", "manque nom du fichier\n");
            returnValue=ERREUR_FILE_NOT_FOUND;
        }
    } else {
        fluxWriteln("fluxerr", "Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}