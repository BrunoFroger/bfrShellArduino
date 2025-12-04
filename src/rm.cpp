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
#include "gestionFlux.hpp"
#include "commandes.hpp"

void rmAide(void){
    fluxWriteln("fluxout", "Commande rm :");
    fluxWriteln("fluxout", "fonction : supprime un fichier");
    fluxWriteln("fluxout", "usage    : rm <nom du fichier>");
}

int rm(struct_cde_data data){
    int returnValue=NO_ERREUR;
    if (data.commande.equals("aide")){
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
            fluxWriteln("fluxerr", "manque nom du fichier\n");
            returnValue=ERREUR_FILE_NOT_FOUND;
        }
    } else {
        fluxWriteln("fluxerr", "Carte SD non disponible");
        returnValue=ERREUR_SD_CARD_NON_DISPONIBLE;
    }
    return returnValue;
}