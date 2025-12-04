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
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (data.commande.equals("aide")){
        catAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String filename;
        File fic;
        filename = cdeTbl[1];
        // Serial.println("filename = " + filename);
        if (filename.length() > 0){
            fic = sdOpenRead(filename);
            if (!fic){
                fluxWriteln("fluxerr", "fichier " + filename + " non trouvé");
                returnValue=ERREUR_FILE_NOT_FOUND;
            } else {
                if (fic.isDirectory()){
                    fluxWriteln("fluxerr", filename + " est un repertoire");
                    returnValue=ERREUR_FILE_NOT_FOUND;
                }
                while (fic.available()){
                    Serial.write(fic.read());
                }
                fic.close();
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