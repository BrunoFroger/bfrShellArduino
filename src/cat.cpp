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
#include "gestionFlux.hpp"
#include "commandes.hpp"

void catAide(void){
    fluxWriteln("fluxout", "Commande cat :");
    fluxWriteln("fluxout", "fonction : affiche a l'ecran le contenu d'un fichier");
    fluxWriteln("fluxout", "usage    : cat <nom du fichier>");
}

int cat(struct_cde_data data){
    data.cdeFlux.fluxin = cdeTbl[1];
    String fonction = "cat";
    Serial.println(fonction + " : fluxin  = " + data.cdeFlux.fluxin);
    Serial.println(fonction + " : fluxout = " + data.cdeFlux.fluxout);
    Serial.println(fonction + " : fluxerr = " + data.cdeFlux.fluxerr);
    int returnValue=NO_ERREUR;
    if (data.commande.equals("aide")){
        catAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        // File fic;
        // Serial.println("filename = " + filename);
        if (data.cdeFlux.fluxin.length() > 0){
            // fic = sdOpenRead(data.cdeFlux.fluxin);
            if (!fileExist(data.cdeFlux.fluxin)){
                // int creePipe("cat");
            }
            if (!fluxAvailable(data.cdeFlux.fluxin)){
                fluxWriteln("fluxerr", "fichier " + data.cdeFlux.fluxin + " non trouvé");
                returnValue=ERREUR_FILE_NOT_FOUND;
            } else {
                // if (fic.isDirectory()){
                //     fluxWriteln("fluxerr", data.cdeFlux.fluxin + " est un repertoire");
                //     returnValue=ERREUR_FILE_NOT_FOUND;
                // }
                // Serial.println("fluxout = <" + data.cdeFlux.fluxout + ">");
                while (fluxAvailable(data.cdeFlux.fluxin)){
                    // char buff[200];
                    // strcpy(buff,fic.read());
                    // fluxWrite(data.cdeFlux.fluxout, String(fic.read()));
                    fluxWrite(data.cdeFlux.fluxout, String(fluxRead(data.cdeFlux.fluxin)));
                    // Serial.write(fic.read());
                }
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