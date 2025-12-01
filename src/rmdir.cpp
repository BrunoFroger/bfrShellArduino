//---------------------------------------------------
//
//      rmdir.cpp
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

void rmdirAide(void){
    fluxWriteln("fluxout", "Commande rm :");
    fluxWriteln("fluxout", "fonction : supprime un fichier");
    fluxWriteln("fluxout", "usage    : rm <nom du fichier>");
}

int rmdir(String commande){
    int returnValue=NO_ERREUR;
    if (commande.equals("aide")){
        rmdirAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            if (fileExist(filename)){
                sdRmdir(filename);
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