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
#include "gestionFlux.hpp"
#include "commandes.hpp"

void cpAide(void){
    fluxWriteln("fluxout", "Commande cp :");
    fluxWriteln("fluxout", "fonction : copie le contenu d'un fichier dans un autre fichier");
    fluxWriteln("fluxout", "usage    : cp <fichier source> <fichier destination>");
}

int cp(struct_cde_data data){
    // decomposeCommande(commande, ' ');
    int returnValue=NO_ERREUR;
    if (data.commande.equals("aide")){
        cpAide();
        return returnValue;
    } 
    if (isSdAvailable()){
        String fichierSource, fichierDest;
        File ficSource, ficDest;
        // fichierSource = getPath(cdeTbl[1]);
        // fichierDest = getPath(cdeTbl[2]);
        fichierSource = cdeTbl[1];
        fichierDest = cdeTbl[2];
        // Serial.println("filename = " + filename);
        if (fichierSource.length() > 0){
            ficSource = sdOpenRead(fichierSource);
            if (!ficSource){
                fluxWriteln("fluxerr", "fichier " + fichierSource + " non trouvé");
                returnValue=ERREUR_FILE_NOT_FOUND;
            } else {
                if (fichierDest.length() > 0){
                    if (fileExist(fichierDest)){
                        fluxWriteln("fluxerr", "le fichier destination (" + fichierDest + ") existe deja");
                        returnValue = ERREUR_FILE_EXIST;
                    } else {
                        ficDest = sdOpenWrite(fichierDest);
                        if(! ficDest){
                            fluxWriteln("fluxerr", "impossible de créer le fichier destination " + fichierDest);
                            returnValue=ERREUR_FILE_NOT_FOUND;
                            return returnValue;
                        }
                    }
                }
                if (ficSource.isDirectory()){
                    fluxWriteln("fluxerr", fichierSource + " est un repertoire");
                    returnValue=ERREUR_FILE_NOT_FOUND;
                    return returnValue;
                }
                while (ficSource.available()){
                    // Serial.write(ficSource.read());
                    ficDest.write(ficSource.read());
                }
                ficSource.close();
                ficDest.close();
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